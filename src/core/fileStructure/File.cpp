#include "File.h"
#include "Settings.h"
extern shared_ptr<Settings> setting;
#include <sstream>
#include <iomanip>
void myfs::File::Check(PathContext & paths) {
#ifdef DEBUG
	std::cout << ">>Checking file:" << paths.pathFromRoot << file_name;
#endif // DEBUG

	path used_pathToRoot;
	if (check_files_change(paths,used_pathToRoot)) {
		Rewrite(used_pathToRoot, paths);
	}
#ifdef  DEBUG
	std::cout << "....done" << endl;
#endif //  DEBUG

}


void myfs::File::Rewrite(path & used_pathToRoot,const PathContext& paths, bool rewriteAll)
{
	if (rewriteAll||(used_pathToRoot!=paths.pathToRoot)) {
		WriteChunks(paths.pathToRoot / paths.pathFromRoot /path( file_name));
	}
	for (auto it = paths.targetDirs->begin(); it != paths.targetDirs->end(); ++it) {
		if (rewriteAll||(*it != used_pathToRoot)) {
			
			WriteChunks((*it) / paths.pathFromRoot / path(file_name));
		}
	}
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
