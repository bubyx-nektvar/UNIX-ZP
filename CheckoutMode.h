#ifndef CHECKOUT_MODE_H_
#define CHECKOUT_MODE_H_

#include "ClientMode.h"
#include "ServerAdress.h"

class CheckoutMode:
	public ClientMode
{
public:
	CheckoutMode(ServerAdress adress)
		:ClientMode(adress) {}
	~CheckoutMode();
	virtual void Run() override;
};


#endif // !CHECKOUT_MODE_