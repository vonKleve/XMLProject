#pragma once

#include <utility>
#include "AbstractInterval.h"
#include "MillerRabinTest.h"

#define TESTS_AMOUNT 20

class Interval : public AbstractInterval
{
	uint low_, high_;
public:
	Interval(uint low = 0, uint high = 0) : low_(low), high_(high) { if (high < low) high_ = low; };
	Interval(std::pair<uint, uint> &p) : low_(p.first), high_(p.second) { if (high_ < low_) high_ = low_; };
	~Interval() {};

	void SetLow(uint low) override;
	void SetHigh(uint high) override;

	void GeneratePrimes(ThreadSafeSet<uint> &) override;

	uint GetLow() override;
	uint GetHigh() override;
};

