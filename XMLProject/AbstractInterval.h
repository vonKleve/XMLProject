#pragma once

#include <utility>

typedef unsigned int uint;

class AbstractInterval
{
public:
	AbstractInterval() {};
	virtual ~AbstractInterval() {};

	virtual void SetLow(uint low) = 0;
	virtual void SetHigh(uint high) = 0;

	virtual uint GetLow() { return 0; };
	virtual uint GetHigh() { return 0; };

	virtual void GeneratePrimes() = 0;
};

