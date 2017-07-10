#include "unix/io/FileInfo.h"

unix::DirectoryInfo unix::FileInfo::GetParentDirectory() const
{
	return DirectoryInfo(this->fullPath.parent());
}
