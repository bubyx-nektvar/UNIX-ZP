#ifndef FS_ROOT_H_
#define FS_ROOT_H_
#include <vector>
#ifdef _WIN32
#include <filesystem>
#else
#include <experimental/filesystem>
#endif
#include <algorithm>
#include <queue>
#include <mutex>
#include <tuple>
#include<unordered_map>
namespace myfs {
	class Root;
}
#include "VersionChange.h"
#include "RootFile.h"
#include "RootDirectory.h"
namespace fs = std::experimental::filesystem;
namespace myfs {
	class Root {

	public:
		void Check();
		//prida do fronty k pridani soubor/adresar
		//nezablokuje vlakno, ale soubor je pridan az pred dalsi kontrolou
		void AddChecked(fs::path path);
		void AddTarget(fs::path d_path);
		//zjisti zda je mezi cili cesta param(p) a odstrani ji z cilu
		//return true pokud mezi cili je
		bool RemoveTarget(fs::path p);
		bool RemoveChecked(fs::path p);

		//pridane zdrojove soubory
		std::vector<RootFile> files;
		//pridane zdrojove adresare
		std::vector<RootDirectory> dirs;
		//cilove adresare
		std::vector<fs::path> target_dirs;
		//from_version - zmena z verze
		//new_version - nova verze
		//continue_version - verze na kterou tato verze navazuje
		void CreateVersion(VersionChange & ver);
		//nastavi u vsech kontrolovanych souboru, hash log filu
		void SetHashes(std::unordered_map<std::string, Hash> hashes);
		void LoadVersion(Version v);
		void RewriteActualState();



	private:
		//soubory jsou volany z Check methody, takze nepocitaji s tim ze by soubezne s nimi probihala kontrola souboru
		//x-begin 
		void add_checked_root_file(fs::path f_path);
		void add_checked_root_dir(fs::path d_path);
		void add_target(fs::path t);
		void remove_checked_file(fs::path f_path);
		void remove_checked_dir(fs::path d_path);
		void remove_target(fs::path t);
		//x-end

		fs::path get_hash_file_path(fs::path target_dir); 
		void check_bbdata_folders_exists();

		void process_targets();
		void process_checked();
		
		//zamika se pri zmenach files,dirs
		std::mutex checked_lock;
		//zamika se pri zmenach target_dirs
		std::mutex target_lock;
		//fronty pro pridani bool =true-pridat false-odebrat
		std::queue<std::tuple<fs::path, bool>> checked_queue;
		std::mutex checked_queue_lock;
		std::queue<std::tuple<fs::path, bool>> target_queue;
		std::mutex target_queue_lock;
	};

}
#endif
