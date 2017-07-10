#ifndef UNIX_DIRECOTORY_INFO_H_
#define UNIX_DIRECOTORY_INFO_H_

#include <string>
#include <iterator>
#include "UNIXFileSystem.h"
#include "UNIXFileInfo.h"
#include "UNIXAPI.h"

namespace unix {
	class DirectoryInfo
		:public FileInfo
	{
	private:

	public:

		class iterator :std::iterator<std::output_iterator_tag,FileInfo,int,const FileInfo*,FileInfo> {
		private:
			DIR* dirp;
			FileInfo fi;
		public:
			iterator(DIR* d)
				:dirp(d),fi("")
			{}
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
		DirectoryInfo(path p)
			:FileInfo(p)
		{}
		DirectoryInfo(std::string fullPath):FileInfo(fullPath) {

		}
		~DirectoryInfo();

		//pravda pokud je koren souboroveho systemu
		bool isRoot() const{
			return this->fullPath[0] == FileSystem::PathDelimetr;
		}
		FileInfo GetChild(std::string name) const{
			auto path = this->fullPath + unix::FileSystem::PathDelimetr + name;
			return FileInfo(path);
		}

	};
}

#endif // !UNIX_DIRECOTORY_INFO_H_