#include "ClientMode.h"
#include "UNIXAPI.h"
#include "ConnectionWrapper.h"

std::unique_ptr<ClientConnection> ClientMode::getConnection() const
{
	auto ai = this->serverPath.GetAddressInfo();
	auto c = ConnectionWrapper(ai);
	return std::make_unique<ClientConnection>(c);
}
