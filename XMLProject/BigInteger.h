#pragma once

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <sstream>

class BigInteger
{
private:
	std::vector<int> number;
	bool positive;
	int base;
	unsigned int skip;
	static const int default_base = 10e+8;

public:
	//Constructors
	BigInteger();
	BigInteger(long long);
	BigInteger(std::string);
	BigInteger(const BigInteger& b);

	//Adding
	BigInteger operator+(BigInteger const &) const;
	BigInteger &operator+=(BigInteger const &);
	BigInteger operator+(long long const &) const;
	BigInteger &operator+=(long long);

	//Subtraction
	BigInteger operator-(BigInteger const &) const;
	BigInteger &operator-=(BigInteger const &);

	//Multiplication
	BigInteger operator*(BigInteger const &);
	BigInteger &operator*=(BigInteger const &);
	BigInteger operator*(long long const &);
	BigInteger &operator*=(int const &);
	int operator%(int const &);

	//Compare
	bool operator<(const BigInteger &) const;
	bool operator>(const BigInteger &) const;
	bool operator<=(const BigInteger &) const;
	bool operator>=(const BigInteger &) const;
	bool operator==(const BigInteger &) const;
	bool operator!=(const BigInteger &) const;

	//Allocation
	BigInteger operator=(const long long &);

	//Access
	int operator[](int const &);

	//Input&Output
	friend std::istream &operator>>(std::istream &, BigInteger &);
	friend std::ostream &operator<<(std::ostream &, BigInteger const &);

	//Helpers
	void clear();
	BigInteger &abs();

	//Power
	BigInteger &pow(int const &);

	//Trivia
	int digits() const;
	int trailing_zeros() const;
private:
	int segment_length(int) const;
	BigInteger pow(int const &, std::map<int, BigInteger> &);
	int compare(BigInteger const &) const; //0 a == b, -1 a < b, 1 a > b
};

BigInteger abs(BigInteger);
std::string to_string(BigInteger const &);
BigInteger factorial(int);