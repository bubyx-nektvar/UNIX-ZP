#ifndef FS_FILE_H_
#define FS_FILE_H_
#include <algorithm>
#ifdef _WIN32
#include <filesystem>
#else
#include <experimental/filesystem>
#endif
#include "FileStream.h"
#include <vector>
#include <memory>
#include <string>
#include <unordered_map>

namespace myfs {
	class File;
}
#include "ILogger.h"
#include "base.h"
#include "VersionChange.h"
using namespace std;
namespace myfs {
	class File
	{
	public:
		File(std::string name):file_name(name){}
		File(const File& that) = delete;
		File & operator=(const File&) = delete;
		//targetFolder - pouze seznam vsech cilovych slozek
		//pathToCurrentFolder - cesta v teto strukture k tomuto souboru, od zdrojove slozky
		//rootPath - cesta ke koreni struktury
		void Check(PathContext & paths);
		std::string GetName() { return file_name; }
		void WriteHash(std::ostream & output, path rootPath);
		//virtual void CreateVersion(VersionChange & ver, PathContext &paths) = 0;
		//nacte strukturu
		//vytvori log file s pridanim chunku
		//vytvori hash
		virtual void Init(path pathToOriginFile, path fromRoot,vector<path>* targets)= 0;
		//nascte strukturu z log fileu
		virtual void Load(path originalRoot, vector<path>& targets, path pathFromRoot,Version v) = 0;
		virtual void SetHash(std::unordered_map<std::string, Hash> hashes, path fromRoot);
		virtual void AddToTargetClearly(path toTarget, path fromRoot) ;
		virtual void RewriteActualState(const PathContext & paths) {
			Rewrite(path(), paths, true);
		}
		virtual std::unique_ptr<ILogger> GetLogger() = 0;
	protected:
		// zpracuje zmeny v souboru
		//rootPath - cesta ke koreni struktury
		//targetFolder - seznam vsech cilovych slozek
		//pathToCurrentFolder - cesta v teto strukture k tomuto souboru, od zdrojove slozky
		// return - true pokud se nejaky soubor upravoval
		//used_target - je target kde je nejaktualnesi verze souboru
		virtual bool check_files_change(PathContext & paths,path & used_path) = 0;
		std::string file_name;

		bool is_change(vector<BaseNumberType>* change_description);

		//prepise soubor ve vsechtargetech ( + originalni soubor) s vyjimkou used_pathToRoot
		//used_pathToRoot - cesta ke koreni z niz pochazi posledni zmena
		//rewriteAll - true pokud bez vyjimky
		void Rewrite(path& used_pathToRoot,const PathContext& paths, bool rewriteAll = false); 
		virtual void log_init(std::vector<path>* targets, const path & fromRoot) = 0;
		virtual void WriteChunks(path file) = 0;
	};
}
#endif

