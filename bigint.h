#ifndef _BIGINT_H_
#define _BIGINT_H_

#include <string>
#include <iostream>

class BigInt
{
public:
	BigInt();
	BigInt(const std::string& rhs);
	BigInt(const int rhs);
	BigInt(const char* rhs);
	BigInt& operator=(const BigInt& rhs);
	BigInt& operator-=(const BigInt&);
	BigInt& operator-=(const int&);
	BigInt& operator-=(const std::string&);
	BigInt& operator+=(const BigInt&);
	BigInt& operator+=(const int&);
	BigInt& operator+=(const std::string&);
	BigInt& operator*=(const BigInt&);
	BigInt& operator*=(const int&);
	BigInt& operator*=(const std::string&);
	BigInt& operator/=(const BigInt&);
	BigInt& operator/=(const int&);
	BigInt& operator/=(const std::string&);
	BigInt& operator%=(const BigInt&);
	BigInt& operator%=(const int&);
	BigInt& operator%=(const std::string&);
private:
	std::string number;
	friend std::ostream& operator << (std::ostream&, const BigInt&);
	friend BigInt operator+(const std::string&, const BigInt&);
	friend BigInt operator+(const BigInt&, const std::string&);
	friend BigInt operator+(const int&, const BigInt&);
	friend BigInt operator+(const BigInt&, const int&);
	friend BigInt operator+(const BigInt&, const BigInt&);
	friend BigInt operator-(const std::string&, const BigInt&);
	friend BigInt operator-(const BigInt&, const std::string&);
	friend BigInt operator-(const int&, const BigInt&);
	friend BigInt operator-(const BigInt&, const int&);
	friend BigInt operator-(const BigInt&, const BigInt&);
	friend BigInt operator*(const std::string&, const BigInt&);
	friend BigInt operator*(const BigInt&, const std::string&);
	friend BigInt operator*(const int&, const BigInt&);
	friend BigInt operator*(const BigInt&, const int&);
	friend BigInt operator*(const BigInt&, const BigInt&);
	friend BigInt operator/(const std::string&, const BigInt&);
	friend BigInt operator/(const BigInt&, const std::string&);
	friend BigInt operator/(const int&, const BigInt&);
	friend BigInt operator/(const BigInt&, const int&);
	friend BigInt operator/(const BigInt&, const BigInt&);
	friend BigInt operator%(const std::string&, const BigInt&);
	friend BigInt operator%(const BigInt&, const std::string&);
	friend BigInt operator%(const int&, const BigInt&);
	friend BigInt operator%(const BigInt&, const int&);
	friend BigInt operator%(const BigInt&, const BigInt&);
	friend bool operator==(const int&, const BigInt&);
	friend bool operator==(const BigInt&, const int&);
	friend bool operator==(const BigInt&, const std::string&);
	friend bool operator==(const std::string&, const BigInt&);
	friend bool operator==(const BigInt&, const BigInt&);
	friend bool operator!=(const int&, const BigInt&);
	friend bool operator!=(const BigInt&, const int&);
	friend bool operator!=(const BigInt&, const std::string&);
	friend bool operator!=(const std::string&, const BigInt&);
	friend bool operator!=(const BigInt&, const BigInt&);
	friend bool operator<(const int&, const BigInt&);
	friend bool operator<(const BigInt&, const int&);
	friend bool operator<(const BigInt&, const std::string&);
	friend bool operator<(const std::string&, const BigInt&);
	friend bool operator<(const BigInt&, const BigInt&);
	friend bool operator>(const int&, const BigInt&);
	friend bool operator>(const BigInt&, const int&);
	friend bool operator>(const BigInt&, const std::string&);
	friend bool operator>(const std::string&, const BigInt&);
	friend bool operator>(const BigInt&, const BigInt&);
	friend bool operator<=(const int&, const BigInt&);
	friend bool operator<=(const BigInt&, const int&);
	friend bool operator<=(const BigInt&, const std::string&);
	friend bool operator<=(const std::string&, const BigInt&);
	friend bool operator<=(const BigInt&, const BigInt&);
	friend bool operator>=(const int&, const BigInt&);
	friend bool operator>=(const BigInt&, const int&);
	friend bool operator>=(const BigInt&, const std::string&);
	friend bool operator>=(const std::string&, const BigInt&);
	friend bool operator>=(const BigInt&, const BigInt&);
	static std::string addition(std::string, std::string);
	static std::string substraction(const std::string&, const std::string&);
	static std::string division(std::string, std::string);
	static std::string multiplication(std::string, const std::string&);
	static std::string modulo(std::string, std::string);
};

#endif
