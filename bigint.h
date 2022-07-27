#pragma once
#include <string>

class BigInteger
{
public:
	BigInteger(const std::string& sNumber = "0");
	BigInteger(int iNumber);
	BigInteger(const char* lpszNumber);
	BigInteger& operator = (const BigInteger&);

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
	friend bool operator < (const BigInteger&, const BigInteger&);
	friend bool operator > (const BigInteger&, const BigInteger&);
	friend bool operator <= (const BigInteger&, const BigInteger&);
	friend bool operator >= (const BigInteger&, const BigInteger&);
	static std::string addition(std::string, std::string);
	static std::string substraction(const std::string&, const std::string&);
	static std::string division(std::string, std::string);
	static std::string multiplication(std::string, const std::string&);
	static std::string modulo(std::string, std::string);
};