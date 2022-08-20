#include<iostream>
#include<fstream>
#include<chrono>

#include"FileLoggerSingletone.h"
#include"LoggerSingleton.h"

ofstream logOut;

ProxyLoggerSingleton::ProxyLoggerSingleton(Singleton *SingProxy) :SingProxy_memb(SingProxy){}

string GetCurDateTime()
{
    auto cur = std::chrono::system_clock::now();
    time_t time = std::chrono::system_clock::to_time_t(cur);
    char buf[64] = { 0 };
    ctime_s(buf, 64, &time);
    buf[strlen(buf) - 1] = '\0';
    return string(buf);
}

void __fastcall ProxyLoggerSingleton::WriteToLog(const string& str)
{
    if (SingProxy_memb != nullptr)
    {
        if (logOut.is_open())
        {
            logOut << count++ << GetCurDateTime() << " - " << str << endl;
        }
    }
}

void __fastcall ProxyLoggerSingleton::WriteToLog(const string& str, int n)
{
    if (SingProxy_memb != nullptr)
    {
        if (logOut.is_open())
        {
            logOut << count++ << GetCurDateTime() << " - " << str << endl;
        }
    }
}


void __fastcall ProxyLoggerSingleton::WriteToLog(const string& str, double d)
{
    if (SingProxy_memb != nullptr)
    {
        if (logOut.is_open())
        {
            logOut << count++ << GetCurDateTime() << " - " << str << endl;
        }
    }
}