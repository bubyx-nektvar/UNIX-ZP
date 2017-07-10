#include <sstream>
#include "StreamWrapper.h"
#include "UNIXAPI.h"


int StreamWrapper::readSysToBuff()
{
	if (buffNextCharPosition >= buffLength) {
		buffLength = read(this->fileDesc, this->buff.get(), sizeof(char)*buffMaxLength);
		buffNextCharPosition = 0;
		if(buffLength<0)
		{
			errorNumber = errno;
		}
		else if(buffLength == 0)
		{
			_eof = true;
		}
	}
	return buffLength;
}
int StreamWrapper::buffedRead(char * buff, int startPos, size_t maxLength)
{
	readSysToBuff();
	auto i = 0;
	for (; i < maxLength && buffNextCharPosition < buffLength; ++i,++buffNextCharPosition) {
		buff[startPos + i] = this->buff[buffNextCharPosition];
	}
	return i;
}

StreamWrapper::~StreamWrapper()
{
	close(this->fileDesc);
}

int StreamWrapper::wread(char * buff, int startPos, size_t maxLength)
{
	return buffedRead(buff, startPos, maxLength);
}

std::string StreamWrapper::readChunk()
{
	const size_t len = 1024 * 128;
	char buff[len];
	auto readed = wread(&buff[0], 0, len);
	return std::string(buff, readed);
}

int StreamWrapper::wwrite(const char * buff, int startPos, size_t length) const
{
	return write(this->fileDesc, buff + startPos, length * sizeof(char));
}

void StreamWrapper::wwrite(std::string text) const
{
	auto x = wwrite(text.c_str(), 0, text.size());
}

std::string StreamWrapper::getline()
{

	bool newLineReaded = false;
	bool carrigeReturnReaded = false;
	std::stringstream ss;
	
	readSysToBuff();
	
	while(!((newLineReaded&&carrigeReturnReaded)||eof()))
	{
		auto c = buff[buffNextCharPosition++];
		switch(c)
		{
			case '\n':
				newLineReaded = true;
				break;
			case '\r':
				carrigeReturnReaded = true;
				break;
			default:
				if (newLineReaded) {
					ss << '\n';
					newLineReaded = false;
				}
				if (carrigeReturnReaded) {
					ss << '\r';
					carrigeReturnReaded = false;
				}
				ss << c;
				break;
		}
		readSysToBuff();
	}
	return ss.str();

}
