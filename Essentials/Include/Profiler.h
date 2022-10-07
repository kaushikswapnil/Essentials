#pragma once

#define PROFILER_ENABLED 

#ifdef PROFILER_ENABLED
#include <windows.h>
#include<iostream>

#define SCOPEDPROFILE(scope_name) ScopedProfiler __safe_scope_name_profiler__{#scope_name};

struct ScopedProfiler
{
    ScopedProfiler(const std::string name) : m_Name(name) { Start(); }
    ~ScopedProfiler() { Stop(); }

    __int64 CounterStart{};
    double PCFreq{};
    std::string m_Name{};

    inline void Start()
    {
        LARGE_INTEGER li;
        QueryPerformanceFrequency(&li);

        PCFreq = double(li.QuadPart) / 1000.0;

        QueryPerformanceCounter(&li);
        CounterStart = li.QuadPart;
    }

    inline void Stop()
    {
        std::cout << "\nProfiler " << m_Name << "recorded time of " << std::to_string(GetCounter());
    }

    inline double GetCounter() const
    {
        LARGE_INTEGER li;
        QueryPerformanceCounter(&li);
        return double(li.QuadPart - CounterStart) / PCFreq;
    }
};

#else
#define SCOPEDPROFILE(scope_name)  

#endif