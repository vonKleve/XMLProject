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

void Interval::GeneratePrimes(ThreadSafeSet<uint> & set)
{
	MillerRabinTest prTest;
	for (uint i = low_; i < high_; i++)
	{
		if (prTest.IsProbablePrime(i, TESTS_AMOUNT))
		{
			set.Insert(i);
		}
	}
}

uint Interval::GetLow()
{
	return low_;
}

uint Interval::GetHigh()
{
	return high_;
}
