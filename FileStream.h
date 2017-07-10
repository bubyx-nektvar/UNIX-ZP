#ifndef FILE_STREAM_H_
#define FILE_STREAM_H_

#include <string>
#include "UNIXAPI.h"
#include "StreamWrapper.h"

namespace unix {
	enum OpenMode {
		Out = O_WRONLY,
		In = O_RDONLY,
		OI = O_RDWR,
		Trunc = O_TRUNC,
		Append = O_APPEND
	};
	class FileStream:StreamWrapper
	{
	public:
		FileStream(int fileDescriptor)
			:StreamWrapper(fileDescriptor) {
		}
		FileStream(const FileStream & fs)
			:FileStream(fs.fileDesc)
		{}
		static FileStream OpenFileStream(std::string path, OpenMode mode) {
			auto fd =open(path.c_str(), mode);
			return FileStream(fd);
		}

		~FileStream();
	};

}
#endif // !FILE_STREAM_H_
