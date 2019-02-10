#include "bigint.h"

BigInt::BigInt(const string& N = "0") : number{ N } {}
BigInt::BigInt(const int& rhs) : number{ to_string(rhs) }{}
BigInt& BigInt::operator=(const int& rhs)
{
	number = to_string(rhs);
	return *this;
}
BigInt& BigInt::operator=(const BigInt& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	number = rhs.number;
	return *this;
}
BigInt operator-(const string& lhs, const BigInt& rhs)
{
	return { BigInt::substraction(lhs, rhs.number) };
}
BigInt operator-(const BigInt& lhs, const string& rhs)
{
	return { BigInt::substraction(lhs.number, rhs) };
}
BigInt operator-(const int& lhs, const BigInt& rhs)
{
	return { BigInt::substraction(to_string(lhs), rhs.number) };
}
BigInt operator-(const BigInt& lhs, const int& rhs)
{
	return { BigInt::substraction(lhs.number, to_string(rhs)) };
}
BigInt operator-(const BigInt& lhs, const BigInt& rhs)
{
	return { BigInt::substraction(lhs.number, rhs.number) };
}
BigInt& BigInt::operator-=(const BigInt& rhs)
{
	number = substraction(number, rhs.number);
	return *this;
}
BigInt& BigInt::operator-=(const int& rhs)
{
	number = substraction(number, to_string(rhs));
	return *this;
}
BigInt& BigInt::operator-=(const string& rhs)
{
	number = substraction(number, rhs);
	return *this;
}
BigInt operator+(const string& lhs, const BigInt& rhs)
{
	return { BigInt::addition(lhs, rhs.number) };
}
BigInt operator+(const BigInt& lhs, const string& rhs)
{
	return { BigInt::addition(lhs.number, rhs) };
}
BigInt operator+(const int& lhs, const BigInt& rhs)
{
	return { BigInt::addition(to_string(lhs), rhs.number) };
}
BigInt operator+(const BigInt& lhs, const int& rhs)
{
	return { BigInt::addition(lhs.number, to_string(rhs)) };
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
	number = addition(number, to_string(rhs));
	return *this;
}
BigInt& BigInt::operator+=(const string& rhs)
{
	number = addition(number, rhs);
	return *this;
}
BigInt operator*(const string& lhs, const BigInt& rhs)
{
	return { BigInt::multiplication(lhs, rhs.number) };
}
BigInt operator*(const BigInt& lhs, const string& rhs)
{
	return { BigInt::multiplication(lhs.number, rhs) };
}
BigInt operator*(const int& lhs, const BigInt& rhs)
{
	return { BigInt::multiplication(to_string(lhs), rhs.number) };
}
BigInt operator*(const BigInt& lhs, const int& rhs)
{
	return { BigInt::multiplication(lhs.number, to_string(rhs)) };
}
BigInt operator*(const BigInt& lhs, const BigInt& rhs)
{
	return { BigInt::multiplication(lhs.number, rhs.number) };
}
BigInt& BigInt::operator*=(const BigInt& rhs)
{
	number = multiplication(number, rhs.number);
	return *this;
}
BigInt& BigInt::operator*=(const int& rhs)
{
	number = multiplication(number, to_string(rhs));
	return *this;
}
BigInt& BigInt::operator*=(const string& rhs)
{
	number = multiplication(number, rhs);
	return *this;
}
BigInt operator/(const string& lhs, const BigInt& rhs)
{
	return { BigInt::division(lhs, rhs.number) };
}
BigInt operator/(const BigInt& lhs, const string& rhs)
{
	return { BigInt::division(lhs.number, rhs) };
}
BigInt operator/(const int& lhs, const BigInt& rhs)
{
	return { BigInt::division(to_string(lhs), rhs.number) };
}
BigInt operator/(const BigInt& lhs, const int& rhs)
{
	return { BigInt::division(lhs.number, to_string(rhs)) };
}
BigInt operator/(const BigInt& lhs, const BigInt& rhs)
{
	return { BigInt::division(lhs.number, rhs.number) };
}
BigInt& BigInt::operator/=(const BigInt& rhs)
{
	number = division(number, rhs.number);
	return *this;
}
BigInt& BigInt::operator/=(const int& rhs)
{
	number = division(number, to_string(rhs));
	return *this;
}
BigInt& BigInt::operator/=(const string& rhs)
{
	number = division(number, rhs);
	return *this;
}
BigInt operator%(const string& lhs, const BigInt& rhs)
{
	return { BigInt::modulo(lhs, rhs.number) };
}
BigInt operator%(const BigInt& lhs, const string& rhs)
{
	return { BigInt::modulo(lhs.number, rhs) };
}
BigInt operator%(const int& lhs, const BigInt& rhs)
{
	return { BigInt::modulo(to_string(lhs), rhs.number) };
}
BigInt operator%(const BigInt& lhs, const int& rhs)
{
	return { BigInt::modulo(lhs.number, to_string(rhs)) };
}
BigInt operator%(const BigInt& lhs, const BigInt& rhs)
{
	return { BigInt::modulo(lhs.number, rhs.number) };
}
BigInt& BigInt::operator%=(const BigInt& rhs)
{
	number = modulo(number, rhs.number);
	return *this;
}
BigInt& BigInt::operator%=(const int& rhs)
{
	number = modulo(number, to_string(rhs));
	return *this;
}
BigInt& BigInt::operator%=(const string& rhs)
{
	number = modulo(number, rhs);
	return *this;
}
ostream& operator<<(ostream& os, const BigInt& rhs)
{
	os << rhs.number;
	return os;
}
bool operator<(const int& lhs, const BigInt& rhs)
{
	string t = to_string(lhs);
	if (t.length() < rhs.number.length())
	{
		return true;
	}
	if (t.length() == rhs.number.length() && t < rhs.number)
	{
		return true;
	}
	return false;
}
bool operator<(const BigInt& lhs, const int& rhs)
{
	string t = to_string(rhs);
	if (lhs.number.length() < t.length())
	{
		return true;
	}
	if (lhs.number.length() == t.length() && lhs.number < t)
	{
		return true;
	}
	return false;
}
bool operator<(const BigInt& lhs, const string& rhs)
{
	if (lhs.number.length() < rhs.length())
	{
		return true;
	}
	if (lhs.number.length() == rhs.length() && lhs.number < rhs)
	{
		return true;
	}
	return false;
}
bool operator<(const string& lhs, const BigInt& rhs)
{
	if (lhs.length() < rhs.number.length())
	{
		return true;
	}
	if (lhs.length() == rhs.number.length() && lhs < rhs.number)
	{
		return true;
	}
	return false;
}
bool operator<(const BigInt& lhs, const BigInt& rhs)
{
	if (lhs.number.length() < rhs.number.length())
	{
		return true;
	}
	if (lhs.number.length() == rhs.number.length() && lhs.number < rhs.number)
	{
		return true;
	}
	return false;
}
bool operator<=(const int& lhs, const BigInt& rhs)
{
	string t = to_string(lhs);
	if (t.length() < rhs.number.length())
	{
		return true;
	}
	if (t.length() == rhs.number.length() && t <= rhs.number)
	{
		return true;
	}
	return false;
}
bool operator<=(const BigInt& lhs, const int& rhs)
{
	string t = to_string(rhs);
	if (lhs.number.length() < t.length())
	{
		return true;
	}
	if (lhs.number.length() == t.length() && lhs.number <= t)
	{
		return true;
	}
	return false;
}
bool operator<=(const BigInt& lhs, const string& rhs)
{
	if (lhs.number.length() < rhs.length())
	{
		return true;
	}
	if (lhs.number.length() == rhs.length() && lhs.number <= rhs)
	{
		return true;
	}
	return false;
}
bool operator<=(const string& lhs, const BigInt& rhs)
{
	if (lhs.length() < rhs.number.length())
	{
		return true;
	}
	if (lhs.length() == rhs.number.length() && lhs <= rhs.number)
	{
		return true;
	}
	return false;
}
bool operator<=(const BigInt& lhs, const BigInt& rhs)
{
	if (lhs.number.length() < rhs.number.length())
	{
		return true;
	}
	if (lhs.number.length() == rhs.number.length() && lhs.number <= rhs.number)
	{
		return true;
	}
	return false;
}
bool operator>(const int& lhs, const BigInt& rhs)
{
	string t = to_string(lhs);
	if (t.length() > rhs.number.length())
	{
		return true;
	}
	if (t.length() == rhs.number.length() && t > rhs.number)
	{
		return true;
	}
	return false;
}
bool operator>(const BigInt& lhs, const int& rhs)
{
	string t = to_string(rhs);
	if (lhs.number.length() > t.length())
	{
		return true;
	}
	if (lhs.number.length() == t.length() && lhs.number > t)
	{
		return true;
	}
	return false;
}
bool operator>(const BigInt& lhs, const string& rhs)
{
	if (lhs.number.length() > rhs.length())
	{
		return true;
	}
	if (lhs.number.length() == rhs.length() && lhs.number > rhs)
	{
		return true;
	}
	return false;
}
bool operator>(const string& lhs, const BigInt& rhs)
{
	if (lhs.length() > rhs.number.length())
	{
		return true;
	}
	if (lhs.length() == rhs.number.length() && lhs > rhs.number)
	{
		return true;
	}
	return false;
}
bool operator>(const BigInt& lhs, const BigInt& rhs)
{
	if (lhs.number.length() > rhs.number.length())
	{
		return true;
	}
	if (lhs.number.length() == rhs.number.length() && lhs.number > rhs.number)
	{
		return true;
	}
	return false;
}
bool operator>=(const int& lhs, const BigInt& rhs)
{
	string t = to_string(lhs);
	if (t.length() > rhs.number.length())
	{
		return true;
	}
	if (t.length() == rhs.number.length() && t >= rhs.number)
	{
		return true;
	}
	return false;
}
bool operator>=(const BigInt& lhs, const int& rhs)
{
	string t = to_string(rhs);
	if (lhs.number.length() > t.length())
	{
		return true;
	}
	if (lhs.number.length() == t.length() && lhs.number >= t)
	{
		return true;
	}
	return false;
}
bool operator>=(const BigInt& lhs, const string& rhs)
{
	if (lhs.number.length() > rhs.length())
	{
		return true;
	}
	if (lhs.number.length() == rhs.length() && lhs.number >= rhs)
	{
		return true;
	}
	return false;
}
bool operator>=(const string& lhs, const BigInt& rhs)
{
	if (lhs.length() > rhs.number.length())
	{
		return true;
	}
	if (lhs.length() == rhs.number.length() && lhs >= rhs.number)
	{
		return true;
	}
	return false;
}
bool operator>=(const BigInt& lhs, const BigInt& rhs)
{
	if (lhs.number.length() > rhs.number.length())
	{
		return true;
	}
	if (lhs.number.length() == rhs.number.length() && lhs.number >= rhs.number)
	{
		return true;
	}
	return false;
}
bool operator!=(const int& lhs, const BigInt& rhs)
{
	if (to_string(lhs) != rhs.number)
	{
		return true;
	}
	return false;
}
bool operator!=(const BigInt& lhs, const int& rhs)
{
	if (lhs.number != to_string(rhs))
	{
		return true;
	}
	return false;
}
bool operator!=(const BigInt& lhs, const string& rhs)
{
	if (lhs.number != rhs)
	{
		return true;
	}
	return false;
}
bool operator!=(const string& lhs, const BigInt& rhs)
{
	if (lhs != rhs.number)
	{
		return true;
	}
	return false;
}
bool operator!=(const BigInt& lhs, const BigInt& rhs)
{
	if (lhs.number != rhs.number)
	{
		return true;
	}
	return false;
}
bool operator==(const int& lhs, const BigInt& rhs)
{
	if (to_string(lhs) == rhs.number)
	{
		return true;
	}
	return false;
}
bool operator==(const BigInt& lhs, const int& rhs)
{
	if (lhs.number == to_string(rhs))
	{
		return true;
	}
	return false;
}
bool operator==(const BigInt& lhs, const string& rhs)
{
	if (lhs.number == rhs)
	{
		return true;
	}
	return false;
}
bool operator==(const string& lhs, const BigInt& rhs)
{
	if (lhs == rhs.number)
	{
		return true;
	}
	return false;
}
bool operator==(const BigInt& lhs, const BigInt& rhs)
{
	if (lhs.number == rhs.number)
	{
		return true;
	}
	return false;
}

string BigInt::addition(string a, string b)
{
	string res;
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

string BigInt::substraction(const string& a, const string& b)
{
	string res;

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
		if (it == string::npos)
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
string BigInt::multiplication(string a, const string& b)
{
	string result = "0", t_res;
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
string BigInt::division(string a, string b)
{
	if (a.length() < b.length() || (a.length() == b.length() && a < b))
	{
		return "0";
	}
	string result = "0";
	string zero(a.length() - b.length(), '0');
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

string BigInt::modulo(string a, string b)
{
	if (a.length() < b.length() || (a.length() == b.length() && a < b))
	{
		return a;
	}
	string result = "0";
	string zero(a.length() - b.length(), '0');
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
