#ifndef FILE_INFO_H_
#define FILE_INFO_H_

#include <memory>
#include <sstream>
#include "UNIXFileSystem.h"
#include "UNIXFileInfo.h"

class FileInfo
{
private:
	std::string pathFromRoot;
	int lastUpdateRevision = -1;
	std::string pathWithRev();
public:
	FileInfo(std::string pathFromRoot, int revision) {
		this->pathFromRoot = pathFromRoot;
		this->lastUpdateRevision = revision;
	}
	void CreateSvn(std::string svnDirPath);
	~FileInfo();
};



#endif // !FILE_INFO_H_

