#include "UNIXAPI.h"
#include <string>
#include <iostream>
#include "FileStream.h"
#include <thread>
#include <memory>
#include <string>
#include "Messages.h"
#include "base.h"
#include "Global.h"
#include "ModeBuilder.h"
#include "RunParamException.h"

using namespace std;
extern shared_ptr<Settings> setting;
extern shared_ptr<ConsoleDispatcher> dispatcher;


void run_checking()
{
	while (setting->MakeLoop()) {
		setting->root->Check();

		setting->WaitInterval();
	}
}
void Run()
{
	std::thread check_t(run_checking);

	while (setting->MakeLoop()) {
		std::string line;
		getline(cin, line);
		dispatcher->DispatchLine(line);
		if (cin.fail())return;
	}
	check_t.join();
}
std::unique_ptr<Mode> processArgs(int argc, char * argv[]) {
	ModeBuilder mode;
	int opt;
	while (opt = getopt(argc, argv, "a:cus:") != -1) {
		switch (opt) {
		case 'a'://ADD FILE 
			ThrowIfFail(mode.AddFile(string(optarg)));
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
			fprintf(stderr,
				"usage: %s [-acou] [-s serverPort] [-p serverUrl]",
				basename(argv[0]));

			break;
		}
	}
	return mode.Build();
}
void ThrowIfFail(bool result) {
	if(!result) throw new RunParamException();

}

//jediny parametr je cesta k souboru .bbdata.conf
int main(int argc , char * argv[] ) {
	
	std::unique_ptr<Mode> mode = std::move(processArgs(argc,argv));

#ifdef TEST
	test();
#endif

	mode->Run();
	return 0;
}
