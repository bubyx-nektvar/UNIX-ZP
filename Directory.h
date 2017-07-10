#ifndef FS_DIRECTORY_H_
#define FS_DIRECTORY_H_
#define unique_solved
#ifdef _WIN32
#include <filesystem>
#else
#include <experimental/filesystem>
#endif
#include <vector>
#include<iostream>
#include <memory>
namespace myfs {
	class Directory;
}
#include "IInterface.h"
#include "File.h"
#include "PathContext.h"
#include "VersionChange.h"
namespace fs = std::experimental::filesystem;
namespace myfs {
	class Directory :public IInterface 
	{
	public:
		Directory(fs::path originalPath)
			:dir_name(originalPath.filename().string())
		{

		}
		Directory(const Directory&) = delete;
		Directory & operator=(const Directory&) = delete;
		Directory(Directory&& other) {
			dir_name = other.dir_name;
			for (auto x = other.direcotries.begin(); x != other.direcotries.end(); ++x) {
				direcotries.push_back(std::move(*x));
			}
			//direcotries = other.direcotries;
			for (auto x = other.files.begin(); x != other.files.end(); ++x) {
				files.push_back(std::move(*x));
			}
		}
		Directory & operator=(Directory&& other) {
			return std::move(other);
		}

		Directory(fs::path toRoot, fs::path fromRoot,std::string name);

		//targetDirs - koreny cilovych slozek
		//pathToCurrentDir - cesta do slozky v niz je slozka korespondujici teto instanci
		//rootPath - cesta ke koreni struktury
		virtual void Check(PathContext & paths)override;
		virtual void WriteHash(std::ostream & output, fs::path rootPath)override;
		void CreateVersion(VersionChange & ver, PathContext &paths);
		virtual void Init(fs::path systemPath, fs::path pathFromRoot, std::vector<fs::path>* targets)override;
		void SetHash(std::unordered_map<std::string, Hash> hashes,fs::path fromRoot);
		virtual void Load(fs::path originalRoot, std::vector<fs::path>& targets, fs::path fromRoot, Version v)override;
		virtual void AddToTargetClearly(fs::path toTarget, fs::path fromRoot)override;
		virtual void Remove(std::vector<fs::path>& targets, fs::path fromRoot)override;
		virtual void RewriteActualState(const PathContext & paths)override;
		void CheckExistance(PathContext& p);
	protected:
		std::vector<Directory> direcotries;
#ifdef unique_solved
		std::vector<std::unique_ptr<File>> files;
#else
		std::vector<File*> files;
#endif
		std::string dir_name;
	};
}
#endif
