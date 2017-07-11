#include "unix/io/FileSystem.h"
#include <unistd.h>

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
std::string FileSystem::getCurrentDirPath(){
    size_t size = 1024;
    char * buff;
    char * ptr;
    
    for(buff = ptr = NULL; ptr == NULL; size *= 8){
        delete buff;
        buff = new char[size];
        
        ptr = getcwd(buff, size);
        if(prt==NULL && errno != ERANGE){
            throw OutOfRangeException();
        }
    }
    free(buff);
    
}