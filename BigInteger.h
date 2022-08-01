#pragma once
#include <string>

class BigInteger
{
public:
	BigInteger();
	BigInteger(const std::string& sNumber);
	BigInteger(int iNumber);
	BigInteger(const char* lpszNumber);

	BigInteger& operator -= (const BigInteger& rhs);
	BigInteger& operator += (const BigInteger& rhs);
	BigInteger& operator *= (const BigInteger& rhs);
	BigInteger& operator /= (const BigInteger& rhs);
	BigInteger& operator %= (const BigInteger& rhs);

	BigInteger& operator ++ ();
	BigInteger operator ++ (int);
	BigInteger& operator -- ();
	BigInteger operator -- (int);

private:
	std::string m_sNumber;
	bool m_bSignum;
	friend std::ostream& operator << (std::ostream& lhs, const BigInteger& rhs);
	friend BigInteger operator + (const BigInteger& lhs, const BigInteger& rhs);
	friend BigInteger operator - (const BigInteger& lhs, const BigInteger& rhs);
	friend BigInteger operator * (const BigInteger& lhs, const BigInteger& rhs);
	friend BigInteger operator / (const BigInteger& lhs, const BigInteger& rhs);
	friend BigInteger operator % (const BigInteger& lhs, const BigInteger& rhs);
	friend bool operator == (const BigInteger& lhs, const BigInteger& rhs);
	friend bool operator != (const BigInteger& lhs, const BigInteger& rhs);
	friend bool operator <  (const BigInteger& lhs, const BigInteger& rhs);
	friend bool operator >  (const BigInteger& lhs, const BigInteger& rhs);
	friend bool operator <= (const BigInteger& lhs, const BigInteger& rhs);
	friend bool operator >= (const BigInteger& lhs, const BigInteger& rhs);
	static std::string Addition(const std::string& lhs, const std::string& rhs);
	static std::string Subtraction(const std::string& lhs, const std::string& rhs);
	static std::string Multiplication(std::string lhs, const std::string& rhs);
	static std::string Division(std::string lhs, std::string rhs);
	static std::string Remainder(std::string lhs, std::string rhs);
};
