#pragma once
#include <string>

class ILogPolicy
{
public:
	virtual ~ILogPolicy() = default;

	virtual void OpenOStream(const std::string& ostreamName) = 0;
	virtual void CloseOStream() = 0;
	virtual void Write(const std::string& message) = 0;
	virtual const bool IsOStreamOpen() const = 0;
};