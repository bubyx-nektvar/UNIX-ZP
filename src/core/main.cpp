#include <string>
#include <iostream>
#include <thread>
#include <memory>
#include <string>
#include "unix/io/FileSystem.h"
#include "unix/io/FileStream.h"
#include "Messages.h"
#include "base.h"
#include "mode/ModeBuilder.h"
#include "RunParamException.h"

void ThrowIfFail(bool result) {
	if(!result) throw RunParamException();

}

std::unique_ptr<Mode> processArgs(int argc, char * argv[]) {
	ModeBuilder mode(unix::FileSystem::getCurrentDirPath());
	int opt;
	while (opt = getopt(argc, argv, "a:cus:") != -1) {
		switch (opt) {
		case 'a'://ADD FILE 
			ThrowIfFail(mode.AddFile(std::string(optarg)));
			break;
		case 'c'://COMMIT
			ThrowIfFail(mode.SetCommit());
			break;
		case 'o'://CHECK-OUT
			ThrowIfFail(mode.SetCheckOut());
			break;
		case 'u'://UPDATE
			ThrowIfFail(mode.SetUpdate());
			break;
		case 's'://RUN AS SERVER
			ThrowIfFail(mode.SetServerMode(std::string(optarg)));
			break;
		case 'p':
			ThrowIfFail(mode.SetServerAddress(std::string(optarg)));
			break;
		case '?':
            throw RunParamException();

			break;
		}
	}
	return mode.Build();
}

//jediny parametr je cesta k souboru .bbdata.conf
int main(int argc , char * argv[] ) {
	
	std::unique_ptr<Mode> mode = std::move(processArgs(argc,argv));

	mode->Run();
	return 0;
}
