#pragma once
#include "Singleton.h"
#include "Logger.h"
#include "SystemConfiguration.h"

class LogSystem
{
public:
	ESSENTIALS_DLL static void PrintLog(const std::string& message);
	ESSENTIALS_DLL static void Configure(const std::string& fileLogName, const bool logToDebug, const bool logToConsole);

private:
	static Logger m_Logger;

};

#define LOG LogSystem::PrintLog
