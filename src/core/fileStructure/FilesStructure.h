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

	unix::DirectoryInfo getSvnRootDir(path fullPath);
	//ziska relativni cestu vuci .svn z cesty .../.svn/../....
	path getSvnRelative(path svnRoot, path fullPath);
	//získa relativni cestu vuci .svn z cesty .../.svn/....
	path getSvnRelative(path svnFilePath, int* revision);
	FileInfo createRevisionFile(path relativePath, int revision);
public:
	FilesStructure(std::string rootPath);
	~FilesStructure();
	void AddFile(std::string filePath);
};


#endif