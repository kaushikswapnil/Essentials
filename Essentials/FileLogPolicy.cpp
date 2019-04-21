#include "pch.h"
#include "FileLogPolicy.h"
#include "Assertion.h"

void FileLogPolicy::OpenOStream(const std::string& ostreamName)
{
	HARDASSERT(!outStream.is_open(), "Trying to open file stream that is already open.");
	outStream.open(ostreamName, std::ios_base::out);
	CRITICAL_RUNTIME_ERROR(outStream.is_open(), "Unable to open log file for writing."); //Crash if the file is not found
}

void FileLogPolicy::CloseOStream()
{
	HARDASSERT(outStream.is_open(), "Trying to close a file that is not open.");
	outStream.close();
}
