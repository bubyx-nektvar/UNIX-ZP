#ifndef ADDRESS_INFO_WRAPPER_H_
#define ADDRESS_INFO_WRAPPER_H_

#include <string>

struct AdressInfoWrapper {
public:
	struct addrinfo* originAddrInfo;
	struct addrinfo* addrinfo;
	AdressInfoWrapper(std::string adress, std::string port);
	~AdressInfoWrapper() {
		if (originAddrInfo != NULL) {
			freeaddrinfo(originAddrInfo);
		}
	}
	bool next() {
		if (addrinfo != NULL) {
			addrinfo = addrinfo->ai_next;
		}
		return addrinfo != NULL;
	}
	int getSocket() {
		return socket(addrinfo->ai_family, addrinfo->ai_socktype, addrinfo->ai_protocol);
	}
};


#endif // !ADDRESS_INFO_WRAPPER_H_
