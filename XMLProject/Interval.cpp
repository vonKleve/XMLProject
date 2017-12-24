#include "stdafx.h"
#include "Interval.h"


void Interval::SetLow(uint low)
{
	low_ = low;
}

void Interval::SetHigh(uint high)
{
	high_ = high;
}

void Interval::GeneratePrimes()
{
}

uint Interval::GetLow()
{
	return low_;
}

uint Interval::GetHigh()
{
	return high_;
}
