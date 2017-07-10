#ifndef ILOGGER_H_
#define ILOGGER_H_
#include <vector>
#include "path.h"
class ILogger {
public:
	//file - cesta z root az k souboru (vcetne nazvu souboru)
	virtual void Open(std::vector<path>* targets, path file) = 0;
	virtual void Open(std::vector<path>& log_files) = 0;

	//close opened fstreams
	virtual void Close() = 0;
	virtual	void LogVersion(unsigned long prevVersion, unsigned long newversion) = 0;
	virtual void LogDelete() = 0;
	virtual void LogCreate() = 0;
};
#endif
