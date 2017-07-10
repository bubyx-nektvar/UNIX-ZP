#ifndef FILES_STRUCTURE_H_
#define FILES_STRUCTURE_H_

#include <vector>
#include <memory>
#include <string>
#include "FileInfo.h"
#include "unix/io/DirectoryInfo.h"

class FilesStructure
{
private:
	const static std::string SVNDirName;
	std::string rootPath;
	std::vector<std::unique_ptr<FileInfo>> files;

	static unix::DirectoryInfo getSvnRootDir(std::string fullPath);
	//ziska relativni cestu vuci .svn z cesty .../.svn/../....
	static std::string getSvnRelative(path svnRoot, std::string fullPath);
	//získa relativni cestu vuci .svn z cesty .../.svn/....
	static std::string getSvnRelative(path svnFilePath, int* revision);
	static FileInfo createFile(unix::DirectoryInfo svnDir, std::string relativePath, int revision);
public:
	FilesStructure(std::string rootPath);
	~FilesStructure();
	static void AddFile(std::string filePath);
};


#endif