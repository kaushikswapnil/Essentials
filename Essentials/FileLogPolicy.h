#pragma once
#include "LogPolicy.h"
#include <fstream>

class FileLogPolicy : public ILogPolicy
{
private:
	std::ofstream outStream;
public:
	FileLogPolicy() = default;
	~FileLogPolicy() = default;

	void OpenOStream(const std::string& ostreamName);
	void CloseOStream();
	void Write(const std::string& message);

	/*void OpenOStream(const std::string& ostreamName) override;
	void CloseOStream() override;
	void Write(const std::string& message) override;*/
};

