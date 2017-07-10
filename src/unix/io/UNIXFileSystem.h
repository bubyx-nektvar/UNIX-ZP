#ifndef UNIX_FILE_SYSTEM_H_
#define UNIX_FILE_SYSTEM_H_

#include <string>

namespace unix {
	class FileSystem {
	public:
		static const char PathDelimetr = '/';
		static std::string PathConcat(std::string part1, std::string part2);
	};
}
#endif // !UNIX_FILE_SYSTEM_H_

