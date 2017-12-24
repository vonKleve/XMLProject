#include "stdafx.h"
#include "Intervals.h"


void Intervals::GeneratePrimes()
{
	for (auto it : intervals_)
	{
		it->GeneratePrimes();
	}
}

void Intervals::AddInterval(AbstractInterval * interval)
{
	intervals_.emplace_back(interval);
}

void Intervals::SetLow(uint low)
{
	intervals_.at(intervals_.size() - 1)->SetLow(low);
}

void Intervals::SetHigh(uint high)
{
	intervals_.at(intervals_.size() - 1)->SetHigh(high);
}

void Intervals::Set(const int index, std::pair<uint, uint> npair)
{
	intervals_.at(index)->SetLow(npair.first);
	intervals_.at(index)->SetHigh(npair.second);
}

AbstractInterval& Intervals::Get(const int index)
{
	return *intervals_.at(index);
}

size_t Intervals::GetSize()
{
	return intervals_.size();
}