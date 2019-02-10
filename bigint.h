#pragma once
#include <string>
#include <iostream>
using namespace std;

class BigInt
{
public:
	BigInt(const string&);
	BigInt(const int&);
	BigInt& operator=(const BigInt&);
	BigInt& operator=(const int&);
	BigInt& operator-=(const BigInt&);
	BigInt& operator-=(const int&);
	BigInt& operator-=(const string&);
	BigInt& operator+=(const BigInt&);
	BigInt& operator+=(const int&);
	BigInt& operator+=(const string&);
	BigInt& operator*=(const BigInt&);
	BigInt& operator*=(const int&);
	BigInt& operator*=(const string&);
	BigInt& operator/=(const BigInt&);
	BigInt& operator/=(const int&);
	BigInt& operator/=(const string&);
	BigInt& operator%=(const BigInt&);
	BigInt& operator%=(const int&);
	BigInt& operator%=(const string&);

private:
	string number;
	friend ostream& operator << (ostream&, const BigInt&);
	friend BigInt operator+(const string&, const BigInt&);
	friend BigInt operator+(const BigInt&, const string&);
	friend BigInt operator+(const int&, const BigInt&);
	friend BigInt operator+(const BigInt&, const int&);
	friend BigInt operator+(const BigInt&, const BigInt&);
	friend BigInt operator-(const string&, const BigInt&);
	friend BigInt operator-(const BigInt&, const string&);
	friend BigInt operator-(const int&, const BigInt&);
	friend BigInt operator-(const BigInt&, const int&);
	friend BigInt operator-(const BigInt&, const BigInt&);
	friend BigInt operator*(const string&, const BigInt&);
	friend BigInt operator*(const BigInt&, const string&);
	friend BigInt operator*(const int&, const BigInt&);
	friend BigInt operator*(const BigInt&, const int&);
	friend BigInt operator*(const BigInt&, const BigInt&);
	friend BigInt operator/(const string&, const BigInt&);
	friend BigInt operator/(const BigInt&, const string&);
	friend BigInt operator/(const int&, const BigInt&);
	friend BigInt operator/(const BigInt&, const int&);
	friend BigInt operator/(const BigInt&, const BigInt&);
	friend BigInt operator%(const string&, const BigInt&);
	friend BigInt operator%(const BigInt&, const string&);
	friend BigInt operator%(const int&, const BigInt&);
	friend BigInt operator%(const BigInt&, const int&);
	friend BigInt operator%(const BigInt&, const BigInt&);
	friend bool operator!=(const int&, const BigInt&);
	friend bool operator!=(const BigInt&, const int&);
	friend bool operator!=(const BigInt&, const string&);
	friend bool operator!=(const string&, const BigInt&);
	friend bool operator!=(const BigInt&, const BigInt&);
	friend bool operator<(const int&, const BigInt&);
	friend bool operator<(const BigInt&, const int&);
	friend bool operator<(const BigInt&, const string&);
	friend bool operator<(const string&, const BigInt&);
	friend bool operator<(const BigInt&, const BigInt&);
	friend bool operator<=(const int&, const BigInt&);
	friend bool operator<=(const BigInt&, const int&);
	friend bool operator<=(const BigInt&, const string&);
	friend bool operator<=(const string&, const BigInt&);
	friend bool operator<=(const BigInt&, const BigInt&);
	friend bool operator>(const int&, const BigInt&);
	friend bool operator>(const BigInt&, const int&);
	friend bool operator>(const BigInt&, const string&);
	friend bool operator>(const string&, const BigInt&);
	friend bool operator>(const BigInt&, const BigInt&);
	friend bool operator>=(const int&, const BigInt&);
	friend bool operator>=(const BigInt&, const int&);
	friend bool operator>=(const BigInt&, const string&);
	friend bool operator>=(const string&, const BigInt&);
	friend bool operator>=(const BigInt&, const BigInt&);
	friend bool operator==(const int&, const BigInt&);
	friend bool operator==(const BigInt&, const int&);
	friend bool operator==(const BigInt&, const string&);
	friend bool operator==(const string&, const BigInt&);
	friend bool operator==(const BigInt&, const BigInt&);
	static string addition(string, string);
	static string substraction(const string&, const string&);
	static string division(string, string);
	static string multiplication(string, const string&);
	static string modulo(string, string);
};