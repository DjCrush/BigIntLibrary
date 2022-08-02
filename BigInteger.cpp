#include "BigInteger.h"
#include <iostream>
#include <exception>


BigInteger::BigInteger() : m_sNumber("0"), m_bSignum(false) {}

BigInteger::BigInteger(const std::string& sNumber)
{
    if(sNumber.empty())
    {
        throw std::exception();
    }
    m_bSignum = sNumber[0] == '-';
    for (size_t i = m_bSignum ? 1 : 0; i < sNumber.size(); ++i)
    {
        m_sNumber += sNumber[i];
    }
}

BigInteger::BigInteger(unsigned iNumber) : m_bSignum{ false }
{
    while (iNumber)
    {
        m_sNumber = static_cast<char>((iNumber % 10) + '0') + m_sNumber;
        iNumber /= 10;
    }
    if (m_sNumber.empty())
    {
        m_sNumber = "0";
    }
}

BigInteger::BigInteger(int iNumber) : m_bSignum{ iNumber < 0 }
{
    if (m_bSignum)
    {
        iNumber = -iNumber;
    }
    while (iNumber)
    {
        m_sNumber = static_cast<char>((iNumber % 10) + '0') + m_sNumber;
        iNumber /= 10;
    }
    if (m_sNumber.empty())
    {
        m_sNumber = "0";
    }
}

BigInteger::BigInteger(uint64_t iNumber) : m_bSignum{ false }
{
    while (iNumber)
    {
        m_sNumber = static_cast<char>((iNumber % 10) + '0') + m_sNumber;
        iNumber /= 10;
    }
    if (m_sNumber.empty())
    {
        m_sNumber = "0";
    }
}

BigInteger::BigInteger(int64_t iNumber) : m_bSignum{ iNumber < 0 }
{
    if (m_bSignum)
    {
        iNumber = -iNumber;
    }
    while (iNumber)
    {
        m_sNumber = static_cast<char>((iNumber % 10) + '0') + m_sNumber;
        iNumber /= 10;
    }
    if(m_sNumber.empty())
    {
        m_sNumber = "0";
    }
}

BigInteger::BigInteger(const char* lpszNumber)
{
    if(lpszNumber[0] == 0)
    {
        throw std::exception();
    }
    m_bSignum = lpszNumber[0] == '-';
	for (size_t i = m_bSignum ? 1 : 0; lpszNumber[i] != 0; ++i)
    {
        m_sNumber += lpszNumber[i];
    }
}

BigInteger& BigInteger::operator -= (const BigInteger& rhs)
{
    if (m_bSignum && rhs.m_bSignum)
    {
        if (m_sNumber.length() == rhs.m_sNumber.length())
        {
            if (m_sNumber > rhs.m_sNumber)
            {
                m_sNumber = Subtraction(m_sNumber, rhs.m_sNumber);
                m_bSignum = true;
            }
            else
            {
                m_sNumber = Subtraction(rhs.m_sNumber, m_sNumber);
                m_bSignum = false;
            }
        }
        else if (m_sNumber.length() > rhs.m_sNumber.length())
        {
            m_sNumber = Subtraction(m_sNumber, rhs.m_sNumber);
            m_bSignum = true;
        }
        else
        {
            m_sNumber = Subtraction(rhs.m_sNumber, m_sNumber);
            m_bSignum = false;
        }
    }
    else if (!m_bSignum && rhs.m_bSignum)
    {
        m_sNumber = Addition(m_sNumber, rhs.m_sNumber);
        m_bSignum = false;
    }
    else if (m_bSignum && !rhs.m_bSignum)
    {
        m_sNumber = Addition(m_sNumber, rhs.m_sNumber);
        m_bSignum = true;
    }
    else
    {
        if (m_sNumber.length() == rhs.m_sNumber.length())
        {
            if (m_sNumber < rhs.m_sNumber)
            {
                m_sNumber = Subtraction(rhs.m_sNumber, m_sNumber);
                m_bSignum = true;
            }
            else
            {
                m_sNumber = Subtraction(m_sNumber, rhs.m_sNumber);
                m_bSignum = false;
            }
        }
        else  if (m_sNumber.length() < rhs.m_sNumber.length())
        {
            m_sNumber = Subtraction(rhs.m_sNumber, m_sNumber);
            m_bSignum = true;
        }
        else
        {
            m_sNumber = Subtraction(m_sNumber, rhs.m_sNumber);
            m_bSignum = false;
        }
    }
    if (m_sNumber == "0")
    {
        m_bSignum = false;
    }
    return *this;
}

BigInteger& BigInteger::operator += (const BigInteger& rhs)
{
    if (!m_bSignum && !rhs.m_bSignum)
    {
        m_sNumber = Addition(m_sNumber, rhs.m_sNumber);
        m_bSignum = false;
    }
    else if (m_bSignum && rhs.m_bSignum)
    {
        m_sNumber = Addition(m_sNumber, rhs.m_sNumber);
        m_bSignum = true;
    }
    else if (m_bSignum && !rhs.m_bSignum)
    {
        if (m_sNumber.length() > rhs.m_sNumber.length())
        {
            m_sNumber = Subtraction(m_sNumber, rhs.m_sNumber);
            m_bSignum = true;
        }
        else if (m_sNumber.length() < rhs.m_sNumber.length())
        {
            m_sNumber = Subtraction(rhs.m_sNumber, m_sNumber);
            m_bSignum = false;
        }
        else if (m_sNumber < rhs.m_sNumber)
        {
            m_sNumber = Subtraction(rhs.m_sNumber, m_sNumber);
            m_bSignum = false;
        }
        else
        {
            m_sNumber = Subtraction(m_sNumber, rhs.m_sNumber);
            m_bSignum = true;
        }
    }
    else if (!m_bSignum && rhs.m_bSignum)
    {
        if (m_sNumber.length() > rhs.m_sNumber.length())
        {
            m_sNumber = Subtraction(m_sNumber, rhs.m_sNumber);
            m_bSignum = false;
        }
        else if (m_sNumber.length() < rhs.m_sNumber.length())
        {
            m_sNumber = Subtraction(rhs.m_sNumber, m_sNumber);
            m_bSignum = true;
        }
        else if (m_sNumber < rhs.m_sNumber)
        {
            m_sNumber = Subtraction(rhs.m_sNumber, m_sNumber);
            m_bSignum = true;
        }
        else
        {
            m_sNumber = Subtraction(m_sNumber, rhs.m_sNumber);
            m_bSignum = false;
        }
    }
    if (m_sNumber == "0")
    {
        m_bSignum = false;
    }
    return *this;
}

BigInteger& BigInteger::operator *= (const BigInteger& rhs)
{
    m_sNumber = Multiplication(m_sNumber, rhs.m_sNumber);
    m_bSignum = m_sNumber != "0" && m_bSignum != rhs.m_bSignum;
    return *this;
}

BigInteger& BigInteger::operator /= (const BigInteger& rhs)
{
    if (rhs.m_sNumber == "0")
    {
        throw std::exception();
    }
    m_sNumber = Division(m_sNumber, rhs.m_sNumber);
    return *this;
}

BigInteger& BigInteger::operator %= (const BigInteger& rhs)
{
    if (rhs.m_sNumber == "0")
    {
        throw std::exception();
    }
    m_sNumber = Remainder(m_sNumber, rhs.m_sNumber);
    return *this;
}

BigInteger& BigInteger::operator ++ ()
{
    m_sNumber = m_bSignum ? Subtraction(m_sNumber, "1") : Addition(m_sNumber, "1");
    if (m_sNumber == "0")
    {
        m_bSignum = false;
    }
    return *this;
}

BigInteger BigInteger::operator ++ (int)
{
    BigInteger temp = *this;
    ++* this;
    return temp;
}

BigInteger& BigInteger::operator -- ()
{
    if (m_sNumber == "0")
    {
        m_bSignum = true;
    }
    m_sNumber = m_bSignum ? Addition(m_sNumber, "1") : Subtraction(m_sNumber, "1");
    return *this;
}

BigInteger BigInteger::operator -- (int)
{
    BigInteger temp = *this;
    --* this;
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
    BigInteger result;
    if (lhs.m_bSignum && rhs.m_bSignum)
    {
        if (lhs.m_sNumber.length() == rhs.m_sNumber.length())
        {
            if (lhs.m_sNumber > rhs.m_sNumber)
            {
                result.m_sNumber = BigInteger::Subtraction(lhs.m_sNumber, rhs.m_sNumber);
                result.m_bSignum = true;
            }
            else
            {
                result.m_sNumber = BigInteger::Subtraction(rhs.m_sNumber, lhs.m_sNumber);
                result.m_bSignum = false;
            }
        }
        else if (lhs.m_sNumber.length() > rhs.m_sNumber.length())
        {
            result.m_sNumber = BigInteger::Subtraction(lhs.m_sNumber, rhs.m_sNumber);
            result.m_bSignum = true;
        }
        else
        {
            result.m_sNumber = BigInteger::Subtraction(rhs.m_sNumber, lhs.m_sNumber);
            result.m_bSignum = false;
        }
    }
    else if (!lhs.m_bSignum && rhs.m_bSignum)
    {
        result.m_sNumber = BigInteger::Addition(lhs.m_sNumber, rhs.m_sNumber);
        result.m_bSignum = false;
    }
    else if (lhs.m_bSignum && !rhs.m_bSignum)
    {
        result.m_sNumber = BigInteger::Addition(lhs.m_sNumber, rhs.m_sNumber);
        result.m_bSignum = true;
    }
    else
    {
        if (lhs.m_sNumber.length() == rhs.m_sNumber.length())
        {
            if (lhs.m_sNumber < rhs.m_sNumber)
            {
                result.m_sNumber = BigInteger::Subtraction(rhs.m_sNumber, lhs.m_sNumber);
                result.m_bSignum = true;
            }
            else
            {
                result.m_sNumber = BigInteger::Subtraction(lhs.m_sNumber, rhs.m_sNumber);
                result.m_bSignum = false;
            }
        }
        else  if (lhs.m_sNumber.length() < rhs.m_sNumber.length())
        {
            result.m_sNumber = BigInteger::Subtraction(rhs.m_sNumber, lhs.m_sNumber);
            result.m_bSignum = true;
        }
        else
        {
            result.m_sNumber = BigInteger::Subtraction(lhs.m_sNumber, rhs.m_sNumber);
            result.m_bSignum = false;
        }
    }
    if (result.m_sNumber == "0")
    {
        result.m_bSignum = false;
    }
    return result;
}

BigInteger operator + (const BigInteger& lhs, const BigInteger& rhs)
{
    BigInteger result;
    if (!lhs.m_bSignum && !rhs.m_bSignum)
    {
        result.m_sNumber = BigInteger::Addition(lhs.m_sNumber, rhs.m_sNumber);
        result.m_bSignum = false;
    }
    else if (lhs.m_bSignum && rhs.m_bSignum)
    {
        result.m_sNumber = BigInteger::Addition(lhs.m_sNumber, rhs.m_sNumber);
        result.m_bSignum = true;
    }
    else if (lhs.m_bSignum && !rhs.m_bSignum)
    {
        if (lhs.m_sNumber.length() > rhs.m_sNumber.length())
        {
            result.m_sNumber = BigInteger::Subtraction(lhs.m_sNumber, rhs.m_sNumber);
            result.m_bSignum = true;
        }
        else if (lhs.m_sNumber.length() < rhs.m_sNumber.length())
        {
            result.m_sNumber = BigInteger::Subtraction(rhs.m_sNumber, lhs.m_sNumber);
            result.m_bSignum = false;
        }
        else if (lhs.m_sNumber < rhs.m_sNumber)
        {
            result.m_sNumber = BigInteger::Subtraction(rhs.m_sNumber, lhs.m_sNumber);
            result.m_bSignum = false;
        }
        else
        {
            result.m_sNumber = BigInteger::Subtraction(lhs.m_sNumber, rhs.m_sNumber);
            result.m_bSignum = true;
        }
    }
    else if (!lhs.m_bSignum && rhs.m_bSignum)
    {
        if (lhs.m_sNumber.length() > rhs.m_sNumber.length())
        {
            result.m_sNumber = BigInteger::Subtraction(lhs.m_sNumber, rhs.m_sNumber);
            result.m_bSignum = false;
        }
        else if (lhs.m_sNumber.length() < rhs.m_sNumber.length())
        {
            result.m_sNumber = BigInteger::Subtraction(rhs.m_sNumber, lhs.m_sNumber);
            result.m_bSignum = true;
        }
        else if (lhs.m_sNumber < rhs.m_sNumber)
        {
            result.m_sNumber = BigInteger::Subtraction(rhs.m_sNumber, lhs.m_sNumber);
            result.m_bSignum = true;
        }
        else
        {
            result.m_sNumber = BigInteger::Subtraction(lhs.m_sNumber, rhs.m_sNumber);
            result.m_bSignum = false;
        }
    }
    if (result.m_sNumber == "0")
    {
        result.m_bSignum = false;
    }
    return result;
}

BigInteger operator * (const BigInteger& lhs, const BigInteger& rhs)
{
    BigInteger result(BigInteger::Multiplication(lhs.m_sNumber, rhs.m_sNumber));
    if (result.m_sNumber != "0" && lhs.m_bSignum != rhs.m_bSignum)
    {
        result.m_bSignum = true;
    }
    return result;
}

BigInteger operator / (const BigInteger& lhs, const BigInteger& rhs)
{
    if(rhs.m_sNumber == "0")
    {
        throw std::exception();
    }
    BigInteger result;
    result.m_sNumber = BigInteger::Division(lhs.m_sNumber, rhs.m_sNumber);
    result.m_bSignum = lhs.m_bSignum != rhs.m_bSignum;
    return result;
}

BigInteger operator % (const BigInteger& lhs, const BigInteger& rhs)
{
    if (rhs.m_sNumber == "0")
    {
        throw std::exception();
    }
    BigInteger result;
    result.m_sNumber = BigInteger::Remainder(lhs.m_sNumber, rhs.m_sNumber);
    result.m_bSignum = lhs.m_bSignum != rhs.m_bSignum;
    return result;
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

std::string BigInteger::Addition(const std::string& lhs, const std::string& rhs)
{
    size_t iLhsLength = lhs.length();
    size_t iRhsLength = rhs.length();
    std::string sResult;
    bool bCarry = false;
    if (iLhsLength == iRhsLength)
    {
        for (size_t i = 1; i <= iLhsLength; ++i)
        {
            int iDigit = (lhs[iLhsLength - i] - '0') + (rhs[iRhsLength - i] - '0') + bCarry;
            bCarry = iDigit > 9;
            sResult += bCarry ? (iDigit - 10) + '0' : iDigit + '0';
        }
    }
    else if (iLhsLength > iRhsLength)
    {
	    for (size_t i = 1; i <= iLhsLength; ++i)
	    {
	        int iDigit = i <= iRhsLength ?
	            (lhs[iLhsLength - i] - '0') + (rhs[iRhsLength - i] - '0') + bCarry :
	            (lhs[iLhsLength - i] - '0') + bCarry;
	        bCarry = iDigit > 9;
	        sResult += bCarry ? (iDigit - 10) + '0' : iDigit + '0';
	    }
	}
    else
    {
        for (size_t i = 1; i <= iRhsLength; ++i)
        {
            int iDigit = i <= iLhsLength ?
                (lhs[iLhsLength - i] - '0') + (rhs[iRhsLength - i] - '0') + bCarry :
                (rhs[iRhsLength - i] - '0') + bCarry;
            bCarry = iDigit > 9;
            sResult += bCarry ? (iDigit - 10) + '0' : iDigit + '0';
        }
    }
    if (bCarry)
    {
        sResult += '1';
    }
    size_t length = sResult.length() >> 1;
    for (size_t i = 0; i < length; i++)
    {
        std::swap(sResult[i], sResult[sResult.length() - i - 1]);
    }
    return	sResult;
}

std::string BigInteger::Subtraction(const std::string& lhs, const std::string& rhs)
{
    std::string sResult;
    int iLhsLength = lhs.length();
    int iRhsLength = rhs.length();
    bool bCarry = false;
    if (iLhsLength >= iRhsLength)
    {
        for (int i = 1; i <= iLhsLength; ++i)
        {
            int iDigit = i <= iRhsLength ?
                (lhs[iLhsLength - i] - '0') - (rhs[iRhsLength - i] - '0') - bCarry :
                (lhs[iLhsLength - i] - '0') - bCarry;
            bCarry = iDigit < 0;
            if (bCarry)
            {
                iDigit += 10;
            }
            sResult += iDigit + '0';
        }
    }
    else
    {
        for (int i = 1; i <= iRhsLength; ++i)
        {
            int iDigit = i <= iLhsLength ?
                (lhs[iLhsLength - i] - '0') - (rhs[iRhsLength - i] - '0') - bCarry :
                (rhs[iRhsLength - i] - '0') - bCarry;
            bCarry = iDigit < 0;
            if (bCarry)
            {
                iDigit += 10;
            }
            sResult += iDigit + '0';
        }
    }
    if (sResult.length() > 1)
    {
        // remove non-significant zeros at the beginning of the number
        auto it = sResult.find_last_of("123456789");
        if (it == std::string::npos)
        {
            return "0"; // if the result consists of zeros, then we return zero
        }
        sResult.erase(sResult.begin() + it + 1, sResult.end());
    }
    size_t length = sResult.length() >> 1;
    for (size_t i = 0; i < length; ++i)
    {
        std::swap(sResult[i], sResult[sResult.length() - i - 1]);
    }
    return sResult;
}

std::string BigInteger::Multiplication(std::string lhs, const std::string& rhs)
{
    std::string sResult = "0";
    if (lhs != "0" && rhs != "0")
    {
        size_t iRhsLength = rhs.length();
        size_t iLhsLength = lhs.length();
        for (size_t j = 1; j <= iRhsLength; ++j)
        {
            int item = rhs[iRhsLength - j] - '0';
            std::string sInterimResult;
            int iCarry = 0;
            for (size_t i = 1; i <= iLhsLength; ++i)
            {
                int iDigit = (lhs[iLhsLength - i] - '0') * item + iCarry;
                sInterimResult += (iDigit % 10) + '0';
                iCarry = iDigit / 10;
            }
            if (iCarry)
            {
                sInterimResult += iCarry + '0';
            }
            sResult = Addition(sResult, sInterimResult);
            lhs += "0";
        }
    }
    size_t length = sResult.length() >> 1;
    for (size_t i = 0; i < length; ++i)
    {
        std::swap(sResult[i], sResult[sResult.length() - i - 1]);
    }
    return sResult;
}

// Division. v1.0
std::string BigInteger::Division(std::string lhs, std::string rhs)
{
    if (lhs.length() < rhs.length() || (lhs.length() == rhs.length() && lhs < rhs))
    {
        return "0";
    }
    std::string sResult = "0";
    std::string zero(lhs.length() - rhs.length(), '0');
    size_t iRhsLength = rhs.length();
    rhs += zero;
    if (lhs < rhs && rhs.length() > iRhsLength)
    {
        rhs.pop_back();
        zero.pop_back();
    }
    while (true)
    {
        if (lhs >= rhs && lhs.length() == rhs.length() || lhs.length() > rhs.length())
        {
            lhs = Subtraction(lhs, rhs);
            sResult = Addition(sResult, "1");
        }
        if ((lhs < rhs && lhs.length() == rhs.length() && iRhsLength < rhs.length()) || (lhs.length() < rhs.length() && rhs.length() > iRhsLength))
        {
            rhs.pop_back();
            zero.pop_back();
            sResult += "0";
        }
        if (lhs == "0" || (lhs.length() < rhs.length() && rhs.length() == iRhsLength) || (lhs < rhs && rhs.length() == iRhsLength && lhs.length() == rhs.length()))
        {
            break;
        }
    }
    return sResult + zero;
}

std::string BigInteger::Remainder(std::string lhs, std::string rhs)
{
    if (lhs.length() < rhs.length() || (lhs.length() == rhs.length() && lhs < rhs))
    {
        return lhs;
    }
    std::string sResult = "0";
    std::string zero(lhs.length() - rhs.length(), '0');
    size_t iRhsLength = rhs.length();
    rhs += zero;
    if (lhs < rhs && rhs.length() > iRhsLength)
    {
        rhs.pop_back();
        zero.pop_back();
    }
    while (true)
    {
        if (lhs >= rhs && lhs.length() == rhs.length() || lhs.length() > rhs.length())
        {
            lhs = Subtraction(lhs, rhs);
            sResult = Addition(sResult, "1");
        }
        if ((lhs < rhs && lhs.length() == rhs.length() && iRhsLength < rhs.length()) || (lhs.length() < rhs.length() && rhs.length() > iRhsLength))
        {
            rhs.pop_back();
            zero.pop_back();
            sResult += "0";
        }
        if (lhs == "0" || (lhs.length() < rhs.length() && rhs.length() == iRhsLength) || (lhs < rhs && rhs.length() == iRhsLength && lhs.length() == rhs.length()))
        {
            break;
        }
    }
    return lhs;
}
