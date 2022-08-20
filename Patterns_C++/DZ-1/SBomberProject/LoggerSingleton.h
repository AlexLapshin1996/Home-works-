#pragma once
#include<string>
#include"FileLoggerSingletone.h"

using namespace std;

class ProxyLoggerSingleton 
{
public:
	ProxyLoggerSingleton(Singleton *SingProxy);
	void __fastcall WriteToLog(const string& str);
	void __fastcall WriteToLog(const string& str, int n);
	void __fastcall WriteToLog(const string& str, double d);
	string GetCurDateTime();
private:
	Singleton *SingProxy_memb = nullptr;
	int count = 1;
};

