#include "Settings.h"
#include "FileStructure.h"
Settings::Settings(std::istream & settingFileStream,std::string file)
	:last_version(0),actual_version(0),interval(1),original_setting_file_path(file)
{
	text_file_endings.insert(".txt");
	cout << ">>Reading settings";
	root = std::make_unique<myfs::Root>();
	std::string line;
	while (std::getline(settingFileStream, line)) {
		auto semicolon1 = line.find(';');
		std::string settSpec = line.substr(0, semicolon1);
		if (settSpec == "interval") {
			interval = fromString<int>(line.substr(semicolon1 + 1));
		}
		else if (settSpec == "text") {
			set_text_files(line.substr(semicolon1 + 1));
		}
		else if (settSpec == "last-version") {
			last_version = fromString<unsigned long>(line.substr(semicolon1 + 1));
		}
		else if (settSpec == "actual-version") {
			actual_version = fromString<unsigned long>(line.substr(semicolon1 + 1));
		}
	}
	command_version = actual_version;
	cout << "...done" << endl;
}

void Settings::Read_Files_Setting(std::istream & settingFileStream) {

	cout << ">>Reading files settings";
	std::string line;
	while (std::getline(settingFileStream, line)) {
		auto semicolon1 = line.find(';');
		std::string settSpec = line.substr(0, semicolon1);
		if (settSpec == "add-file") {
			fs::path path(line.substr(semicolon1 + 1));
			std::unique_ptr<myfs::File> f_p;
			if (IsTextfile(path)) {
				f_p = std::make_unique<FileStructure<Text>>(path.filename().string());
			}
			else {
				f_p = std::make_unique<FileStructure<Binary>>(path.filename().string());
			}
			root->files.push_back(myfs::RootFile(std::move(f_p), path.parent_path()));
		}
		else if (settSpec == "add-dir") {
			fs::path path(line.substr(semicolon1 + 1));
			auto rd = myfs::RootDirectory(path.parent_path(), path.filename().string());
			root->dirs.push_back(std::move(rd));
		}
		else if (settSpec == "add-target") {
			root->target_dirs.push_back(line.substr(semicolon1 + 1));
		}
	}
	cout << "...done" << endl;
	set_hashes();
	load_data();
}
void Settings::load_data() {
	cout << ">>Loading files" << endl;
	for (auto it = root->files.begin(); it != root->files.end(); ++it) {
		it->GetFile()->Load(it->GetOriginPath(),root->target_dirs, fs::path(), actual_version);
	}
	for (auto it = root->dirs.begin(); it != root->dirs.end(); ++it) {
		it->Load(it->originPath,root->target_dirs,it->GetDirPath().filename(),actual_version);
	}
	cout << "...loading done" << endl;
}
void Settings::ProcessCommandLoadVersion()
{
	command_version_lock.lock();
	if (command_version != actual_version) {
		SetAndLoadActualVersion(command_version);
	}
	command_version_lock.unlock();
}
void Settings::CommandLoadVersion(unsigned long v)
{
	command_version_lock.lock();
	command_version = v;
	command_version_lock.unlock();
}
bool Settings::MakeLoop()
{
	should_end_lock.lock();
	bool res = should_end;
	should_end_lock.unlock();
	return !res;
}
void Settings::Exit()
{
	should_end_lock.lock();
	should_end = true;
	should_end_lock.unlock();
}


void Settings::save_to_stream(std::ofstream & stream)
{
	stream << "interval;" << interval << std::endl
		<< "text;" << get_endings() << std::endl
		<< "actual-version;" << actual_version << std::endl
		<< "last-version;" << last_version << std::endl;
	for (auto it = root->dirs.begin(); it != root->dirs.end(); ++it) {
		stream << "add-dir;" << it->GetDirPath() << std::endl;
	}
	for (auto it = root->files.begin(); it != root->files.end(); ++it) {
		stream << "add-file;" << it->GetFilePath() << std::endl;
	}
	for (auto it = root->target_dirs.begin(); it != root->target_dirs.end(); ++it) {
		stream << "add-target;" << it->string() << std::endl;
	}
}

void Settings::WaitInterval()
{
#ifdef DEBUG
	std::this_thread::sleep_for(std::chrono::seconds(10));
#else
	std::this_thread::sleep_for(std::chrono::minutes(interval));

#endif // DEBUG
}

void Settings::AddEnding(std::string ending)
{
	structure_lock.lock();
	text_file_endings.emplace(ending);
	structure_lock.unlock();
}

bool Settings::IsTextfile(std::string ending)
{
	structure_lock.lock();
	bool res=text_file_endings.count(ending) > 0;
	structure_lock.unlock();
	return res;
}

bool Settings::IsTextfile(fs::path file)
{
	return IsTextfile(file.extension().string());
}

void Settings::Save()
{
	for (auto it = root->target_dirs.begin(); it != root->target_dirs.end(); ++it)
	{
		fs::path f= (*it) / fs::path(".bbdata.conf");
		std::ofstream file(f.string());
		save_to_stream(file);
		file.close();
	}
	std::ofstream file(original_setting_file_path);
	save_to_stream(file);
	file.close();
}
void Settings::set_text_files(std::string fileEndings) 
{
	std::string::iterator part_start=fileEndings.begin(),part_end = fileEndings.begin();
	while (part_end != fileEndings.end())
	{
		part_end = find(part_start, fileEndings.end(), ' ');
		text_file_endings.insert(std::string(part_start, part_end));
		if (part_end != fileEndings.end()) ++part_end;
		part_start = part_end;
	}

}
std::string Settings::get_endings() {
	std::stringstream out;
	for (auto it = text_file_endings.begin(); it != text_file_endings.end(); ++it) 
	{
		out << (*it) << ' ';
	}
	return out.str();
}

void Settings::AddChecked(fs::path p) {
	root->AddChecked(p);
}
void Settings::AddTarget(fs::path p) {
	root->AddTarget(p);
}
bool Settings::RemoveChecked(fs::path toRm) {
	return root->RemoveChecked(toRm);
}
bool Settings::RemoveTarget(fs::path toRm) {
	return root->RemoveTarget(toRm);
}

void Settings::SetInterval(int interval) {
	structure_lock.lock();
	this->interval = interval;
	structure_lock.unlock();
}
void Settings::CreateNewVersion() {

	command_version_lock.lock();
	root->CreateVersion(VersionChange( actual_version, ++last_version,actual_version));
	actual_version = last_version;
	command_version = actual_version;
	command_version_lock.unlock();
}
void Settings::CreateNewVersion(unsigned long fromVersion)
{
	command_version_lock.lock();
	root->CreateVersion(VersionChange( actual_version, ++last_version, fromVersion));
	actual_version = last_version;
	command_version = actual_version;
	command_version_lock.unlock();
}
unsigned long Settings::GetActualVersion()
{
	return actual_version;
}
void Settings::SetAndLoadActualVersion(unsigned long version) {
	structure_lock.lock();
	root->LoadVersion(version);
	root->RewriteActualState();
	actual_version = version;
	command_version = actual_version;
	if (actual_version != last_version) {
		root->CreateVersion(VersionChange(actual_version, ++last_version, actual_version));
		//CreateNewVersion(actual_version);
	}
	structure_lock.unlock();
}