#include "File.h"

#include <sstream>
#include <iomanip>

void myfs::File::RewriteSVNFile(const PathContext& paths){
    WriteChunks(paths.pathToPrevRevisionFile);
}
void myfs::File::RewriteCurrentFile(const PathContext& paths){
    WriteChunks(paths.pathToCurrentModifiedFile);
}
void myfs::File::RewriteAll(const PathContext& paths)
{
    RewriteSVNFile(paths);
    RewriteCurrentFile(paths);
}

bool myfs::File::is_change(vector<BaseNumberType>* change_description)
{
	BaseNumberType i = 0;
	for (auto it = change_description->begin(); it != change_description->end(); ++it,++i) {
		if (*it != i) {
			return true;
		}
	}
	return false;
}
