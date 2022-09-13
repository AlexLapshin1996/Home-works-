#include "FileLogger.h"

#include<chrono>

using namespace std;

FileLogger GlobalLogger;

void __fastcall FileLogger::OpenLogFile(const string& FN)
{
	Logger.open(FN, ios_base::out);
}

void FileLogger::CloseLogFile()
{
    if (Logger.is_open())
    {
        Logger.close();
    }
}

void __fastcall FileLogger::WriteToLog(const string& str)
{
    if (Logger.is_open())
    {
        Logger << GetCurDateTime() << " - " << str << endl;
    }
}

string FileLogger::GetCurDateTime()
{
    auto cur = std::chrono::system_clock::now();
    time_t time = std::chrono::system_clock::to_time_t(cur);
    char buf[64] = { 0 };
    ctime_s(buf, 64, &time);
    buf[strlen(buf) - 1] = '\0';
    return string(buf);
}

void __fastcall FileLogger::WriteToLog(const std::string& str, int n)
{
    if (Logger.is_open())
    {
        Logger << GetCurDateTime() << " - " << str << n << endl;
    }
}

void __fastcall FileLogger::WriteToLog(const string& str, double d)
{
    if (Logger.is_open())
    {
        Logger << GetCurDateTime() << " - " << str << d << endl;
    }
}
