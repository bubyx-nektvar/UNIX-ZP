#ifndef FS_ROOT_FILE_H_
#define FS_ROOT_FILE_H_
#ifdef _WIN32
#include <filesystem>
#else
#include <experimental/filesystem>
#endif
#include <memory>
#include<vector>
#include <unordered_map>
namespace myfs {
	class RootFile;
}
#include "File.h"
namespace fs = std::experimental::filesystem;
namespace myfs {
	class RootFile
	{
	public:
		RootFile(std::unique_ptr<File> f,fs::path orig):file(std::move(f)),originPath(orig){
		}
		void Check(std::vector<fs::path>* targetDirs);
		fs::path GetFilePath();
		void WriteHash(std::ostream & output, fs::path rootPath);
		void CreateVersion(VersionChange & ver, std::vector<fs::path> * targets);
		void SetHash(std::unordered_map<std::string, Hash> hashes);
		File * GetFile() { return file.get(); }
		fs::path GetOriginPath() { return originPath; }
		void RewriteActualState(std::vector<fs::path>* target_dirs);
	private:
		std::unique_ptr<File> file;
		//cesta bez nazvu souboru
		fs::path originPath;
	public:


		class SelectPath {
		public:
			SelectPath(fs::path p) :pp(p) {}
			bool operator() (RootFile& f) {
				if (pp == f.GetFilePath()) return true;
				else return false;
			}
		private:
			fs::path pp;
		};
	};
}
#endif // !FS_ROOT_DIRECTORY_H_

