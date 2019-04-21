#include "Logger.h"
#include "pch.h"
#include "Assertion.h"
#include "FileLogPolicy.h"
#include "DebugLogPolicy.h"
#include "ConsoleLogPolicy.h"

Logger::Logger()
{
	//Initialize to default;
	const bool writeToConsole = true;
	const bool writeToDebug = true;
	Configure("essentials-log.txt", writeToDebug, writeToConsole);
}

Logger::~Logger()
{
	SafelyDeletePolicies();
}

void Logger::PrintLog(const std::string& message)
{
	m_Lock.Lock();

	for (auto& policy : m_Policies)
	{
		HARDASSERT(policy->IsOStreamOpen(), "Trying to write to a logging policy that does not have an open stream.");
		policy->Write(message);
	}

	m_Lock.Unlock();
}

void Logger::Configure(const std::string& fileLogName, const bool logToDebug, const bool logToConsole)
{
	SafelyDeletePolicies();

	//#TODO Write better, agnostic log policy code
	m_Policies.push_back(std::make_unique<FileLogPolicy>(fileLogName));

#ifdef _DEBUG
	if (logToDebug)
	{
		m_Policies.push_back(std::make_unique<DebugLogPolicy>());
	}
#endif // _DEBUG

	if (logToConsole)
	{
		m_Policies.push_back(std::make_unique<ConsoleLogPolicy>());
	}
}

void Logger::SafelyDeletePolicies()
{
	for (auto& policy : m_Policies)
	{
		policy->CloseOStream();
	}

	m_Policies.clear();
}
