#ifndef CONNECTION_WRAPPER_H_
#define CONNECTION_WRAPPER_H_

#include <exception>

#include "unix/io/AddressInfoWrapper.h"
#include "unix/io/StreamWrapper.h"

class CouldNotConnectException : std::exception {
private:
	AdressInfoWrapper addressinfo;
public:
	CouldNotConnectException(AdressInfoWrapper ai) :addressinfo(ai) {

	}
};
class ConnectionWrapper:StreamWrapper
{
public:
    ConnectionWrapper(const ConnectionWrapper& c)
    :StreamWrapper(c.fileDesc){
        
    }
	ConnectionWrapper(AdressInfoWrapper ai);
	~ConnectionWrapper();
	
};



#endif // !CONNECTION_WRAPPER_H_

