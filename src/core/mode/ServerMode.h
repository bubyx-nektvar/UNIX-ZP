#ifndef SERVER_MODE_H_
#define SERVER_MODE_H_

#include "Mode.h"

class ServerMode
	:public Mode
{
private:
	int port;
public:
	ServerMode(int port) {
		this->port = port;
	}
	~ServerMode();
	virtual void Run() override;
};


#endif // !SERVER_MODE_H_