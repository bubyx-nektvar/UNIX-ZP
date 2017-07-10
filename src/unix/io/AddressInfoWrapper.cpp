#include "AddressInfoWrapper.h"

AdressInfoWrapper::AdressInfoWrapper(std::string adress, std::string port)
{
	struct addrinfo hi;
	memset(&hi, 0, sizeof(hi));
	hi.ai_family = AF_UNSPEC;
	hi.ai_socktype = SOCK_STREAM;
	getaddrinfo(adress.c_str(), port.c_str(), &hi, &addrinfo);
	originAddrInfo = addrinfo;
}
