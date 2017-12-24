#include "stdafx.h"
#include "XmlParser.h"


void XmlParser::LoadFile()
{
	if (file_.is_open())
	{
		return;
	}

	file_.open(filename_, ifstream::in);
}

void XmlParser::Read()
{
	if(!file_.is_open())
	{
		return;
	}

	string stemp;
	while (getline(file_, stemp))
	{
		trim(stemp);
		size_t pos = stemp.find_first_of('>') + 1;

		if (stemp.length() == pos)
		{
			Parse(stemp);
		}
		else
		{
			string part = stemp.substr(0, pos);
			Parse(part);

			size_t pos2 = stemp.find_last_of('<');
			part = stemp.substr(pos, pos2 - pos);
			Parse(part);

			if (pos2 != 0)
			{
				part = stemp.substr(pos2);
				Parse(part);
			}
		}
	}
}

void XmlParser::Parse(string & s)
{
	trim(s);
	if (s == "")
	{
		return;
	}

	static int status = 0;
	string temp = s;
	if (s[0] == '<')
	{
		temp = s.substr(1, s.length() - 2);
		trim(temp);

		ChangeStatus(temp, status);

		if (status == 1)
		{
			intervals_.AddInterval(new Interval());
		}
	}
	else
	{
		switch (status)
		{
		case 2:
			intervals_.SetLow(stoi(temp));
			break;
		case 3:
			intervals_.SetHigh(stoi(temp));
			break;
		default:
			break;
		}
	}
}

void XmlParser::ChangeStatus(string & s, int & status)
{
	if (s == "interval")
	{
		status = 1;
	}
	else if (s == "low")
	{
		status = 2;
	}
	else if (s == "high")
	{
		status = 3;
	}
	else
	{
		status = 0;
	}
}