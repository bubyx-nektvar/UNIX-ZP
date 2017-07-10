#include "FilesStructure.h"
#include "UNIXFileSystem.h"
#include "UNIXDirectoryInfo.h"
#include <queue>



unix::DirectoryInfo FilesStructure::getSvnRootDir(std::string fullPath)
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

std::string FilesStructure::getSvnRelative(std::string svnRoot, std::string fullPath)
{
	return fullPath.substr(svnRoot.size(), fullPath.size() - svnRoot.size());
}

std::string FilesStructure::getSvnRelative(std::string svnFilePath, int * revision)
{
	auto i = svnFilePath.find_last_of(SVNDirName);
	if (i == -1) return std::string();

	auto x = svnFilePath.substr(i, svnFilePath.size() - i);
	i = svnFilePath.find_last_of('.');
	if (i == -1) return std::string();

	auto r = svnFilePath.substr(i + 1, svnFilePath.size() - (i + 1));
	auto p = svnFilePath.substr(0, i);
	*revision = std::stoi(r);
	return p;
}

FileInfo FilesStructure::createFile(unix::DirectoryInfo svnDir, std::string relativePath, int revision)
{
	auto fi = FileInfo(relativePath,revision);
	fi.CreateSvn(svnDir.GetFullPath());
	
}

FilesStructure::FilesStructure(std::string rootPath)
{
	this->rootPath = rootPath;
	auto fp = unix::FileSystem::PathConcat(rootPath, SVNDirName);
	std::queue<std::string> dirQueue;
	dirQueue.push(fp);
	while (dirQueue.size() > 0) {
		auto dir = std::make_unique<unix::DirectoryInfo>(new unix::DirectoryInfo(dirQueue.front()));
		dirQueue.pop();

		auto it = dir->begin();
		for (; it != dir->end(); it++) {
			if (it->isDirectory()) {
				dirQueue.emplace(it->GetFullPath());
			}
			else {
				int revision=-1;
				auto pathFromRoot = getSvnRelative(it->GetFullPath(),&revision);
				files.emplace_back(new FileInfo(pathFromRoot,revision));
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
	auto relaticePath = getSvnRelative(dir.GetFullPath(), filePath);
	createFile(dir, relaticePath, -1);
}
