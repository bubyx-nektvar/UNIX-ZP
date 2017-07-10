#include "ChunkType.h"
#include <string>
#include <sstream>
#include <iomanip>
unix::FileStream Text::openFile(std::string file_path,unix::OpenMode mode)
{
	return unix::FileStream::OpenFileStream(file_path,mode);
}

Text Text::readChunk(unix::FileStream & s)
{
	std::string line;
	std::getline(s, line);
	return Text(line);
}

Text Text::parseChunk(std::string & s)
{
	return Text(s);
}

void Text::Write(unix::FileStream & output,bool isLast) const
{
	if (isLast) output << line;
	else output << line <<std::endl;
}

std::string Text::ToString() const
{
	return line;
}