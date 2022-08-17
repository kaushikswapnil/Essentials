#pragma once
#include<windows.h>

class CriticalSection
{
public:
	CriticalSection();
	virtual ~CriticalSection();

	void Lock();
	void Unlock();

private:
	CRITICAL_SECTION m_cs;
};

class AutoCriticalSection : protected CriticalSection
{
public:
	AutoCriticalSection();
	~AutoCriticalSection();
};





