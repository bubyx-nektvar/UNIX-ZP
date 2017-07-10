#include "UNIXDirectoryInfo.h"
#include "UNIXAPI.h"




unix::DirectoryInfo::iterator unix::DirectoryInfo::begin() const
{
	DIR *d = opendir(this->fullPath.c_str());
	
	return iterator(d);
}

unix::DirectoryInfo::iterator unix::DirectoryInfo::end() const
{
	return iterator(NULL);
}

unix::DirectoryInfo::iterator & unix::DirectoryInfo::iterator::operator++()
{
	struct dirent *de;
	if (de = readdir(this->dirp)) {
		//TODO CHECK: je d_name cela cesta?
		this->fi = FileInfo(std::string(de->d_name));
	}
	else {
		closedir(this->dirp);
	}
	return *this;
}

bool unix::DirectoryInfo::iterator::operator==(iterator other) const
{
	return this->dirp == other.dirp;
}

std::iterator<std::forward_iterator_tag, unix::FileInfo, int, const unix::FileInfo*, unix::FileInfo>::reference unix::DirectoryInfo::iterator::operator*() const
{
	return fi;
}

std::iterator<std::forward_iterator_tag, unix::FileInfo, int, const unix::FileInfo*, unix::FileInfo>::pointer unix::DirectoryInfo::iterator::operator->() const
{
	return &fi;
}
