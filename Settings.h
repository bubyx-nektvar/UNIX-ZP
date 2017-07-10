#ifndef SETTINGS_H_
#define SETTINGS_H_
#include <unordered_set>
#include <chrono>
#include <thread>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <mutex>
#ifdef _WIN32
#include <filesystem>
#else
#include <experimental/filesystem>
#endif
#include <istream>
#include <memory>
class Settings;
#include "base.h"
#include "Root.h"
namespace fs = std::experimental::filesystem;
class Settings
{
public:
	//settingFileStream - je stream do souboru na adrese file
	//file - cesta k config souboru
	Settings(std::istream &settingFileStream,std::string file);
	//tato metoda musi byt zavolana po vytvoreni setting instance
	void Read_Files_Setting(std::istream & settingFileStream);
	void WaitInterval();
	void AddEnding(std::string ending);
	bool IsTextfile(std::string fileName);
	bool IsTextfile(fs::path file);
	void SetInterval(int interval);
	void CreateNewVersion();
	void CreateNewVersion(unsigned long fromVersion);
	unsigned long GetActualVersion();

	void SetAndLoadActualVersion(unsigned long version);
	void Save();
	//prida soubor/slozku mezi kontrolovane
	void AddChecked(fs::path p);
	//prida novou cilovou slozku
	void AddTarget(fs::path p);
	//odebere soubor z kontrolovanych
	//return true-pokud uspesne odebran false-neni v systemu
	bool RemoveChecked(fs::path toRm);
	//odebere soubor z cilu
	//return true-pokud uspesne odebran false-neni v systemu
	bool RemoveTarget(fs::path toRm);
	//koren kontrolovanych souboru
	std::unique_ptr<myfs::Root> root;
	//nacte data z log filu
	void load_data();
	void ProcessCommandLoadVersion();
	void CommandLoadVersion(unsigned long v);
	bool MakeLoop();
	void Exit();
private:
	//should lock when any change of Settings from public
	std::mutex structure_lock;
	//cesta k config souboriu z ktereho se nacita pri spusteni aplikace
	std::string original_setting_file_path;
	int interval;
	std::unordered_set<std::string> text_file_endings;
	unsigned long last_version;
	unsigned long actual_version;
	std::mutex command_version_lock;
	unsigned long command_version;

	bool should_end = false;
	std::mutex should_end_lock;

	void set_text_files(std::string fileEndings);
	std::string get_endings();
	void set_hashes();
	void save_to_stream(std::ofstream & stream);
};
#endif
