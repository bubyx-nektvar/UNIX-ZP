#ifndef CLIENT_MODE_H_
#define CLIENT_MODE_H_

#include <string>
#include <memory>
#include "Mode.h"
#include "core/ServerAdress.h"
#include "core/Connection.h"
#include "core/fileStructure/FilesStructure.h"

class ClientMode :
	public Mode
{
private:
	ServerAdress serverPath;
    FilesStructure fs;
public:
	ClientMode()
        :serverPath(""),fs("")
    {}
	ClientMode(ServerAdress path,std::string rootPath) 
        :serverPath(path),fs(rootPath)
    {}
	std::unique_ptr<ClientConnection> getConnection() const;
};


#endif