#pragma once

#include <vector>
#include <complex>
#include <algorithm>

#define _USE_MATH_DEFINES
#include <math.h>

typedef unsigned int uint;
typedef std::complex<double> base;

class APArithmetic
{
	std::vector<uint> number_;
	static const uint digitBase_ = 10;
public:
	APArithmetic(std::vector<uint> vec) : number_(vec) {};
	APArithmetic(uint val);
	~APArithmetic() {};

	std::vector<uint> Pow(uint power);
	std::vector<uint> Multiply(APArithmetic operand);
	std::vector<uint> Multiply(uint operand);
	std::vector<uint> Divide(uint operand);
	std::vector<uint> Mod(uint operand);
	std::vector<uint> Add(APArithmetic operand);
	std::vector<uint> Subtract(APArithmetic operand);

	uint At(size_t index)
	{
		return number_.at(index);
	}

	size_t Size()
	{
		return number_.size();
	}

	std::string ToString()
	{
		std::string res;
		std::for_each(number_.begin(), number_.end(),
			[&](uint it) { res += std::to_string(it); });
		return res;
	}
};

