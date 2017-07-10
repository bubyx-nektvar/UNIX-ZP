#ifndef FS_ROOT_DIRECTORY_H_
#define FS_ROOT_DIRECTORY_H_
#ifdef _WIN32
#include <filesystem>
#else
#include <experimental/filesystem>
#endif
namespace myfs {
	class RootDirectory;
}
#include "Directory.h"
namespace myfs 
{
	class RootDirectory :public Directory {
	public:

		class SelectPath {
		public:
			SelectPath(fs::path p) :pp(p) {}
			bool operator() (RootDirectory& f) {
				if (pp == (f.originPath/fs::path(f.dir_name))) return true;
				else return false;
			}
		private:
			fs::path pp;
		};
		//originPath - systemova cesta (obsahuje i nazev slozky)
	public:
		RootDirectory(fs::path toRoot, std::string name);
		
		RootDirectory(fs::path originPath ) 
			: Directory(originPath),originPath(originPath.parent_path())
		{
		}
		RootDirectory(const RootDirectory&) = delete;
		RootDirectory& operator=(const RootDirectory&) = delete;
		RootDirectory(RootDirectory&& dir) :Directory(std::move(dir)) {
			originPath = dir.originPath;
		}
		RootDirectory& operator=(RootDirectory&& other) {
			return std::move(other);
		}
		//systemova cesta k adresari (bez jmena adresare)
		fs::path originPath;
		virtual void Check(PathContext & paths) override;

		//vrarti originalni cestu k adresari se samotnym adresarem
		fs::path GetDirPath();
		void RewriteActualState(std::vector<fs::path>* target_dirs);
	};
}
#endif
