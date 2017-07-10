#ifndef COMMIT_MODE_H_
#define COMMIT_MODE_H_

#include "ClientMode.h"

class CommitMode :
	public ClientMode
{
public:
	CommitMode(ServerAdress adress)
		:ClientMode(adress) {}
	~CommitMode();
	virtual void Run() override;
};


#endif // !COMMIT_MODE_H_

