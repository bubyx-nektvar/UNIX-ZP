#ifndef VERSION_CHANGE_H_
#define VERSION_CHANGE_H_

class VersionChange;
#include "core/base.h"

class VersionChange
{
public:
	//from - zmena z verze
	//newv - nova verze
	//continuev - verze na kterou nazazuje
	VersionChange(Version from, Version newv, Version continuev) 
		:from_version(from),new_version(newv),continue_version(continuev){

	}
	//from_version - zmena z verze
	Version from_version;
	//new_version - nova verze
	Version new_version;
	//continue_version - verze na kterou tato verze navazuje
	Version continue_version;

	//zjisti zda verze pokracuje v dive nactene verzi (from_version!=continue_version)
	bool ShouldReload() {
		return from_version != continue_version;
	}
};
#endif

