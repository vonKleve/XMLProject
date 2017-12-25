#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\XMLProject\BigInteger.h"
#include <random>
#include <limits.h>
#include <string>
#include <utility>
#include <functional>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define UTESTS_AMOUNT 100
#define MAX 999999999

//typedef unsigned long long ull;

namespace BigIntegerTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(MultiplicationTest)
		{
			std::mt19937 gen;
			std::uniform_int_distribution<int> distr(0, MAX);

			for (int i = 0; i < UTESTS_AMOUNT; i++)
			{
				unsigned long long ulla = distr(gen),
					ullb = distr(gen);

				BigInteger ba = ulla,
					bb = ullb;
				BigInteger bc = ba * bb;	
				unsigned long long ullc = ulla * ullb;
				Assert::AreEqual(bc.ToString(), std::to_string(ullc));

				ba = ulla;
				ba *= bb;				
				Assert::AreEqual(ba.ToString(), bc.ToString());

				ba = ulla;
				ba *= ullb;				
				Assert::AreEqual(ba.ToString(), std::to_string(ullc));

				ba = ulla;
				ba = ba * ullb;				
				Assert::AreEqual(ba.ToString(), std::to_string(ullc));
			}
		}

		TEST_METHOD(ModTest)
		{
			std::mt19937 gen;
			std::uniform_int_distribution<int> distr(0, MAX);

			for (int i = 0; i < UTESTS_AMOUNT; i++)
			{
				unsigned long long ulla = distr(gen),
					ullb = distr(gen);

				BigInteger ba = ulla;

				unsigned long long ullc = ulla % ullb;
				ba = ba % ullb;

				Assert::AreEqual(ba.ToString(), std::to_string(ullc));
			}
		}

		TEST_METHOD(AddTest)
		{
			std::mt19937 gen;
			std::uniform_int_distribution<int> distr(0, MAX);

			for (int i = 0; i < UTESTS_AMOUNT; i++)
			{
				unsigned long long ulla = distr(gen),
					ullb = distr(gen);

				BigInteger ba = ulla,
					bb = ullb;

				BigInteger bc = ba + bb;
				unsigned long long ullc = ulla + ullb;

				std::string sullc = std::to_string(ullc);
				Assert::AreEqual(bc.ToString(), sullc);

				ba += bb;
				Assert::AreEqual(ba.ToString(), sullc);

				ba = ulla;
				ba += ullb;
				Assert::AreEqual(ba.ToString(), sullc);

				ba = ulla;
				ba = ba + ullb;
				Assert::AreEqual(ba.ToString(), sullc);
			}
		}

		//TEST_METHOD(SubtractTest)
		//{
		//	std::mt19937 gen;
		//	std::uniform_int_distribution<int> distr(0, MAX);
		//	for (int i = 0; i < UTESTS_AMOUNT; i++)
		//	{
		//		unsigned long long ulla = distr(gen),
		//			ullb = distr(gen);
		//		BigInteger ba = ulla,
		//			bb = ullb;
		//		BigInteger bc = ba - bb;
		//	//	ba -= bb;
		//		unsigned long long ullc = ulla - ullb;
		//	//	Assert::AreEqual(bc.ToString(), ba.ToString());
		//		Assert::AreEqual(bc.ToString(), std::to_string(ullc));
		//	}
		//}

		//std::pair<unsigned long long, BigInteger> doIt(ull & ulla, ull & ullb,
		//	BigInteger & ba, BigInteger & bb,
		//	std::mt19937 &gen, std::uniform_int_distribution<int> &distr,
		//	std::function<ull(ull, ull)> ullf, std::function<BigInteger(BigInteger, BigInteger)> bif)
		//{
		//	ulla = distr(gen);
		//	ullb = distr(gen);
		//	ba = ulla;
		//	bb = ullb;
		//	return std::pair<ull, BigInteger>(ullf(ulla, ullb), bif(ba, bb));
		//}

		TEST_METHOD(ToStringTest)
		{
			std::mt19937 gen;
			std::uniform_int_distribution<int> distr(0, MAX);

			for (int i = 0; i < UTESTS_AMOUNT; i++)
			{
				unsigned long long ulla = distr(gen);
				BigInteger ba = ulla;

				Assert::AreEqual(ba.ToString(), std::to_string(ulla));
			}
		}

		TEST_METHOD(AbsTest)
		{
			std::mt19937 gen;
			std::uniform_int_distribution<int> distr(-MAX, MAX);

			for (int i = 0; i < UTESTS_AMOUNT; i++)
			{
				long long ulla = distr(gen);

				BigInteger ba = ulla;
				ba = ba.abs();

				ulla = std::abs(ulla);
				Assert::AreEqual(std::to_string(ulla), ba.ToString());
			}
		}

		TEST_METHOD(PowTest)
		{
			std::mt19937 gen;
			std::uniform_int_distribution<int> distr(0, 100);
			std::uniform_int_distribution<int> distr2(0, 5);

			for (int i = 0; i < UTESTS_AMOUNT; i++)
			{
				unsigned long long ulla = distr(gen);
				int power = distr2(gen);
				BigInteger ba = ulla;
				ba = ba.pow(power);

				ulla = std::pow(ulla, power);

				Assert::AreEqual(ba.ToString(), std::to_string(ulla));
			}
		}

		TEST_METHOD(MoreLessTest)
		{
			std::mt19937 gen;
			std::uniform_int_distribution<int> distr(-MAX, MAX);

			for (int i = 0; i < UTESTS_AMOUNT; i++)
			{
				long long ulla = distr(gen),
					ullb = distr(gen);

				BigInteger ba = ulla,
					bb = ullb;

				bool ullflag = ulla > ullb;
				bool biflag = ba > bb;
				Assert::AreEqual(ullflag, biflag);

				ullflag = ulla < ullb;
				biflag = ba < bb;
				Assert::AreEqual(ullflag, biflag);

				ullflag = ulla >= ullb;
				biflag = ba >= bb;
				Assert::AreEqual(ullflag, biflag);

				ullflag = ulla <= ullb;
				biflag = ba <= bb;
				Assert::AreEqual(ullflag, biflag);

				ullflag = ulla == ullb;
				biflag = ba == bb;
				Assert::AreEqual(ullflag, biflag);

				ullflag = ulla != ullb;
				biflag = ba != bb;
				Assert::AreEqual(ullflag, biflag);
			}
		}
	};
}