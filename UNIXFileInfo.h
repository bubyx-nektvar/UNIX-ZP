#ifndef UNIX_FILE_INFO_H_
#define UNIX_FILE_INFO_H_

#include <string>
#include <errno.h>
#include "UNIXAPI.h"
//#include <sys/stat.h>
#include "path.h"
#include "UNIXDirectoryInfo.h"
#include "FileStream.h"
#include "IOException.h"

namespace unix {

	class FileInfo
	{
	private:
		bool _isDirectory;
		bool _exists;
		void readInfo()
		{
			//TODO init isDirectory, exists
			struct stat buffer;
			int status = lstat(fullPath.c_str(), &buffer);
			if (status<0) throw new IOException(fullPath, (int)errno);
		}
	protected:
		path fullPath;
	public:
		FileInfo(path p) :fullPath(p)
		{
			readInfo();
		}
		FileInfo(std::string fullPath) :fullPath(fullPath)
		{
			readInfo();
		}
		~FileInfo();
		bool isDirectory() const { return _isDirectory; }
		bool exists() const { return _exists; }
		path GetFullPath() const { return fullPath; }
		DirectoryInfo GetParentDirectory() const;
		void create();
		FileStream openRead() const{
			auto fd = open(fullPath.c_str(), O_RDONLY);
			return FileStream(fd);
		}
		FileStream openRewrite() const{
			auto fd = open(fullPath.c_str(), O_WRONLY | O_CREAT | O_TRUNC);
			return FileStream(fd);
		}
		FileStream openAppend() const{
			auto fd = open(fullPath.c_str(), O_WRONLY|O_CREAT|O_APPEND);
			return FileStream(fd);
		}
	};
}
#endif

