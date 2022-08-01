#pragma once
#include <string>

class BigInteger
{
public:
	BigInteger();
	BigInteger(const std::string& sNumber);
	BigInteger(unsigned iNumber);
	BigInteger(int iNumber);
	BigInteger(uint64_t iNumber);
	BigInteger(int64_t iNumber);
	BigInteger(const char* lpszNumber);

	BigInteger& operator -= (const BigInteger&);
	BigInteger& operator += (const BigInteger&);
	BigInteger& operator *= (const BigInteger&);
	BigInteger& operator /= (const BigInteger&);
	BigInteger& operator %= (const BigInteger&);

	BigInteger& operator ++ ();
	BigInteger operator ++ (int);
	BigInteger& operator -- ();
	BigInteger operator -- (int);

private:
	std::string m_sNumber;
	bool m_bSignum;
	friend std::ostream& operator << (std::ostream&, const BigInteger&);
	friend BigInteger operator + (const BigInteger&, const BigInteger&);
	friend BigInteger operator - (const BigInteger&, const BigInteger&);
	friend BigInteger operator * (const BigInteger&, const BigInteger&);
	friend BigInteger operator / (const BigInteger&, const BigInteger&);
	friend BigInteger operator % (const BigInteger&, const BigInteger&);
	friend bool operator == (const BigInteger&, const BigInteger&);
	friend bool operator != (const BigInteger&, const BigInteger&);
	friend bool operator <  (const BigInteger&, const BigInteger&);
	friend bool operator >  (const BigInteger&, const BigInteger&);
	friend bool operator <= (const BigInteger&, const BigInteger&);
	friend bool operator >= (const BigInteger&, const BigInteger&);
	static std::string Addition(const std::string&, const std::string&);
	static std::string Subtraction(const std::string&, const std::string&);
	static std::string Multiplication(std::string, const std::string&);
	static std::string Division(std::string, std::string);
	static std::string Remainder(std::string, std::string);
};
