#ifndef PATH_CONTEXT_H_
#define PATH_CONTEXT_H_

#include "core/base.h"
#include "unix/io/path.h"

class PathContext{
private:
    path rootPath;
    path relativePath;
    path svnDirName;
    Version version;
public:
    
    path pathToPrevRevisionFile() const{
        return rootPath / svnDirName / relativePath + '.' + version;
    }
    path pathToCurrentModifiedFile() const{
        return rootPath / relativePath;
    }
    PathContext(path relativePath, path rootPath, path svnDirName, Version version)
        : rootPath(rootPath), relativePath(relativePath)
        , svnDirName(svnDirName),version(version)
    {}
    
};
#endif