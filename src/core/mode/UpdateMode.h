#ifndef UPDATE_MODE_H_
#define UPDATE_MODE_H_

#include "ClientMode.h"

class UpdateMode :
	public ClientMode
{
public:
	UpdateMode(ServerAdress adress,std::string rootPath)
		:ClientMode(adress, rootPath)
    {}
	~UpdateMode();
	virtual void Run() override;
};

#endif