#include "bigint.h"

BigInt::BigInt() : number("0")
{}

BigInt::BigInt(const string& N) : number(N)
{}

BigInt::BigInt(const int& rhs) : number(to_string(rhs))
{}

BigInt BigInt::operator=(const int& rhs)
{
	number = to_string(rhs);
	return *this;
}

BigInt BigInt::operator= (const BigInt& rhs)
{
	if (this == &rhs) {
		return *this;
	}
	number = rhs.number;
	return *this;
}

BigInt BigInt::operator-(const BigInt& rhs)
{
	return { substraction(number, rhs.number) };
}

BigInt BigInt::operator-(const int& rhs)
{
	return { substraction(number, to_string(rhs)) };
}

BigInt BigInt::operator-=(const BigInt& rhs)
{
	return { substraction(number, rhs.number) };
}
BigInt BigInt::operator-=(const int& rhs)
{
	return { substraction(number, to_string(rhs)) };
}

BigInt BigInt::operator+(const BigInt& rhs)
{
	return { addition(number, rhs.number) };
}

BigInt BigInt::operator+(const int& rhs)
{
	return { addition(number, to_string(rhs)) };
}

BigInt BigInt::operator+=(const BigInt& rhs)
{
	return { addition(number, rhs.number) };
}

BigInt BigInt::operator+=(const int& rhs)
{
	return { addition(number, to_string(rhs)) };
}

BigInt BigInt::operator*(const BigInt& rhs)
{
	return { multiplication(number, rhs.number) };
}

BigInt BigInt::operator*(const int& rhs)
{
	return { multiplication(number, to_string(rhs)) };
}

BigInt BigInt::operator*=(const BigInt& rhs)
{
	return { multiplication(number, rhs.number) };
}

BigInt BigInt::operator*=(const int& rhs)
{
	return { multiplication(number, to_string(rhs)) };
}


BigInt BigInt::operator/(const BigInt& rhs)
{
	return { division(number, rhs.number) };
}
BigInt BigInt::operator/(const int& rhs)
{
	return { division(number, to_string(rhs)) };
}

BigInt BigInt::operator/=(const BigInt& rhs)
{
	return { division(number, rhs.number) };
}

BigInt BigInt::operator/=(const int& rhs)
{
	return { division(number, to_string(rhs)) };
}

ostream& operator<<(ostream& os, const BigInt& rhs)
{
	os << rhs.number;
	return os;
}

bool BigInt::operator< (BigInt const & rhs)
{
	if (number.length() < rhs.number.length())
	{
		return true;
	}
	if (number.length() == rhs.number.length())
	{

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
	for (int i = 0; i < b_l; i++)
	{
		if ((a_l - 1 - i) >= 0)
		{
			c = (a.at(a_l - 1 - i) - '0') + (b.at(b_l - 1 - i) - '0') + carry;
		}
		else
		{
			c = (b.at(b_l - 1 - i) - '0') + carry;
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

string BigInt::substraction(string a, string b)
{
	string res;

	int carry = 0, c;
	int a_l = a.length();
	int b_l = b.length();

	if (a_l >= b_l)
	{
		for (int i = 0; i < a_l; i++)
		{
			if ((b_l - 1 - i) >= 0)
			{
				c = (a.at(a_l - 1 - i) - '0') - (b.at(b_l - 1 - i) - '0') - carry;
			}
			else
			{
				c = (a.at(a_l - 1 - i) - '0') - carry;
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
		for (int i = 0; i < b_l; i++)
		{
			if ((a_l - 1 - i) >= 0)
			{
				c = (a.at(a_l - 1 - i) - '0') + (b.at(b_l - 1 - i) - '0') - carry;
			}
			else
			{
				c = (b.at(b_l - 1 - i) - '0') - carry;
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
	int l = res.length() >> 1;
	char temp;
	for (int i = 0; i < l; i++)
	{
		temp = res[i];
		res[i] = res[res.length() - 1 - i];
		res[res.length() - 1 - i] = temp;
	}

	return	res;
}

// light version
string BigInt::multiplication(string a, string b)
{
	string result = "0", t_res;
	for (int i = 0; i < b.length(); i++)
	{
		int l = b[b.length() - 1 - i] - '0';
		t_res = "0";
		for (int i1 = 0; i1 < l; i1++)
		{
			t_res = addition(a, t_res);
		}
		result = addition(result, t_res);
		a = a + "0";
	}
	return	result;
}

string BigInt::division(string a, string b)
{
	string result = "0", t_res;

	return	result;
}


BigInt::~BigInt()
{}