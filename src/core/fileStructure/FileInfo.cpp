#include "FileInfo.h"



FileInfo::FileInfo()
{
}


std::string FileInfo::pathWithRev()
{
	auto x = std::stringstream();
	x << pathFromRoot << '.' << lastUpdateRevision;
	return x.str();
}

void FileInfo::CreateSvn(std::string svnDirPath)
{
	auto fi = unix::FileInfo(unix::FileSystem::PathConcat(svnDirPath, pathWithRev()));
	fi.create();
}

FileInfo::~FileInfo()
{
}
