#pragma once
#include "Singleton.h"
#include "Logger.h"
#include "FileLogPolicy.h"

class LogSystem
{
	DECLARE_SINGLETON_BASE_NC_ND_CC(LogSystem, , "essentials_log.txt");

public:
	Logger<FileLogPolicy>& GetLogger() { return m_Logger; }
	void PrintLog(const std::string& message) { m_Logger.PrintLog(message); }

private:
	LogSystem(const std::string& outStreamName) : m_Logger(outStreamName) { }
	~LogSystem() = default;

	Logger<FileLogPolicy> m_Logger;
};

#define LOG (LogSystem::GetInstance()).PrintLog
