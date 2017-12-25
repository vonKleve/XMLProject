#include "stdafx.h"
#include "CppUnitTest.h"
#include "Interval.h"
#include "ESieve.h"
#include "ThreadSafeSet.h"
#include <random>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define UTESTS_AMOUNT 100

namespace IntervalTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(SetTest)
		{
			std::mt19937 gen;
			std::uniform_int_distribution<int> distr(0, INT_MAX);

			for (int i = 0; i < UTESTS_AMOUNT; i++)
			{
				int low = distr(gen), high = distr(gen);
				Interval intrl(low, high);
				Assert::IsTrue(intrl.GetLow() <= intrl.GetHigh());
			}
		}

		TEST_METHOD(TestPrimes)
		{
			std::mt19937 gen;
			std::uniform_int_distribution<int> distr(0, MAX);

			ESieve sieve;
			sieve.Generate();

				ThreadSafeSet<unsigned int> set;
				int low = distr(gen);
				int high = distr(gen);

				Interval intrl(low, high);
				intrl.GeneratePrimes(set);

				std::vector<unsigned int> svec = set.ToVector();
				for (size_t i = 0, j = 0; i < MAX; i++)
				{
					if (j == svec.size())
					{
						Assert::AreEqual(1, 1);
						return;
					}
					if (svec[j] == sieve.pr[i])
						j++;
				}
				Assert::AreEqual(0, 1);
			}
		

	};
}