#pragma once

#include<string>
#include<fstream>
#include<iostream>

class FileLogger
{
public:
	FileLogger() { OpenLogFile("log.txt"); }

	void __fastcall OpenLogFile(const std::string& FN);

	~FileLogger() { CloseLogFile(); }

	void CloseLogFile();

	std::string GetCurDateTime();

	void __fastcall WriteToLog(const std::string& str);

	void __fastcall WriteToLog(const std::string& str, int n);

	void __fastcall WriteToLog(const std::string& str, double d);
private:
	std::fstream Logger;
};

