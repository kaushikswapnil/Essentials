#include "pch.h"
#include "LogSystem.h"

Logger<FileLogPolicy> LogSystem::m_Logger("essentials_log.txt");

void LogSystem::PrintLog(const std::string& message)
{
	m_Logger.PrintLog(message);
}
