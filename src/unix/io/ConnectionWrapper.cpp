#include "ConnectionWrapper.h"
#include <sys/types.h>
#include <sys/socket.h>

ConnectionWrapper::ConnectionWrapper(AdressInfoWrapper ai)
{
	while (ai.next()) {
		//TODO check errno
		fileDesc = ai.getSocket();
		if (connect(fileDesc, (struct sockaddr*)ai.addrinfo->ai_addr, ai.addrinfo->ai_addrlen) == 0)
			return;
	}
	throw new CouldNotConnectException();
}

ConnectionWrapper::~ConnectionWrapper()
{
}
