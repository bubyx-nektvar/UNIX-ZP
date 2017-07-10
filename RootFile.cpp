#include "RootFile.h"

void myfs::RootFile::WriteHash(std::ostream & output, fs::path rootPath)
{
	file->WriteHash(output, rootPath);
}

void myfs::RootFile::CreateVersion(VersionChange & ver, vector<fs::path> * targets)
{
	file->CreateVersion(ver, PathContext(targets,originPath,fs::path() ));
}

void myfs::RootFile::SetHash(std::unordered_map<std::string, Hash> hashes)
{
	file->SetHash(hashes, fs::path());
}

void myfs::RootFile::RewriteActualState(std::vector<fs::path>* target_dirs)
{
	file->RewriteActualState(PathContext(target_dirs, originPath,fs::path()));
}

void myfs::RootFile::Check(std::vector<fs::path>* targetDirs) {
	file->Check(PathContext(targetDirs,originPath,fs::path()));
}
fs::path myfs::RootFile::GetFilePath() {
	return originPath / fs::path(file->GetName());
}