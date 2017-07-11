#ifndef ADD_FILE_MODE_H_
#define ADD_FILE_MODE_H_

#include <string>
#include <memory>
#include "ClientMode.h"

class AddFileMode :
	public ClientMode
{
private:
	std::string filePath;
public:
	AddFileMode(ServerAdress serverPath,std::string rootPath, std::string filePath) 
		:ClientMode(serverPath, rootPath) 
	{
		this->filePath = filePath;
	}
	virtual void Run() override;
	~AddFileMode();
};

#endif