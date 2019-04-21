#pragma once
#include "CriticalSection.h"
#include <vector>
#include <sstream>
#include <string>
#include "ILogPolicy.h"

class Logger 
{
public:
	Logger();
	~Logger();

	void PrintLog(const std::string& message);

	void Configure(const std::string& fileLogName, const bool logToDebug, const bool logToConsole);

private:
	void SafelyDeletePolicies();

	std::vector<std::unique_ptr<ILogPolicy>> m_Policies;
	CriticalSection m_Lock;
	std::stringstream m_LogStream;
};
