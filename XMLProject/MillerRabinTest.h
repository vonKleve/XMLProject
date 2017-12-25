#pragma once

#include <random>
#include <limits.h>
#include "BigInteger.h"

#define MIN 2

#include <iostream>

class MillerRabinTest
{
	static bool ActualTest(unsigned int n, unsigned int d)
	{
		std::mt19937 gen;
		int MAX = n - 2;
		if (MAX > 40) MAX = 10;
		std::uniform_int_distribution<int> distr(MIN, MAX);

		int a = distr(gen);
		long long x = pow(a, d);
		x = x % n;

		if (x == 1 || x == n - 1)
		{
			return true;
		}

		while (d != n - 1)
		{
			x = (x * x) % n;
			d *= 2;
			if (x == 1)
				return false;
			if (x == n - 1)
				return true;
		}
		return false;
	}
public:
	MillerRabinTest() {};
	~MillerRabinTest() {};

	static bool IsProbablePrime(unsigned int tested, const unsigned int k)
	{
		if (tested == 2 || tested == 3)
		{
			return true;
		}
		if (tested == 1 || tested % 2 == 0)
		{
			return false;
		}

		int n = tested - 1;

		int power = 1;
		int d = n / pow(2, power);
		while (d % 2 == 0 || d != n / pow(2, power - 1))
		{
			if (d == 1)
				break;
			d = n / pow(2, power++);
		}

		for (int i = 0; i < k; i++)
		{
			bool res = ActualTest(tested, d);
			if (!res)
				return false;
		}

		return true;
	}
};

