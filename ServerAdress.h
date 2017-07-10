#ifndef SERVER_ADRESS_H_
#define SERVER_ADRESS_H_

#include <string>
#include "AddressInfoWrapper.h"
#include "Testing.h"

class WrongAddressException 
	:exception {
public:
	WrongAddressException(){}
};

class ServerAdress
{
private:
	std::string ipAddress;
	std::string port;
	std::string svnPath;
public:
	ServerAdress(std::string adress);
	~ServerAdress();
	AdressInfoWrapper GetAddressInfo() const;
#ifdef TEST

	void assert(std::string ip, std::string p, std::string path) const{
		Assert::equals<std::string>(ip, this->ipAddress);
		Assert::equals<std::string>(p, this->port);
		Assert::equals<std::string>(path, this->svnPath);
	}
	static void test(){
		//IP
		auto x = ServerAdress("123.0.0.129:1234/public/mff/rep1");
		x.assert("123.0.0.129", "1234", "/public/mff/rep1");
		
		//HOST
		auto x2 = ServerAdress("localhost:1234/rep2");
		x2.assert("", "1234", "/rep2");
		//TODO

		//IPv6
		auto x3 = ServerAdress("[2001:db8:0:1234:0:567:8:1]:1234/private/rep2");
		x3.assert("[2001:db8:0:1234:0:567:8:1]", "1234", "/private/rep2");
	}
#endif // TEST

};


#endif // !SERVER_ADRESS_H_