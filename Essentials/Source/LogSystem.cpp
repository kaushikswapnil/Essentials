#include "pch.h"
#include "LogSystem.h"

Logger LogSystem::m_Logger;

void LogSystem::PrintLog(const std::string& message)
{
	m_Logger.PrintLog(message);
}

void LogSystem::Configure(const std::string& fileLogName, const bool logToDebug, const bool logToConsole)
{
	m_Logger.Configure(fileLogName, logToDebug, logToConsole);
}
