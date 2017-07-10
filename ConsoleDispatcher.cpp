#include "ConsoleDispatcher.h"
#include "Messages.h"
using namespace std;
void ConsoleDispatcher::DispatchLine(string line)
{
	auto comma1 = line.find('-');
	auto brace1 = line.find('(',comma1);
	string prefix = line.substr(0, comma1);
	string main = line.substr(comma1+1, brace1-(comma1+1));
	string parametr = line.substr(brace1+1, line.find(')')-(brace1+1));
	if (prefix == "checked") //“checked-add(path)” or “checked - remove(path)”
	{
		auto p = ParsePath(parametr);
		if (main == "add") {

			if (fs::is_directory(p) || fs::is_regular_file(p)) {
				setting->AddChecked(p);
			}
			else {
				cout << WRONG_FILE << endl;
			}
		}
		else if (main == "remove") {

			if (!setting->RemoveChecked(p)) {
				cout << PATH_NOT_TRACKED << endl;
			}
			else {
				cout << PATH_CHECKED_REMOVED << endl;
			}
		}
	}
	else if (prefix == "target") //“target-add(path)” or “target-remove(path)”
	{
		auto p = ParsePath(parametr);
		if (main == "add") {
			if (fs::is_directory(p)) {
				if (fs::is_empty(p)) {
					setting->AddTarget(p);
				}
				else {
					cout << DIR_MUST_EMPTY << endl;
				}
			}
			else {
				cout << NOT_DIR << endl;
			}
		}
		else if (main == "remove") {
			if (!setting->RemoveTarget(p)) {
				cout << PATH_NOT_TRACKED << endl;
			}
			else {
				cout << PATH_TARGET_REMOVED << endl;
			}
		}
	}
	else if (prefix == "create")//“create-version”
	{
		if (main == "version") {
			setting->CreateNewVersion();
		}

	}
	else if(prefix =="load")//“load-version(version)”
	{
		if (main == "version") {
			istringstream ss(parametr);
			unsigned long i;
			ss >> i;	
			setting->CommandLoadVersion(i);
		}
	}
	else if (prefix == "view")//“view-changes(path)”
	{
		if (main == "changes") {
			//TODO
		}
	}
	else if (prefix == "interval") {
		if (main == "set") {
			istringstream ss(parametr);
			int i;
			ss >> i;
			setting->SetInterval(i);
		}
	}
	else if (prefix == "exit") {
		setting->Exit();
	}
	else {
		if (line != "") {
			cout << UNKNOWN_COMMAND << endl;
		}
	}
}

path ConsoleDispatcher::ParsePath(std::string path)
{
	return path;
}
