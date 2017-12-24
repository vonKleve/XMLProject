#pragma once

#include <fstream>
#include <string>
#include <algorithm>
#include <functional> 
#include <cctype>
#include <locale>
#include "Intervals.h"
#include "Interval.h"

#include <iostream>

using namespace std;

class XmlParser
{
	ifstream file_;
	string filename_;

	Intervals &intervals_;
public:
	XmlParser(string &xmlfile, Intervals &itrls) : filename_(xmlfile), intervals_(itrls) {};
	~XmlParser() 
	{ 
		if (file_.is_open()) 
		{
			file_.close();
		}
	};

	void LoadFile();
	void Read();
	void Parse(string &s);


	static std::string &ltrim(std::string &s) {
		s.erase(s.begin(), std::find_if(s.begin(), s.end(),
			std::not1(std::ptr_fun<int, int>(std::isspace))));
		return s;
	}

	static std::string &rtrim(std::string &s) {
		s.erase(std::find_if(s.rbegin(), s.rend(),
			std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
		return s;
	}

	static std::string &trim(std::string &s) {
		return ltrim(rtrim(s));
	}

private:
	void ChangeStatus(string &s, int &status);
};

