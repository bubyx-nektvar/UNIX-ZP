#ifndef UNIX_DIRECOTORY_INFO_H_
#define UNIX_DIRECOTORY_INFO_H_

#include <string>
#include <iterator>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

namespace unix{
    class DirectoryInfo;
}
#include "path.h"
#include "unix/io/FileInfo.h"
#include "unix/io/FileSystem.h"

namespace unix {
	class DirectoryInfo
		:public FileInfo
	{
        public:

            class iterator :std::iterator<std::output_iterator_tag,FileInfo,int,const FileInfo*,FileInfo> {
            private:
                DIR* dirp;
                FileInfo fi;
            public:
                iterator(DIR* d);
                iterator& operator++();
                bool operator==(iterator other) const;
                bool operator!=(iterator other) const { return !(*this == other); }
                reference operator*() const;
                pointer operator->() const;
                ~iterator() {
                    if (dirp != NULL) closedir(dirp);
                }
            };

            iterator begin() const;
            iterator end() const;
            DirectoryInfo(path p);
            DirectoryInfo(std::string fullPath);
            ~DirectoryInfo();

            //pravda pokud je koren souboroveho systemu
            bool isRoot() const;
            FileInfo GetChild(std::string name) const;

	};
}

#endif // !UNIX_DIRECOTORY_INFO_H_