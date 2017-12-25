#pragma once

#include <fstream>
#include <string>
#include <vector>
#include "Intervals.h"

typedef unsigned int uint;

class XmlWriter
{
	std::ofstream file_;
	std::string filename_;
public:
	XmlWriter(std::string filename) : filename_(filename) {};
	~XmlWriter();

	void Write(std::vector<uint> &vec);
	void Write(std::string &s);
};

