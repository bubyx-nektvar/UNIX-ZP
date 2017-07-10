#include "Root.h"
#include "FileStream.h"
#include "FileStructure.h"
#include "ChunkType.h"
#include "path.h"
void myfs::Root::Check() {
	process_checked();
	process_targets();
	setting->Save();
	check_bbdata_folders_exists();
	for (auto it = files.begin(); it != files.end(); ++it) {
		it->Check(&target_dirs);
	}
	for (auto it = dirs.begin(); it != dirs.end(); ++it) {
		it->Check(PathContext( &target_dirs, fs::path(it->originPath), fs::path()));
	}
	setting->ProcessCommandLoadVersion();
}
void myfs::Root::AddChecked(fs::path path) {
	checked_queue_lock.lock();
	checked_queue.push(tuple<path, bool>(path, true));
	checked_queue_lock.unlock();
}
void myfs::Root::AddTarget(path d_path) {
	target_queue_lock.lock();
	target_queue.push(tuple<path, bool>(d_path, true));
	target_queue_lock.unlock();
}
bool myfs::Root::RemoveTarget(path p) {
	auto r = find(target_dirs.begin(), target_dirs.end(), p) != target_dirs.end();

	target_queue_lock.lock();
	target_queue.push(tuple<path, bool>(p, false));
	target_queue_lock.unlock();

	return r;
}
bool myfs::Root::RemoveChecked(path p) {
	checked_lock.lock();
	auto r = find_if(files.begin(), files.end(), RootFile::SelectPath(p)) != files.end();
	auto r2 = find_if(dirs.begin(), dirs.end(), RootDirectory::SelectPath(p)) != dirs.end();
	checked_lock.unlock();

	checked_queue_lock.lock();
	checked_queue.push(tuple<path, bool>(p, false));
	checked_queue_lock.unlock();

	return r || r2;
}

void myfs::Root::CreateVersion(VersionChange & ver)
{
	for (auto it = dirs.begin(); it != dirs.end(); ++it) {
		it->CreateVersion(ver,PathContext(&target_dirs,it->originPath,path()));
	}
	for (auto it = files.begin(); it != files.end(); ++it) {
		it->CreateVersion(ver,&target_dirs);
	}
}

void myfs::Root::SetHashes(std::unordered_map<std::string, Hash> hashes)
{
	for (auto it = dirs.begin(); it != dirs.end();++it)
	{
		it->SetHash(hashes,path());
	}
	for (auto it = files.begin(); it != files.end(); ++it) {
		it->SetHash(hashes);
	}
}

void myfs::Root::LoadVersion(Version v)
{
	for (auto it = dirs.begin(); it != dirs.end(); ++it) {
		it->Directory::Load(it->originPath,target_dirs, path(), v);
	}for (auto it = files.begin(); it != files.end(); ++it) {
		it->GetFile()->Load(it->GetOriginPath(),target_dirs,path(),v);
	}
}

void myfs::Root::RewriteActualState()
{
	for (auto x = dirs.begin(); x != dirs.end(); ++x) {
		x->RewriteActualState(&target_dirs);
	}for (auto x = files.begin(); x != files.end(); ++x) {
		x->RewriteActualState(&target_dirs);
	}
}

void myfs::Root::add_checked_root_file(path f_path)
{
	unique_ptr<File> f;
	if (setting->IsTextfile(f_path)) {
		//f = make_unique<File>(new FileStructure<Text>(f_path.filename().string()));
		f = std::make_unique<FileStructure<Text>>(f_path.filename().string());
	}
	else {
		//f = make_unique<File>(new FileStructure<Binary>(f_path.filename().string()));
		f = std::make_unique<FileStructure<Binary>>(f_path.filename().string());
	}
	f->Init(f_path,path(), &target_dirs);
	checked_lock.lock();
	files.push_back(RootFile(move(f), f_path.parent_path()));
	checked_lock.unlock();
}

void myfs::Root::add_checked_root_dir(path d_path)
{
	checked_lock.lock();
	RootDirectory dir(d_path);
	dir.Init(d_path,path(),&target_dirs);
	dirs.push_back(std::move(dir));
	checked_lock.unlock();
}

void myfs::Root::add_target(path t)
{
	if (target_dirs.begin() != target_dirs.end()) {
		
		fs::copy((*target_dirs.begin()), t,fs::copy_options::recursive);

	}
	else {
		fs::create_directory(t / path(".bbdata"));
		for (auto it = dirs.begin(); it != dirs.end(); ++it) {
			it->AddToTargetClearly(t,path());
		}
		for (auto it = files.begin(); it != files.end(); ++it) {
			it->GetFile()->AddToTargetClearly(t,path());
		}
	}
	target_lock.lock();
	target_dirs.push_back(t);
	target_lock.unlock();
	std::cout << ">>Target added" << t << endl;
}

void myfs::Root::remove_checked_file(path f_path)
{
	auto f=std::find_if(files.begin(), files.end(), RootFile::SelectPath(f_path));
	if (f != files.end()) {
		for (auto it = target_dirs.begin(); it != target_dirs.end(); ++it) {
			path toRm = (*it) / f->GetFilePath().filename();
			fs::remove(toRm);
		}
		f->GetFile()->Remove(target_dirs,path());
		checked_lock.lock();
		files.erase(f);
		checked_lock.unlock();
	}
}

void myfs::Root::remove_checked_dir(path d_path)
{
	auto f = std::find_if(dirs.begin(), dirs.end(), RootDirectory::SelectPath(d_path));
	if (f != dirs.end()) {
		for (auto it = target_dirs.begin(); it != target_dirs.end(); ++it) {
			path toRm = (*it) / f->originPath.filename();
			fs::remove_all(toRm);
		}
		checked_lock.lock();
		f->Remove(target_dirs,path());
		dirs.erase(f);
		checked_lock.unlock();
	}
}

void myfs::Root::remove_target(path t_path)
{
	auto t = find(target_dirs.begin(), target_dirs.end(), t_path);
	if (t != target_dirs.end()) {
		target_lock.lock();
		target_dirs.erase(t);
		target_lock.unlock();
	}
}

path myfs::Root::get_hash_file_path(path target_dir)
{
	return target_dir/path(".bbdata.hash");
}

void myfs::Root::check_bbdata_folders_exists()
{
	for (auto x = target_dirs.begin(); x != target_dirs.end(); ++x) {
		if (!fs::exists((*x) / BBDataFolderName)) {
			fs::create_directory(*x / BBDataFolderName);
		}
	}
}

void myfs::Root::process_targets()
{
	target_queue_lock.lock();
	while (!target_queue.empty()) {
		auto x = target_queue.front();
		target_queue.pop();
		target_queue_lock.unlock();
		
		path p = std::get<0>(x);
		bool add = std::get<1>(x);
		if (add)add_target(p);
		else remove_target(p);


		target_queue_lock.lock();
	}
	target_queue_lock.unlock();
}

void myfs::Root::process_checked()
{
	checked_queue_lock.lock();
	while (!checked_queue.empty()) {
		auto x = checked_queue.front();
		checked_queue.pop();
		checked_queue_lock.unlock();
		//zpracovani path
		path p=std::get<0>(x);
		bool add = std::get<1>(x);
		if (fs::is_directory(p)) {
			if(add)add_checked_root_dir(p);
			else remove_checked_dir(p);
		}
		else {
			if(add)add_checked_root_file(p);
			else remove_checked_file(p);
		}

		checked_queue_lock.lock();
	}
	checked_queue_lock.unlock();
}
