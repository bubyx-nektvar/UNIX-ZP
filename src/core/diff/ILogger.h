#ifndef ILOGGER_H_
#define ILOGGER_H_

#include <vector>
#include "unix/io/path.h"

class ILogger {
public:
	virtual void Open(path fullPath) = 0;

	//close opened fstreams
	virtual void Close() = 0;
	virtual	void LogVersion(unsigned long prevVersion, unsigned long newversion) = 0;
	virtual void LogDelete() = 0;
	virtual void LogCreate() = 0;
};
#endif
