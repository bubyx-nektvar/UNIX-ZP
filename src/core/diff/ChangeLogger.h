#ifndef CHANGE_LOGGER_
#define CHANGE_LOGGER_

#include <vector>
#include <algorithm>
#include "unix/io/path.h"
#include "unix/io/FileStream.h"

template<typename T> class ChangeLogger;

#include "core/base.h"
#include "ILogger.h"

template<typename T>
class ChangeLogger: public ILogger
{
private :
	unix::FileStream logFile;
public:
	
	void Open(path fullPath) override{
        logFile = unix::FileStream::OpenFileStream(fullPath.str(),unix::OpenMode::Out|unix::OpenMode::Append);
	}
	void Close() override{
        logFile.close();
	}
	void LogAdd(T chunk, Index i) {
		logFile << "add;" << i << ";" << chunk.ToString() << '\n';
	}
	void LogRemoveChunk(Index i) {
		logFile << "remove;" << i << '\n';
	}
	void LogVersion(unsigned long prevVersion, unsigned long newversion) override{
		logFile << "version;" << prevVersion << ";" << newversion << '\n';
	}
	void LogDelete() override{
		logFile << "deleted" << '\n';
	}
	void LogCreate() override{
		logFile << "crea30ted" << '\n';
	}
};
#endif

