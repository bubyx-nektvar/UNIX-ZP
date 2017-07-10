#ifndef FILE_INFO_H_
#define FILE_INFO_H_

#include <memory>
#include <sstream>
#include "unix/io/path.h"

class FileInfo
{
private:
	path pathFromRoot;
	int lastUpdateRevision = -1;
	path pathWithRev();
public:
	FileInfo(std::string pathFromRoot, int revision)
        :pathFromRoot(pathFromRoot),lastUpdateRevision(revision)
    { }
	void CreateSvn(path svnDirPath);
	~FileInfo();
};



#endif // !FILE_INFO_H_

