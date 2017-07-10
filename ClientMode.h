#ifndef CLIENT_MODE_H_
#define CLIENT_MODE_H_

#include <string>
#include <memory>
#include "Mode.h"
#include "ServerAdress.h"
#include "Connection.h"

class ClientMode :
	public Mode
{
private:
	ServerAdress serverPath;
public:
	void SetServerPath(std::string path) {
		this->serverPath = ServerAdress(path);
	}
	ClientMode():serverpath(""){}
	ClientMode(ServerAdress path) 
		:serverPath(path){
	}
	std::unique_ptr<ClientConnection> getConnection() const;
}


#endif