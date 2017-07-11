#include "AddFileMode.h"
#include "core/fileStructure/FilesStructure.h"

void AddFileMode::Run()
{
	fs.AddFile(filePath);
}

AddFileMode::~AddFileMode()
{
}