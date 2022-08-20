#pragma once

#include<string>

class Singleton
{
public:
	static Singleton& GetInstance()
	{
		static Singleton Instance;
		return Instance;
	}

	void __fastcall OpenLogFile(const std::string& FN);

	void CloseLogFile();

	void __fastcall WriteToLog(const std::string& str);

	void __fastcall WriteToLog(const std::string& str, int n);

	void __fastcall WriteToLog(const std::string& str, double d);

private:
	Singleton() {};
	Singleton(const Singleton&) =delete;
	Singleton& operator =(const Singleton&) = delete;
};