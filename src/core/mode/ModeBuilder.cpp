#include "ModeBuilder.h"
#include "core/RunParamException.h"
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
			//result = std::make_unique<Mode>(new AddFileMode(this->serverAdress,this->file));
			result = std::make_unique<AddFileMode>(this->serverAdress, this->rootPath, this->file);
			break;
		case BuilderModeSelector::Checkout:
			result = std::make_unique<CheckoutMode>(this->serverAdress, this->rootPath);
			break;
		case BuilderModeSelector::Commit:
			result = std::make_unique<CommitMode>(this->serverAdress, this->rootPath);
			break;
		case BuilderModeSelector::Server:
			result = std::make_unique<ServerMode>(this->port);
			break;
		case BuilderModeSelector::Update:
			result = std::make_unique<UpdateMode>(this->serverAdress, this->rootPath);
			break;
		default:
			throw new RunParamException();
			break;
	}
	return result;
}
