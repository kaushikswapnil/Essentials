#pragma once

//#ifdef _DEBUG

#include "ILogPolicy.h"

class DebugLogPolicy :
	public ILogPolicy
{
public:
	DebugLogPolicy() = default;
	~DebugLogPolicy() = default;

	void OpenOStream(const std::string& ostreamName) override { }
	void CloseOStream() override { }
	void Write(const std::string& message) override { }
	const bool IsOStreamOpen() const override { return IsDebuggerPresent(); }
};

//#endif // _DEBUG