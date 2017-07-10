#include "Directory.h"
#include "FileStructure.h"
myfs::Directory::Directory(path toRoot,path fromRoot,std::string name)
	:dir_name(name)
{
	{

		for (fs::directory_iterator it(toRoot/fromRoot/path(dir_name)); it != fs::directory_iterator(); ++it) {
			if (fs::is_directory(*it)) {
				direcotries.push_back(myfs::Directory(toRoot,fromRoot/path(dir_name),it->path().filename().string()));
			}
			else {
				std::unique_ptr<File> f;
				if (setting->IsTextfile(it->path())) {
					f = std::make_unique< FileStructure<Text>>(it->path().filename().string());
				}
				else {
					f = std::make_unique< FileStructure<Binary>>(it->path().filename().string());
				}
				files.push_back(std::move( f));
			}
		}
	}
}
void myfs::Directory::Check(PathContext & paths) {
	
	CheckExistance(paths);

	path path = paths.pathFromRoot / fs::path(dir_name);
	for (auto it = direcotries.begin(); it != direcotries.end(); ++it) {
		it->Check(PathContext(paths, path));
	}
	for (auto it2 = files.begin(); it2 != files.end(); ++it2) {
		it2->get()->Check(PathContext(paths, path));
	}
}

void myfs::Directory::WriteHash(std::ostream &output, fs::path rootPath)
{
	for (auto it2 = files.begin(); it2 != files.end(); ++it2) {
		it2->get()->WriteHash(output, (rootPath/fs::path(dir_name)));
	}
	for (auto it2 = direcotries.begin(); it2 != direcotries.end(); ++it2) {
		it2->WriteHash(output,rootPath/ fs::path(dir_name));
	}
}

void myfs::Directory::CreateVersion(VersionChange & ver, PathContext & paths)
{
	PathContext p(paths, paths.pathFromRoot / fs::path(dir_name));
	for (auto it = direcotries.begin(); it != direcotries.end(); ++it) {
		it->CreateVersion(ver,p);
	}
	for (auto it = files.begin(); it != files.end(); ++it) {
#ifdef unique_solved
		it->get()->CreateVersion(ver, p);
#else
		(*it)->CreateVersion(ver, p);
#endif
	}
}

void myfs::Directory::Init(fs::path systemPath , fs::path pathFromRoot, vector<fs::path>* targets)
{
	for (auto it = targets->begin(); it != targets->end(); ++it) {
		fs::create_directory((*it) / pathFromRoot / dir_name);
		fs::create_directory((*it) / fs::path(".bbdata") / pathFromRoot / dir_name);
	}
	for (fs::directory_iterator it(systemPath); it != fs::directory_iterator(); ++it) {
		if (fs::is_directory(it->path())) {//pridat pod adresar
			Directory d(it->path());
			d.Init(it->path(),pathFromRoot/fs::path(dir_name),targets);
			direcotries.push_back(std::move(d));
		}
		else if (fs::is_regular_file(it->path())) {//pridate pod soubor
#ifdef unique_solved
			unique_ptr<File> f;
#else
			File* f;
#endif
			if (setting->IsTextfile(it->path())) {

#ifdef unique_solved
				f = std::make_unique<FileStructure<Text>>(it->path().filename().string());
#else
				f = new FileStructure<Text>(it->path().filename().string());
#endif
			}
			else {
#ifdef unique_solved
				f = std::make_unique< FileStructure<Binary>>(it->path().filename().string());
#else
				f = new FileStructure<Binary>(it->path().filename().string());
#endif
			}
			f->Init(it->path(),pathFromRoot/fs::path(dir_name),targets);
#ifdef unique_solved
			files.push_back(move(f));
#else
			files.push_back(f);
#endif

		}
	}
	
}

void myfs::Directory::SetHash(std::unordered_map<std::string, Hash> hashes, fs::path fromRoot)
{
	for (auto it = direcotries.begin(); it != direcotries.end(); ++it) {
		it->SetHash(hashes, fromRoot / fs::path(dir_name));
	}
	for (auto it = files.begin(); it != files.end(); ++it) {
		(*it)->SetHash(hashes, fromRoot / fs::path(dir_name));
	}

}

void myfs::Directory::Load(fs::path originalRoot, std::vector<fs::path>& targets, fs::path fromRoot, Version v)
{
	fs::path n_fromRoot = fromRoot / fs::path(dir_name);
	for (auto it = direcotries.begin(); it != direcotries.end(); ++it) {
		it->Load(originalRoot, targets,n_fromRoot, v);
	}
	for (auto it = files.begin(); it != files.end(); ++it) {
		(*it)->Load(originalRoot, targets, n_fromRoot, v);
	}
}

void myfs::Directory::AddToTargetClearly(fs::path toTarget, fs::path fromRoot)
{
	fs::path actFromRoot = fromRoot / fs::path(dir_name);
	fs::path realDir = toTarget / actFromRoot;
		
	if (fs::exists(realDir)){
		if (!fs::is_directory(realDir)) {
			fs::remove(realDir);
			fs::create_directory(realDir);
		}
	}
	else {
		fs::create_directory(realDir);
	}
	fs::path realTargetDir = toTarget / fs::path(".bbdata") / actFromRoot;
	if (fs::exists(realTargetDir)) {
		if (!fs::is_directory(realTargetDir)) {
			fs::remove(realTargetDir);
			fs::create_directory(realTargetDir);
		}
	}
	else {
		fs::create_directory(realTargetDir);
	}
	for (auto it = direcotries.begin(); it != direcotries.end();++it)
	{
		it->AddToTargetClearly(toTarget,actFromRoot);
	}
	for (auto it = files.begin(); it != files.end(); ++it) {
		(*it)->AddToTargetClearly(toTarget,actFromRoot);
	}
}

void myfs::Directory::Remove(std::vector<fs::path>& targets, fs::path fromRoot)
{
	for (auto it = files.begin(); it != files.end(); ++it) {
		(*it)->Remove(targets,fromRoot/dir_name);
	}
	for (auto it = direcotries.begin(); it != direcotries.end(); ++it) {
		it->Remove(targets, fromRoot / dir_name);
	}
}

void myfs::Directory::RewriteActualState(const PathContext & paths)
{
	PathContext p(paths,paths.pathFromRoot/dir_name);
	for (auto x = direcotries.begin(); x != direcotries.end();++x) {
		x->RewriteActualState(p);
	}for (auto x = files.begin(); x != files.end();++x) {
		(*x)->RewriteActualState(p);
	}
}

void myfs::Directory::CheckExistance(PathContext & p)
{
	fs::path fR = p.pathFromRoot / dir_name;

	fs::path sysPath = p.pathToRoot / fR;
	if (!fs::exists(sysPath) ){
		fs::create_directory(sysPath);
	}
	for (auto x = p.targetDirs->begin(); x != p.targetDirs->end(); ++x) {
		sysPath = (*x) / fR;
		if (!fs::exists(sysPath)) {
			fs::create_directory(sysPath);
		}
		sysPath = (*x) / ".bbdata" / fR;
		if (!fs::exists(sysPath)) {
			fs::create_directory(sysPath);
		}
	}
	
}

