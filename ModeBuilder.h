#ifndef MODE_BUILDER_H_
#define MODE_BUILDER_H_

#include <string>
#include <iostream>
#include <memory>
#include "ServerAdress.h"
#include "Mode.h"

enum BuilderModeSelector {
	None = -1,
	AddFile = 1,
	Commit,
	Update,
	Server,
	Checkout

};

class ModeBuilder
{
private:
	BuilderModeSelector mode;
	std::string file;
	int port;
	ServerAdress serverAdress;
	bool SetMode(BuilderModeSelector mode);
public:
	ModeBuilder();
	~ModeBuilder();
	bool AddFile(std::string file);
	bool SetCommit() {
		return SetMode(BuilderModeSelector::Commit);
	}
	bool SetUpdate() {
		return SetMode(BuilderModeSelector::Update);
	}
	bool SetServerMode(std::string port);
	bool SetServerAddress(std::string serverAdress) {
		this->serverAdress = ServerAdress(serverAdress);
		return true;
	}
	bool SetCheckOut() {
		return SetMode(BuilderModeSelector::Checkout);
	}
	std::unique_ptr<Mode> Build();

};

#endif