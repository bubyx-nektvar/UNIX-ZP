#ifndef  IO_EXCEPTION_H_
#define  IO_EXCEPTION_H_

#include <exception>
#include <string>
#include  "path.h"

class IOException :
	public std::exception
{
private:
	std::string filePath;
	int errorNumober;
public:
	IOException(path p, int errno)
		:filePath(p.str())
		, errorNumober(errno)
	{}
	IOException(std::string path, int errno)
		:filePath(path)
		, errorNumober(errno)
	{}
	~IOException();
	std::string Error() const
	{
		switch(errorNumober){

			case EACCES:
				return "A component of the path prefix denies search permission.";
			case EIO:
				return "An error occurred while reading from the file system.";
			case ELOOP:
				return "A loop exists in symbolic links encountered during resolution of the path argument.";
			case ENAMETOOLONG:
				return "The length of a pathname exceeds{ PATH_MAX } or a pathname component is longer than{ NAME_MAX }.";
			case ENOTDIR:
				return "A component of the path prefix is not a directory.";
			case ENOENT:
				return "A component of path does not name an existing file or path is an empty string.";
			case EOVERFLOW:
				return "The file size in bytes or the number of blocks allocated to the file or the file serial number cannot be represented correctly in the structure pointed to by buf.";
			default:
				return "Unspecified IO error";
		}
		
	}
};
#endif
