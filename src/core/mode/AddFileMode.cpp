#include "AddFileMode.h"
#include "FilesStructure.h"

void AddFileMode::Run()
{
	FilesStructure::AddFile(filePath);
}

AddFileMode::~AddFileMode()
{
}