#pragma once
#include "ILogPolicy.h"
#include <iostream>
class ConsoleLogPolicy :
	public ILogPolicy
{
public:
	ConsoleLogPolicy();
	~ConsoleLogPolicy();

	void OpenOStream(const std::string& ostreamName) override { }
	void CloseOStream() override { }
	void Write(const std::string& message) override { std::cout << message; }
	const bool IsOStreamOpen() const override { return true; }
};

