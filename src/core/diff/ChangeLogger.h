#ifndef CHANGE_LOGGER_
#define CHANGE_LOGGER_
#include <vector>
#include <iostream>
#include "FileStream.h"
#include <algorithm>
#ifdef _WIN32
#include <filesystem>
#else
#include <experimental/filesystem>
#endif
template<typename T> class ChangeLogger;
#include "base.h"
#include "ILogger.h"
using namespace std;
namespace fs = std::experimental::filesystem;
//trida ktera propaguje zmenu (zpise do jednotlivych kopii souboru i do verzovacich souboru)
template<typename T>
class ChangeLogger: public ILogger
{
public:
	
	void Open(vector<path>* targets, path file) override{
		for (auto it = targets->begin(); it != targets->end(); ++it) {
 			log_files.push_back(ofstream((*it) / path(".bbdata") / file, ofstream::app | ofstream::out));
		}
	}
	void Open(vector<path>& targets) override{
		for (auto it = targets.begin(); it != targets.end(); ++it) {
			log_files.push_back(ofstream(*it, ios::app| ios::out));
		}
	}
	void Close() override{
		for_each(log_files.begin(), log_files.end(), [](ofstream &o) {o.close(); });
		log_files.clear();
	}
	void LogAdd(T chunk, Index i) {
		for_each(log_files.begin(),log_files.end(),
			[chunk,i](ostream &s){
			s << "add;" << i << ";" << chunk.ToString() << endl;
			}
		);
	}
	void LogRemoveChunk(Index i) {
		for_each(log_files.begin(), log_files.end(),
		[i](ostream &s) {
			s << "remove;" << i  << endl;
		});
	}
	void LogVersion(unsigned long prevVersion, unsigned long newversion) override{
		for_each(log_files.begin(), log_files.end(),
		[prevVersion,newversion](ostream &s) {
			s << "version;" << prevVersion << ";" << newversion << endl;
		});
	}
	void LogDelete() override{
		for_each(log_files.begin(), log_files.end(),
		[](ostream &s) {
			s << "deleted" << endl;
		});
	}
	void LogCreate() override{
		for_each(log_files.begin(), log_files.end(),
		[](ostream &s){
			s << "created" << endl;
		});
	}
private :
	vector<ofstream> log_files;
};
#endif

