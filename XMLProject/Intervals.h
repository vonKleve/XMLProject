#pragma once

#include <vector>
#include <utility>
#include "AbstractInterval.h"

class Intervals : public AbstractInterval
{
	std::vector<AbstractInterval *> intervals_;
public:
	Intervals() {};
	~Intervals() {};

	void SetLow(uint low) override;
	void SetHigh(uint high) override;

	void GeneratePrimes() override;

	void AddInterval(AbstractInterval *interval);

	void Set(int index, std::pair<uint, uint> npair);
	AbstractInterval& Get(const int index);

	size_t GetSize();
};

