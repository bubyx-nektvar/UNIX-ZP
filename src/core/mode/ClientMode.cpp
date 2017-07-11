#include "ClientMode.h"
#include "unix/io/ConnectionWrapper.h"
#include "unix/io/AddressInfoWrapper.h"

std::unique_ptr<ClientConnection> ClientMode::getConnection() const
{
	auto ai = this->serverPath.GetAddressInfo();
	auto c = ConnectionWrapper(ai);
	return std::make_unique<ClientConnection>(c);
}
