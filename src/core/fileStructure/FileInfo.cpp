#include "FileInfo.h"

#include <sstream>
#include "unix/io/FileInfo.h"



path FileInfo::pathWithRev()
{
	auto x = std::stringstream();
	x << pathFromRoot << '.' << lastUpdateRevision;
	return x.str();
}

void FileInfo::CreateSvn(path svnDirPath)
{
	auto fi = unix::FileInfo(svnDirPath/pathWithRev());
	fi.create();
}

FileInfo::~FileInfo()
{
}
