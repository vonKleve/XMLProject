#include "stdafx.h"
#include "APArithmetic.h"


APArithmetic::APArithmetic(uint val)
{
	uint temp;
	while (val != 0)
	{
		temp = val;
		val /= 10;
		val *= 10;
		number_.emplace_back(temp - val);
		val /= 10;
	}

	std::reverse(number_.begin(), number_.end());
}

std::vector<uint> APArithmetic::Pow(uint power)
{
	APArithmetic result(number_);
	while (power > 0)
	{
		result = result.Multiply(result);
		power--;
	}
	return result.number_;
}

std::vector<uint> APArithmetic::Multiply(APArithmetic operand)
{
	std::vector<uint> result(number_.size() + operand.Size());
	std::reverse(number_.begin(), number_.end());
	std::reverse(operand.number_.begin(), operand.number_.end());
	for (size_t i = 0; i< number_.size(); ++i)
		for (int j = 0, carry = 0; j<(int)operand.Size() || carry; ++j) {
			long long cur = result[i + j] + number_[i] * 1ll * (j < (int)operand.Size() ? operand.number_[j] : 0) + carry;
			result[i + j] = int(cur % digitBase_);
			carry = int(cur / digitBase_);
		}
	while (result.size() > 1 && result.back() == 0)
		result.pop_back();

	std::reverse(number_.begin(), number_.end());
	std::reverse(operand.number_.begin(), operand.number_.end());

	std::reverse(result.begin(), result.end());
	return result;
}

std::vector<uint> APArithmetic::Multiply(uint operand)
{
	std::vector<uint> res(number_);
	std::reverse(res.begin(), res.end());
	int carry = 0;
	for (size_t i = 0; i<res.size() || carry; ++i) {
		if (i == res.size())
			res.push_back(0);
		long long cur = carry + res[i] * 1ll * operand;
		res[i] = int(cur % digitBase_);
		carry = int(cur / digitBase_);
	}
	std::reverse(res.begin(), res.end());
	return res;
}

std::vector<uint> APArithmetic::Divide(uint operand)
{
	int carry = 0;
	std::vector<uint> res(number_);
	std::reverse(res.begin(), res.end());
	for (int i = (int)res.size() - 1; i >= 0; --i) {
		long long cur = res[i] + carry * 1ll * digitBase_;
		res[i] = int(cur / operand);
		carry = int(cur % operand);
	}
	std::reverse(res.begin(), res.end());
	return res;
}

#include <iostream>

std::vector<uint> APArithmetic::Mod(uint operand)
{
	APArithmetic result(number_);
	result = result.Subtract(((APArithmetic)((APArithmetic)result.Divide(operand)).Multiply(operand)));
	return result.number_;
}

std::vector<uint> APArithmetic::Add(APArithmetic operand)
{
	int carry = 0;
	std::vector<uint> result(number_);
	std::vector<uint> proxy(operand.number_);

	std::reverse(result.begin(), result.end());
	std::reverse(proxy.begin(), proxy.end());

	size_t maxSize = result.size() >= proxy.size() ? result.size() : proxy.size();
	for (size_t i = 0; i < maxSize || carry; ++i) {
		if (i == result.size())
			result.push_back(0);
		result[i] += carry + (i < proxy.size() ? proxy[i] : 0);
		carry = result[i] >= digitBase_;
		if (carry) result[i] -= digitBase_;
	}

	std::reverse(result.begin(), result.end());
	return result;
}

std::vector<uint> APArithmetic::Subtract(APArithmetic operand)
{
	int carry = 0;
	std::vector<uint> result(number_);
	for (size_t i = 0; i < operand.Size() || carry; ++i) {
		result[i] -= carry + (i < operand.Size() ? operand.number_[i] : 0);
		carry = result[i] < 0;
		if (carry) 
		 result[i] += digitBase_;
	}

	std::transform(result.begin(), result.end(), result.begin(),
		[](uint it) {if (it == UINT_MAX) return 0; return (int)it; });

	return result;
}