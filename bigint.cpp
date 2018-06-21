#include "bigint.h"


BigArithmetic::BigInt::BigInt() : number("0") {}

BigArithmetic::BigInt::BigInt(string N) : number(N){}

BigInt& BigArithmetic::BigInt::operator=(const BigInt& rhs) {
	//проверка на самоприсваивание
	if (this == &rhs) {
		return *this;
	}
	number = rhs.number;
	return *this;
}

BigInt BigArithmetic::BigAritmetic::operator-(const BigInt& lhs, const BigInt& rhs)
{
	return BigInt(substraction(lhs.number, rhs.number));
}


const BigInt BigInt::operator+(const BigInt& lhs, const BigInt& rhs)
{
	return BigInt(addition(lhs.number, rhs.number));
}

const BigInt BigInt::operator+(const BigInt& lhs, const int& rhs)
{
	return BigInt(addition(lhs.number, to_string(rhs)));
}

const BigInt BigInt::operator*(const BigInt& lhs, const int& rhs)
{
	return BigInt(multiplication(lhs.number, to_string(rhs)));
}

ostream& BigInt::operator<<(ostream& os, const BigInt& rhs)
{
	os << rhs.number;
	return os;
}

bool BigInt::operator <(BigInt const & lhs, BigInt const & rhs)
{
	return true;
}


string addition(string a, string b)
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

string substraction(const string& a, const string& b)
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
string multiplication(string a, string b)
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

string division(const string& a, const string& b)
{
	string result = "0", t_res;

	return	result;
}

bool modulo(const string& a, const string& b)
{
	bool result;

	return	result;

}

BigInt BigInt::fact(int N)
{
	BigInt a("1");
	if (N != 0)
	{
		for (int i = 1; i <= N; i++)
		{
			a = a * i;
		}
	}
	return a;
}


string fibonacci(string N)
{
	string index = 0;
	string a, b, c;
	do {
		if (index == "0")
		{
			a = "0"; b = "0";
		}
		if (index == "1")
		{
			a = "1";
		}
		c = addition(a, b);
		a = b;
		b = c;
		index = addition(index, "1");
	} while (c != N);
	return c;
}

BigInt::~BigInt()
{

}