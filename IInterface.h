#ifndef I_INTERFACE_H_
#define I_INTERFACE_H_
#include <vector>
#ifdef _WIN32
#include <filesystem>
#else
#include <experimental/filesystem>
#endif
#include <iostream>
#include <unordered_map>
namespace myfs{
	class IInterface;
}
#include "PathContext.h"
#include "base.h"
#include "VersionChange.h"

namespace fs = std::experimental::filesystem;
namespace myfs {
	class IInterface {
	public:
		virtual void Check(PathContext & paths) = 0;
		virtual void WriteHash(std::ostream & output, fs::path rootPath) = 0;
		virtual void CreateVersion(VersionChange & ver, PathContext &paths)=0;
		virtual void Init(fs::path systemPath, fs::path pathFromRoot, std::vector<fs::path>* targets)=0;
		virtual void SetHash(std::unordered_map<std::string, Hash> hashes, fs::path fromRoot)=0;
		virtual void Load(fs::path originalRoot, std::vector<fs::path>& targets, fs::path fromRoot, Version v)=0;
		virtual void AddToTargetClearly(fs::path toTarget, fs::path fromRoot)=0;
		virtual void Remove(std::vector<fs::path>& targets, fs::path fromRoot)=0;
		virtual void RewriteActualState(const PathContext & paths)=0;
	};
}
#endif
