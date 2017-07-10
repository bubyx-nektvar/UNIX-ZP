#ifndef CHUNK_TYPE_H_
#define CHUNK_TYPE_H_
#include <iostream>
#include <string>
#include <memory>
#include "unix/io/FileStream.h"

class Text{
public:
	Text(std::string s):line(s){}
	static unix::FileStream openFile(std::string file_path,unix::OpenMode mode = unix::OpenMode::OI);
	static Text readChunk(unix::FileStream & s);
	static Text parseChunk(std::string & s);
	void Write(unix::FileStream & output,bool isLast) const;
	std::string ToString() const;
	struct Comparer {
		bool operator() (const Text& lhs, const Text& rhs) const
		{
			return lhs.line < rhs.line;
		}
	};
private:
	std::string line;
};
#endif // ! CHUNK_TYPE_H_

