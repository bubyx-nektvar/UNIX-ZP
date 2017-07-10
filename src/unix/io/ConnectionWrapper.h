#ifndef CONNECTION_WRAPPER_H_
#define CONNECTION_WRAPPER_H_

#include <exception>

#include "AddressInfoWrapper.h"
#include "StreamWrapper.h"

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
	ConnectionWrapper(AdressInfoWrapper ai);
	~ConnectionWrapper();
	
};



#endif // !CONNECTION_WRAPPER_H_

