#include "RootDirectory.h"
#include "FileStructure.h"
myfs::RootDirectory::RootDirectory(fs::path toRoot, std::string name)
	:originPath(toRoot) ,Directory(toRoot,fs::path(),name){}

void myfs::RootDirectory::Check(PathContext &paths)
{
	Directory::Check(PathContext(paths,fs::path()));
}

fs::path myfs::RootDirectory::GetDirPath()
{
	return originPath / fs::path(dir_name);
}

void myfs::RootDirectory::RewriteActualState(std::vector<fs::path>* target_dirs)
{
	PathContext p(target_dirs, originPath, fs::path(dir_name));
	for (auto x = direcotries.begin(); x != direcotries.end(); ++x) {
		x->RewriteActualState(p);
	}
	for (auto x = files.begin(); x != files.end(); ++x) {
		(*x)->RewriteActualState(p);
	}
}
