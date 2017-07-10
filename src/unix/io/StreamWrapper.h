#ifndef STREAM_WRAPPER_H_
#define STREAM_WRAPPER_H_

#include <string>
#include <memory>

class StreamWrapper
{
protected:
	int fileDesc;
	std::unique_ptr<char[]> buff;
	int buffMaxLength;
	int buffLength;
	int buffNextCharPosition;
	bool _eof;
	int buffedRead(char * buff, int startPos,size_t maxLength);
	int readSysToBuff();
	int errorNumber;
public:
	StreamWrapper(int filedescription)
		:fileDesc(filedescription),
		buffMaxLength(1024 * 128),
		buffLength(buffMaxLength),
		buffNextCharPosition(buffLength)
	{
		this->buff = std::make_unique<char[]>(buffMaxLength);
		readSysToBuff();
	}
    void close();
	~StreamWrapper();
	int wread(char * buff, int startPos, size_t maxLength);
	std::string readChunk();
	int wwrite(const char* buff, int startPos, size_t length) const;
	void wwrite(std::string text) const;
	std::string getline();
	bool eof() const
	{
		return _eof;
	}
};



#endif // !STREAM_WRAPPER_H_
