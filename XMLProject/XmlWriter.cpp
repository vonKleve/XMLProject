#include "stdafx.h"
#include "XmlWriter.h"


XmlWriter::~XmlWriter()
{
	file_.close();
}

void XmlWriter::Write(std::vector<uint>& vec)
{
	file_.open(filename_, std::ofstream::out, std::ofstream::trunc);
	if (!file_.is_open())
	{
		return;
	}

	file_ << "<root>\n";
	file_ << "\t<primes> ";
	for (auto it : vec)
	{
		file_ << it << " ";
	}
	file_ << "</primes>\n";
	file_ << "</root>";

	file_.close();
}
