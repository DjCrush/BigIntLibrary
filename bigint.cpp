#include "bigint.h"
#include <iostream>

BigInteger::BigInteger(const std::string& sNumber) : m_sNumber{sNumber }, m_bSignum{sNumber[0] == '-' }
{
	if (m_bSignum)
	{
		m_sNumber.erase(0, 1);
	}
}
BigInteger::BigInteger(int iNumber) : m_sNumber{std::to_string(iNumber) }, m_bSignum{iNumber < 0 }
{
	if (m_bSignum)
	{
		m_sNumber.erase(0, 1);
	}
}

BigInteger::BigInteger(const char* lpszNumber) : m_sNumber{lpszNumber }, m_bSignum{lpszNumber[0] == '-' }
{
	if (m_bSignum)
	{
		m_sNumber.erase(0, 1);
	}
}

BigInteger& BigInteger::operator = (const BigInteger& rhs)
{
	if (this != &rhs)
	{
        m_bSignum = rhs.m_bSignum;
        m_sNumber = rhs.m_sNumber;
	}
	return *this;
}

BigInteger& BigInteger::operator -= (const BigInteger& rhs)
{
    m_sNumber = substraction(m_sNumber, rhs.m_sNumber);
    return *this;
}

BigInteger& BigInteger::operator += (const BigInteger& rhs)
{
    m_sNumber = addition(m_sNumber, rhs.m_sNumber);
    return *this;
}

BigInteger& BigInteger::operator *= (const BigInteger& rhs)
{
    m_sNumber = multiplication(m_sNumber, rhs.m_sNumber);
    return *this;
}

BigInteger& BigInteger::operator /= (const BigInteger& rhs)
{
    m_sNumber = division(m_sNumber, rhs.m_sNumber);
    return *this;
}

BigInteger& BigInteger::operator %= (const BigInteger& rhs)
{
    m_sNumber = modulo(m_sNumber, rhs.m_sNumber);
    return *this;
}

BigInteger& BigInteger::operator ++ ()
{
    if(m_bSignum)
    {
        m_sNumber = substraction(m_sNumber, "1");
    }
    else
    {
        m_sNumber = addition(m_sNumber, "1");
    }
    if(m_sNumber == "0")
    {
        m_bSignum = false;
    }
    return *this;
}

BigInteger BigInteger::operator ++ (int)
{
    BigInteger temp = *this;
    ++*this;
    return temp;
}

BigInteger& BigInteger::operator -- ()
{
    if(m_sNumber == "0")
    {
        m_bSignum = true;
    }
    if(m_bSignum)
    {
        m_sNumber = addition(m_sNumber, "1");
    }
    else
    {
        m_sNumber = substraction(m_sNumber, "1");
    }
    return *this;
}

BigInteger BigInteger::operator -- (int)
{
    BigInteger temp = *this;
    --*this;
    return temp;
}

std::ostream& operator << (std::ostream& os, const BigInteger& rhs)
{
    if (rhs.m_bSignum)
    {
        os << '-';
    }
    os << rhs.m_sNumber;
    return os;
}

BigInteger operator - (const BigInteger& lhs, const BigInteger& rhs)
{
	return BigInteger(BigInteger::substraction(lhs.m_sNumber, rhs.m_sNumber));
}

BigInteger operator + (const BigInteger& lhs, const BigInteger& rhs)
{
	return {BigInteger::addition(lhs.m_sNumber, rhs.m_sNumber) };
}

BigInteger operator * (const BigInteger& lhs, const BigInteger& rhs)
{
	return BigInteger(BigInteger::multiplication(lhs.m_sNumber, rhs.m_sNumber));
}

BigInteger operator / (const BigInteger& lhs, const BigInteger& rhs)
{
	return BigInteger(BigInteger::division(lhs.m_sNumber, rhs.m_sNumber));
}

BigInteger operator % (const BigInteger& lhs, const BigInteger& rhs)
{
	return BigInteger(BigInteger::modulo(lhs.m_sNumber, rhs.m_sNumber));
}

bool operator == (const BigInteger& lhs, const BigInteger& rhs)
{
	if (lhs.m_bSignum != rhs.m_bSignum || lhs.m_sNumber.length() != rhs.m_sNumber.length())
	{
		return false;
	}
	return lhs.m_sNumber == rhs.m_sNumber;
}

bool operator != (const BigInteger& lhs, const BigInteger& rhs)
{
	return !(lhs == rhs);
}

bool operator < (const BigInteger& lhs, const BigInteger& rhs)
{
	if (lhs.m_bSignum && !rhs.m_bSignum)
	{
		return true;
	}
	if (!lhs.m_bSignum && rhs.m_bSignum)
	{
		return false;
	}
	if (lhs.m_bSignum && rhs.m_bSignum)
	{
		if (lhs.m_sNumber.length() > rhs.m_sNumber.length())
		{
			return true;
		}
		return (lhs.m_sNumber.length() == rhs.m_sNumber.length() && lhs.m_sNumber > rhs.m_sNumber);
	}
	if (lhs.m_sNumber.length() < rhs.m_sNumber.length())
	{
		return true;
	}
	return (lhs.m_sNumber.length() == rhs.m_sNumber.length() && lhs.m_sNumber < rhs.m_sNumber);
}

bool operator > (const BigInteger& lhs, const BigInteger& rhs)
{
	return rhs < lhs;
}

bool operator <= (const BigInteger& lhs, const BigInteger& rhs)
{
	return !(rhs < lhs);
}

bool operator >= (const BigInteger& lhs, const BigInteger& rhs)
{
	return !(lhs < rhs);
}

std::string BigInteger::addition(std::string lhs, std::string rhs)
{
	if (lhs.length() > rhs.length())
	{
		swap(lhs, rhs);
	}
	int iLhsLength = lhs.length();
	int iRhsLength = rhs.length();
    std::string sResult;
    bool bCarry = false;
	for (size_t i = 1; i <= iRhsLength; i++)
	{
        int iDigit = (iLhsLength - i) >= 0 ?
                (lhs[iLhsLength - i] - '0') + (rhs[iRhsLength - i] - '0') + bCarry :
                (rhs[iRhsLength - i] - '0') + bCarry;
        bCarry = iDigit > 9;
        sResult += bCarry ? (iDigit - 10) + '0' : iDigit + '0';
	}
	if (bCarry)
	{
        sResult += '1';
	}
	size_t length = sResult.length() >> 1;
	for (int i = 0; i < length; i++)
	{
        std::swap(sResult[i], sResult[sResult.length() - i - 1]);
	}
	return	sResult;
}

std::string BigInteger::substraction(const std::string& lhs, const std::string& rhs)
{
	std::string res;
	int iLhsLength = lhs.length();
	int iRhsLength = rhs.length();
    bool bCarry = false;
	if (iLhsLength >= iRhsLength)
	{
		for (int i = 1; i <= iLhsLength; ++i)
		{
			int iDigit = (iRhsLength - i) >= 0 ?
				(lhs[iLhsLength - i] - '0') - (rhs[iRhsLength - i] - '0') - bCarry :
				(lhs[iLhsLength - i] - '0') - bCarry;
            bCarry = iDigit < 0;
			if (bCarry)
			{
				iDigit += 10;
			}
			res += iDigit + '0';
		}
	}
	else
	{
		for (size_t i = 1; i < iRhsLength; ++i)
		{
            int iDigit = (iLhsLength - i) >= 0 ?
				(lhs[iLhsLength - i] - '0') + (rhs[iRhsLength - i] - '0') - bCarry :
				(rhs[iRhsLength - i] - '0') - bCarry;
            bCarry = iDigit < 0;
			if (bCarry)
			{
				iDigit += 10;
			}
			res += iDigit + '0';
		}
	}
	if (res.length() > 1)
	{
		auto it = res.find_last_of("123456789");
		if (it == std::string::npos)
		{
			return "0";
		}
		res.erase(res.begin() + it + 1, res.end());
	}
	size_t length = res.length() >> 1;
	for (size_t i = 0; i < length; ++i)
	{
        std::swap(res[i], res[res.length() - 1 - i]);
	}
	return	res;
}

// division. v1.0
std::string BigInteger::division(std::string a, std::string b)
{
	if (a.length() < b.length() || (a.length() == b.length() && a < b))
	{
		return "0";
	}
	std::string result = "0";
	std::string zero(a.length() - b.length(), '0');
	int b_length = b.length();
	b += zero;
	if (a < b && b.length() > b_length)
	{
		b.pop_back();
		zero.pop_back();
	}
	do
	{
		if (a >= b && a.length() == b.length() || a.length() > b.length())
		{
			a = substraction(a, b);
			result = addition(result, "1");
		}
		if ((a < b && a.length() == b.length() && b_length < b.length()) || (a.length() < b.length() && b.length() > b_length))
		{
			b.pop_back();
			zero.pop_back();
			result += "0";
		}
		if (a == "0" || (a.length() < b.length() && b.length() == b_length) || (a < b && b.length() == b_length && a.length() == b.length()))
		{
			break;
		}
	} while (true);
	return result + zero;
}

// simple version
std::string BigInteger::multiplication(std::string lhs, const std::string& rhs)
{
    std::string result = "0";
    for (int i = 1; i <= rhs.length(); ++i)
    {
        int l = rhs[rhs.length() - i];
        std::string interimResult = "0";
        for (int i1 = '0'; i1 < l; ++i1)
        {
            interimResult = addition(lhs, interimResult);
        }
        result = addition(result, interimResult);
        lhs = lhs + "0";
    }
    return	result;
}

std::string BigInteger::modulo(std::string lhs, std::string rhs)
{
	if (lhs.length() < rhs.length() || (lhs.length() == rhs.length() && lhs < rhs))
	{
		return lhs;
	}
	std::string result = "0";
	std::string zero(lhs.length() - rhs.length(), '0');
	int iRhsLength = rhs.length();
    rhs += zero;
	if (lhs < rhs && rhs.length() > iRhsLength)
	{
		rhs.pop_back();
		zero.pop_back();
	}
	do
	{
		if (lhs >= rhs && lhs.length() == rhs.length() || lhs.length() > rhs.length())
		{
            lhs = substraction(lhs, rhs);
			result = addition(result, "1");
		}
		if ((lhs < rhs && lhs.length() == rhs.length() && iRhsLength < rhs.length()) || (lhs.length() < rhs.length() && rhs.length() > iRhsLength))
		{
			rhs.pop_back();
			zero.pop_back();
			result += "0";
		}
		if (lhs == "0" || (lhs.length() < rhs.length() && rhs.length() == iRhsLength) || (lhs < rhs && rhs.length() == iRhsLength && lhs.length() == rhs.length()))
		{
			break;
		}
	} while (true);
	return lhs;
}
