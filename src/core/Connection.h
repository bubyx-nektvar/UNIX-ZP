#ifndef CONNECTION_H_
#define CONNECTION_H_

#include "unix/io/ConnectionWrapper.h"

class ClientConnection
{
private:
    ConnectionWrapper baseConnection;
public:
	ClientConnection(ConnectionWrapper c)
        :baseConnection(c)
    {}
        
	~ClientConnection();
};


#endif // !CONNECTION_H_
