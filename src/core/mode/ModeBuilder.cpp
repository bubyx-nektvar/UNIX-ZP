#include "RunParamException.h"
#include "ModeBuilder.h"
#include "AddFileMode.h"
#include "CommitMode.h"
#include "CheckoutMode.h"
#include "ServerMode.h"
#include "UpdateMode.h"


bool ModeBuilder::SetMode(BuilderModeSelector mode)
{
	if (this->mode == BuilderModeSelector::None || this->mode == mode) {
		this->mode = mode;
		return true;
	}
	return false;
}

ModeBuilder::ModeBuilder()
{
}


ModeBuilder::~ModeBuilder()
{
}

bool ModeBuilder::AddFile(std::string file)
{
	this->file = file;
	return SetMode(BuilderModeSelector::AddFile);
}

bool ModeBuilder::SetServerMode(std::string port)
{
	this->port = std::stoi(port);
	return SetMode(BuilderModeSelector::Server);
}

std::unique_ptr<Mode> ModeBuilder::Build()
{
	std::unique_ptr<Mode> result;
	switch (this->mode)
	{
		case BuilderModeSelector::AddFile:
			result = std::make_unique<Mode>(new AddFileMode(this->serverAdress,this->file));
			break;
		case BuilderModeSelector::Checkout:
			result = std::make_unique<Mode>(new CheckoutMode(this->serverAdress));
			break;
		case BuilderModeSelector::Commit:
			result = std::make_unique<Mode>(new CommitMode(this->serverAdress));
			break;
		case BuilderModeSelector::Server:
			result = std::make_unique<Mode>(new ServerMode(this->port));
			break;
		case BuilderModeSelector::Update:
			result = std::make_unique<Mode>(new UpdateMode(this->serverAdress));
			break;
		default:
			throw new RunParamException();
			break;
	}
	return result;
}
