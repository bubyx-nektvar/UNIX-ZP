#include "FilesStructure.h"
#include <queue>

#include "unix/io/FileSystem.h"
#include "unix/io/DirectoryInfo.h"
#include "unix/io/FileInfo.h"
#include "PathContext.h"

const std::string FilesStructure::SVNDirName = ".svn";


unix::DirectoryInfo FilesStructure::getSvnRootDir(path fullPath)
{
	auto dir = unix::FileInfo(fullPath).GetParentDirectory();
	do {
		auto svn = dir.GetChild(SVNDirName);
		if (svn.exists() && svn.isDirectory()) {
			break;
		}
		dir = dir.GetParentDirectory();
	} while (!dir.isRoot());
	return dir;
}

path FilesStructure::getSvnRelative(path svnRoot, path fullPath)
{
    return fullPath.removePrefix(svnRoot);
}

path FilesStructure::getSvnRelative(path svnFilePath, int * revision)
{
    auto i = svnFilePath.indexOfLastPart(SVNDirName);
	if (i == -1) return path();
    auto svnRelative = svnFilePath.subpath(i+1);
    *revision = std::stoi(svnFilePath.getEnding());
    return svnRelative;
}

FileInfo FilesStructure::createRevisionFile(path relativePath, int revision)
{
    auto pc = PathContext(relativePath,rootPath,SVNDirName,revision);
    auto fi = unix::FileInfo(pc.pathToPrevRevisionFile());
    fi.create();
}

FilesStructure::FilesStructure(std::string rootPath)
{
	this->rootPath = rootPath;
	auto fp = unix::FileSystem::PathConcat(rootPath, SVNDirName);
	std::queue<path> dirQueue;
	dirQueue.push(fp);
	while (dirQueue.size() > 0) {
		auto dir = std::make_unique<unix::DirectoryInfo>(dirQueue.front());
		dirQueue.pop();

		auto it = dir->begin();
		for (; it != dir->end(); ++it) {
			if (it->isDirectory()) {
				dirQueue.emplace(it->GetFullPath());
			}
			else {
				int revision=-1;
				auto pathFromRoot = getSvnRelative(it->GetFullPath(),&revision);
				files.emplace_back(std::make_unique<FileInfo>(pathFromRoot,revision));
			}
		}
	}
}


FilesStructure::~FilesStructure()
{
}

void FilesStructure::AddFile(std::string filePath)
{
	auto dir = getSvnRootDir(filePath);
	auto relativePath = getSvnRelative(dir.GetFullPath(), filePath);
	createRevisionFile(relativePath, (Version)-1);
}
