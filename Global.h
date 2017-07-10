#ifndef GLOBAL_H_
#define GLOBAL_H_
#include "ConsoleDispatcher.h"
#include "Settings.h"
std::shared_ptr<ConsoleDispatcher> dispatcher(nullptr);
std::shared_ptr<Settings> setting(nullptr);
#endif