#ifndef PATH_CONTEXT_H_
#define PATH_CONTEXT_H_

#include "unix/io/path.h"

struct PathContext{
public:
    path pathToPrevRevisionFile;
    path pathToCurrentModifiedFile;
    PathContext(path revFile,path modFile)
        :pathToPrevRevisionFile(revFile)
        ,pathToCurrentModifiedFile(modFile)
    {}
    
};
#endif