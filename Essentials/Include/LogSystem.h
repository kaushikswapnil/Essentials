#pragma once

#define LOG_ENABLED

#ifdef LOG_ENABLED

#include "SystemConfiguration.h"
#include <string>

class LogSystem
{
public:
	ESSENTIALS_DLL static void PrintLog(const std::string& message);
	ESSENTIALS_DLL static void Configure(const std::string& fileLogName, const bool logToDebug, const bool logToConsole);
};

#endif

#ifdef LOG_ENABLED
#define LOG(x) LogSystem::PrintLog(x);
#else
#define LOG(x) 
#endif
