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

void myfs::File::AddToTargetClearly(path toTarget,path fromRoot)
{
	WriteChunks(toTarget / fromRoot / path(file_name));
	std::vector<path> * tgs = new std::vector<path>();
	tgs->push_back(toTarget);
	this->log_init(tgs,fromRoot);
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
