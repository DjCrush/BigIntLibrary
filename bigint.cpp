#include "bigint.h"

BigInt::BigInt(const std::string& N = "0") : number{ N }, signum{ N[0] == '-' ? true : false }
{
	if (signum == true)
	{
		number.erase(0, 1);
	}
}
BigInt::BigInt(const int& N) : number{ std::to_string(N) }, signum{ N < 0 ? true : false }
{
	if (signum == true)
	{
		number.erase(0, 1);
	}
}
BigInt::BigInt(const char* N) : number{ N }, signum{ N[0] == '-' ? true : false }
{
	if (signum == true)
	{
		number.erase(0, 1);
	}
}
BigInt& BigInt::operator=(const int& rhs)
{
	signum = (rhs < 0 ? true : false);
	number = std::to_string(rhs);
	return *this;
}
BigInt& BigInt::operator=(const BigInt& rhs)
{
	if (this != &rhs)
	{
		signum = rhs.signum;
		number = rhs.number;
	}
	return *this;
}

BigInt operator-(const std::string& lhs, const BigInt& rhs)
{
	if (lhs[0] == '-' && rhs.signum == false)
	{

	}
	return { BigInt::substraction(lhs, rhs.number) };
}

BigInt operator-(const BigInt& lhs, const std::string& rhs)
{
	return { BigInt::substraction(lhs.number, rhs) };
}

BigInt operator-(const int& lhs, const BigInt& rhs)
{
	return { std::to_string(lhs) - rhs };
}

BigInt operator-(const BigInt& lhs, const int& rhs)
{
	return BigInt(BigInt::substraction(lhs.number, std::to_string(rhs)));
}

BigInt operator-(const BigInt& lhs, const BigInt& rhs)
{
	return BigInt(BigInt::substraction(lhs.number, rhs.number));
}

BigInt& BigInt::operator-=(const BigInt& rhs)
{
	number = substraction(number, rhs.number);
	return *this;
}

BigInt& BigInt::operator-=(const int& rhs)
{
	number = substraction(number, std::to_string(rhs));
	return *this;
}

BigInt& BigInt::operator-=(const std::string& rhs)
{
	number = substraction(number, rhs);
	return *this;
}

BigInt operator+(const std::string& lhs, const BigInt& rhs)
{
	return { BigInt::addition(lhs, rhs.number) };
}

BigInt operator+(const BigInt& lhs, const std::string& rhs)
{
	return { rhs + lhs };
}

BigInt operator+(const int& lhs, const BigInt& rhs)
{
	return { BigInt::addition(std::to_string(lhs), rhs.number) };
}

BigInt operator+(const BigInt& lhs, const int& rhs)
{
	return { rhs + lhs };
}

BigInt operator+(const BigInt& lhs, const BigInt& rhs)
{
	return { BigInt::addition(lhs.number, rhs.number) };
}

BigInt& BigInt::operator+=(const BigInt& rhs)
{
	number = addition(number, rhs.number);
	return *this;
}

BigInt& BigInt::operator+=(const int& rhs)
{
	number = addition(number, std::to_string(rhs));
	return *this;
}

BigInt& BigInt::operator+=(const std::string& rhs)
{
	number = addition(number, rhs);
	return *this;
}

BigInt operator*(const std::string& lhs, const BigInt& rhs)
{
	return { BigInt::multiplication(lhs, rhs.number) };
}

BigInt operator*(const BigInt& lhs, const std::string& rhs)
{
	return { rhs * lhs };
}

BigInt operator*(const int& lhs, const BigInt& rhs)
{
	return { BigInt::multiplication(std::to_string(lhs), rhs.number) };
}

BigInt operator*(const BigInt& lhs, const int& rhs)
{
	return { rhs * lhs };
}

BigInt operator*(const BigInt& lhs, const BigInt& rhs)
{
	return BigInt(BigInt::multiplication(lhs.number, rhs.number));
}

BigInt& BigInt::operator*=(const BigInt& rhs)
{
	number = multiplication(number, rhs.number);
	return *this;
}

BigInt& BigInt::operator*=(const int& rhs)
{
	number = multiplication(number, std::to_string(rhs));
	return *this;
}

BigInt& BigInt::operator*=(const std::string& rhs)
{
	number = multiplication(number, rhs);
	return *this;
}

BigInt operator/(const std::string& lhs, const BigInt& rhs)
{
	return BigInt(BigInt::division(lhs, rhs.number));
}

BigInt operator/(const BigInt& lhs, const std::string& rhs)
{
	return BigInt(BigInt::division(lhs.number, rhs));
}

BigInt operator/(const int& lhs, const BigInt& rhs)
{
	return BigInt(BigInt::division(std::to_string(lhs), rhs.number));
}

BigInt operator/(const BigInt& lhs, const int& rhs)
{
	return BigInt(BigInt::division(lhs.number, std::to_string(rhs)));
}

BigInt operator/(const BigInt& lhs, const BigInt& rhs)
{
	return BigInt(BigInt::division(lhs.number, rhs.number));
}

BigInt& BigInt::operator/=(const BigInt& rhs)
{
	number = division(number, rhs.number);
	return *this;
}

BigInt& BigInt::operator/=(const int& rhs)
{
	number = division(number, std::to_string(rhs));
	return *this;
}

BigInt& BigInt::operator/=(const std::string& rhs)
{
	number = division(number, rhs);
	return *this;
}

BigInt operator%(const std::string& lhs, const BigInt& rhs)
{
	return BigInt(BigInt::modulo(lhs, rhs.number));
}

BigInt operator%(const BigInt& lhs, const std::string& rhs)
{
	return BigInt(BigInt::modulo(lhs.number, rhs));
}

BigInt operator%(const int& lhs, const BigInt& rhs)
{
	return BigInt(BigInt::modulo(std::to_string(lhs), rhs.number));
}

BigInt operator%(const BigInt& lhs, const int& rhs)
{
	return BigInt(BigInt::modulo(lhs.number, std::to_string(rhs)));
}

BigInt operator%(const BigInt& lhs, const BigInt& rhs)
{
	return BigInt(BigInt::modulo(lhs.number, rhs.number));
}

BigInt& BigInt::operator%=(const BigInt& rhs)
{
	number = modulo(number, rhs.number);
	return *this;
}

BigInt& BigInt::operator%=(const int& rhs)
{
	number = modulo(number, std::to_string(rhs));
	return *this;
}

BigInt& BigInt::operator%=(const std::string& rhs)
{
	number = modulo(number, rhs);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const BigInt& rhs)
{
	if (rhs.signum == true)
	{
		os << '-';
	}
	os << rhs.number;
	return os;
}

bool operator==(const int& lhs, const BigInt& rhs)
{
	if (lhs < 0 && rhs.signum != true || lhs > 0 && rhs.signum != false) // if first negative and second positive or first positive and second negative
	{
		return false;
	}
	return std::to_string(lhs) == rhs.number;
}

bool operator==(const BigInt& lhs, const int& rhs)
{
	return rhs == lhs;
}

bool operator==(const BigInt& lhs, const std::string& rhs)
{
	if (lhs.signum == true && rhs[0] != '0' || lhs.signum == false && rhs[0] == '0') // if first negative and second positive or first positive and second negative
	{
		return false;
	}
	if (lhs.number.length() != rhs.length())
	{
		return false;
	}
	return lhs.number == rhs;
}

bool operator==(const std::string& lhs, const BigInt& rhs)
{
	return rhs == lhs;
}

bool operator==(const BigInt& lhs, const BigInt& rhs)
{
	if (lhs.signum == true && rhs.signum == false || lhs.signum == false && rhs.signum == true) // if first negative and second positive or first positive and second negative
	{
		return false;
	}
	if (lhs.number.length() != rhs.number.length())
	{
		return false;
	}
	return lhs.number == rhs.number;
}

bool operator!=(const int& lhs, const BigInt& rhs)
{
	return !(lhs == rhs);
}

bool operator!=(const BigInt& lhs, const int& rhs)
{
	return !(lhs == rhs);
}

bool operator!=(const BigInt& lhs, const std::string& rhs)
{
	return !(lhs == rhs);
}

bool operator!=(const std::string& lhs, const BigInt& rhs)
{
	return !(lhs == rhs);
}

bool operator!=(const BigInt& lhs, const BigInt& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const int& lhs, const BigInt& rhs)
{
	if (lhs < 0 && rhs.signum == false)
	{
		return true;
	}
	std::string t = std::to_string(lhs);
	if (lhs < 0)
	{
		t.erase(0, 1);
		if (t.length() < rhs.number.length())
		{
			return true;
		}
		return (t.length() == rhs.number.length() && t > rhs.number);
	}
	if (t.length() < rhs.number.length())
	{
		return true;
	}
	return (t.length() == rhs.number.length() && t < rhs.number);
}

bool operator<(const BigInt& lhs, const int& rhs)
{
	return !(rhs < lhs);
}

bool operator<(const BigInt& lhs, const std::string& rhs)
{
	if (lhs.number.length() < rhs.length())
	{
		return true;
	}
	return (lhs.number.length() == rhs.length() && lhs.number < rhs);
}

bool operator<(const std::string& lhs, const BigInt& rhs)
{
	return !(rhs < lhs);
}

bool operator<(const BigInt& lhs, const BigInt& rhs)
{
	if (lhs.signum == true && rhs.signum == false)
	{
		return true;
	}
	if (lhs.signum == false && rhs.signum == true)
	{
		return false;
	}
	if (lhs.signum == true && rhs.signum == true)
	{
		if (lhs.number.length() > rhs.number.length())
		{
			return true;
		}
		return (lhs.number.length() == rhs.number.length() && lhs.number > rhs.number);
	}
	if (lhs.number.length() < rhs.number.length())
	{
		return true;
	}
	return (lhs.number.length() == rhs.number.length() && lhs.number < rhs.number);
}

bool operator>(const int& lhs, const BigInt& rhs)
{
	return rhs < lhs;
}

bool operator>(const BigInt& lhs, const int& rhs)
{
	return rhs < lhs;
}

bool operator>(const BigInt& lhs, const std::string& rhs)
{
	return rhs < lhs;
}

bool operator>(const std::string& lhs, const BigInt& rhs)
{
	return rhs < lhs;
}

bool operator>(const BigInt& lhs, const BigInt& rhs)
{
	return rhs < lhs;
}

bool operator<=(const int& lhs, const BigInt& rhs)
{
	return !(rhs < lhs);
}

bool operator<=(const BigInt& lhs, const int& rhs)
{
	return !(rhs < lhs);
}
bool operator<=(const BigInt& lhs, const std::string& rhs)
{
	return !(rhs < lhs);
}
bool operator<=(const std::string& lhs, const BigInt& rhs)
{
	return !(rhs < lhs);
}
bool operator<=(const BigInt& lhs, const BigInt& rhs)
{
	return !(rhs < lhs);
}

bool operator>=(const int& lhs, const BigInt& rhs)
{
	return !(lhs < rhs);
}

bool operator>=(const BigInt& lhs, const int& rhs)
{
	return !(lhs < rhs);
}

bool operator>=(const BigInt& lhs, const std::string& rhs)
{
	return !(lhs < rhs);
}

bool operator>=(const std::string& lhs, const BigInt& rhs)
{
	return !(lhs < rhs);
}

bool operator>=(const BigInt& lhs, const BigInt& rhs)
{
	return !(lhs < rhs);
}

std::string BigInt::addition(std::string a, std::string b)
{
	std::string res;
	int carry = 0, c, temp, l;
	if (a.length() >= b.length())
	{
		swap(a, b);
	}
	int a_l = a.length();
	int b_l = b.length();
	for (int i = 1; i <= b_l; i++)
	{
		if ((a_l - i) >= 0)
		{
			c = (a.at(a_l - i) - '0') + (b.at(b_l - i) - '0') + carry;
		}
		else
		{
			c = (b.at(b_l - i) - '0') + carry;
		}
		carry = c / 10;
		res += (c % 10) + '0';
	}
	if (carry > 0)
	{
		res += (c / 10) + '0';
	}
	l = res.length() >> 1;
	for (int i = 0; i < l; i++)
	{
		temp = res[i];
		res[i] = res[res.length() - 1 - i];
		res[res.length() - 1 - i] = temp;
	}
	return	res;
}

std::string BigInt::substraction(const std::string& a, const std::string& b)
{
	std::string res;
	int carry = 0, c;
	int a_l = a.length();
	int b_l = b.length();
	if (a_l >= b_l)
	{
		for (int i = 1; i <= a_l; i++)
		{
			if ((b_l - i) >= 0)
			{
				c = (a.at(a_l - i) - '0') - (b.at(b_l - i) - '0') - carry;
			}
			else
			{
				c = (a.at(a_l - i) - '0') - carry;
			}
			if (c < 0)
			{
				c += 10;
				carry = 1;
			}
			else
			{
				carry = 0;
			}
			res += (c % 10) + '0';
		}
	}
	else
	{
		for (int i = 1; i < b_l; i++)
		{
			if ((a_l - i) >= 0)
			{
				c = (a.at(a_l - i) - '0') + (b.at(b_l - i) - '0') - carry;
			}
			else
			{
				c = (b.at(b_l - i) - '0') - carry;
			}
			if (c < 0)
			{
				c += 10;
				carry = 1;
			}
			else
			{
				carry = 0;
			}
			res += (c % 10) + '0';
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
	int l = res.length() >> 1;
	for (int i = 0; i < l; i++)
	{
		char temp = res[i];
		res[i] = res[res.length() - 1 - i];
		res[res.length() - 1 - i] = temp;
	}
	return	res;
}

// simple version
std::string BigInt::multiplication(std::string a, const std::string& b)
{
	std::string result = "0", t_res;
	for (int i = 1; i <= b.length(); i++)
	{
		int l = b[b.length() - i];
		t_res = "0";
		for (int i1 = '0'; i1 < l; i1++)
		{
			t_res = addition(a, t_res);
		}
		result = addition(result, t_res);
		a = a + "0";
	}
	return	result;
}

// division. v1.0
std::string BigInt::division(std::string a, std::string b)
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

std::string BigInt::modulo(std::string a, std::string b)
{
	if (a.length() < b.length() || (a.length() == b.length() && a < b))
	{
		return a;
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
	return a;
}
