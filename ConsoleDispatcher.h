#ifndef CONSOLE_DISPATCHER_H_
#define CONSOLE_DISPATCHER_H_
#ifdef _WIN32
#include <filesystem>
#else
#include <experimental/filesystem>
#endif
class ConsoleDispatcher;
#include "Settings.h"
namespace fs = std::experimental::filesystem;
class ConsoleDispatcher
{
public:
	ConsoleDispatcher(std::shared_ptr<Settings> setting) :setting(setting)
	{

	}
	//zpracuje prikaz z konzole
	//return - false pokud prikaz neni platny
	//line - prikaz z konzole
	void DispatchLine(std::string line);
private:
	std::shared_ptr<Settings> setting;
	fs::path ParsePath(std::string path);
	
};

#endif