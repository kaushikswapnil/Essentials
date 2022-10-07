#include "pch.h"

#ifdef _DEBUG

#include "DebugLogPolicy.h"
#include "Assertion.h"

void DebugLogPolicy::Write(const std::string& message)
{
	HARDASSERT(IsOStreamOpen(), "Trying to write to a log policy with no open stream");
	std::wstring wideString(ConvertStringToWString(message));
	OutputDebugString(wideString.c_str());
	OutputDebugString(L"\n");
}   

const bool DebugLogPolicy::IsOStreamOpen() const
{
	return IsDebuggerPresent();
}

const std::wstring DebugLogPolicy::ConvertStringToWString(const std::string& stringToConvert) const
{
	unsigned int stringLength = (unsigned int)stringToConvert.length() + 1;
	unsigned int wideStringLength = MultiByteToWideChar(CP_ACP, 0, stringToConvert.c_str(), stringLength, 0, 0);
	wchar_t* buffer = new wchar_t[wideStringLength]; //#TODO Try using simple array
	MultiByteToWideChar(CP_ACP, 0, stringToConvert.c_str(), stringLength, buffer, wideStringLength);
	std::wstring retVal(buffer);
	delete[] buffer;
	return retVal;
}

#endif // _DEBUG


