#ifndef CHECKOUT_MODE_H_
#define CHECKOUT_MODE_H_

#include "ClientMode.h"
#include "core/ServerAdress.h"

class CheckoutMode:
	public ClientMode
{
public:
	CheckoutMode(ServerAdress adress,std::string rootPath)
		:ClientMode(adress, rootPath) {}
	~CheckoutMode();
	virtual void Run() override;
};


#endif // !CHECKOUT_MODE_