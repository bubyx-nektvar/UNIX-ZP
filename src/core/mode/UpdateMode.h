#ifndef UPDATE_MODE_H_
#define UPDATE_MODE_H_

#include "ClientMode.h"

class UpdateMode :
	public ClientMode
{
public:
	UpdateMode(ServerAdress adress)
		:ClientMode(adress){}
	~UpdateMode();
	virtual void Run() override;
};

#endif