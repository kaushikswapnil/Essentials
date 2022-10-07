#include "pch.h"
#include "LogSystem.h"
#include "Logger.h"

Logger& GetLogger() { static Logger l; return l; }

void LogSystem::PrintLog(const std::string& message)
{
	GetLogger().PrintLog(message);
}

void LogSystem::Configure(const std::string& fileLogName, const bool logToDebug, const bool logToConsole)
{
	GetLogger().Configure(fileLogName, logToDebug, logToConsole);
}
