#pragma once
#include <string>
#include <iostream>
using namespace std;

class BigInt
{
public:
	BigInt();
	BigInt(const string& N);
	BigInt(const int& rhs);
	BigInt operator=(const BigInt& rhs);
	BigInt operator=(const int& rhs);
	BigInt operator-(const BigInt& rhs);
	BigInt operator-(const int& rhs);
	BigInt operator+(const BigInt& rhs);
	BigInt operator+(const int& rhs);
	BigInt operator*(const BigInt& rhs);
	BigInt operator*(const int& rhs);
	BigInt operator/(const BigInt& rhs);
	BigInt operator/(const int& rhs);
	BigInt operator+=(const BigInt& rhs);
	BigInt operator+=(const int& rhs);
	BigInt operator-=(const BigInt& rhs);
	BigInt operator-=(const int& rhs);

	friend ostream& operator << (ostream& os, const BigInt& rhs);
	inline bool operator < (BigInt const & rhs);
	~BigInt();
private:
	string number;
	string addition(string a, string b);
	string substraction(string a, string b);
	string division(string a, string b);
	string multiplication(string a, string b);
};