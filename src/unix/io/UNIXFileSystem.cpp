#include "UNIXFileSystem.h"

std::string unix::FileSystem::PathConcat(std::string part1, std::string part2)
{
	while(part1[part1.size() - 1] == PathDelimetr) {
		part1 = part1.substr(0, part1.size() - 1);
	}
	if (part2[part2.size() - 1] != PathDelimetr) {
		part2 = PathDelimetr + part2;
	}
	return part1 + part2;
}
