#pragma once
#include "ILogPolicy.h"
#include <fstream>
#include "Assertion.h"

class FileLogPolicy : 
	public ILogPolicy
{
private:
	std::ofstream outStream;
public:
	FileLogPolicy() = default;
	FileLogPolicy(const std::string& ostreamName) { OpenOStream(ostreamName); }
	~FileLogPolicy() = default;

	void OpenOStream(const std::string& ostreamName) override;
	void CloseOStream() override;
	void Write(const std::string& message) override { HARDASSERT(IsOStreamOpen(), "Trying to print to FileLogPolicy with no open stream."); outStream << message << std::endl; }
	const bool IsOStreamOpen() const override { return outStream.is_open(); }
};

