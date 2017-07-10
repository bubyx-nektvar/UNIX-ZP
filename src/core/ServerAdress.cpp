#include "ServerAdress.h"


ServerAdress::ServerAdress(std::string adress)
{
	auto i = adress.find_last_of(':');
	if (i < 0)throw new WrongAddressException();
	ipAddress = adress.substr(0, i);
	adress = adress.substr(i + 1);
	i = adress.find_first_of('/');
	if (i < 0)throw new WrongAddressException();
	port = adress.substr(0, i);
	svnPath = adress.substr(i);
}


ServerAdress::~ServerAdress()
{
}

AdressInfoWrapper ServerAdress::GetAddressInfo() const
{
	return AdressInfoWrapper(ipAddress, port);
}
