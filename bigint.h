#pragma once
#include <string>
using namespace std;
namespace BigArithmetic {
	
	BigInt fact(int N);
	string fibonacci(string N);

	class BigInt
	{
	public:
		BigInt();
		BigInt(string N);
		BigInt& operator=(const BigInt& rhs);
		friend BigInt operator-(const BigInt& lhs, const BigInt& rhs);
		BigInt operator+(const BigInt& lhs, const BigInt& rhs);
		BigInt operator+(const BigInt& lhs, const int& rhs);
		BigInt operator*(const BigInt& lhs, const int& rhs);
		ostream& operator<<(ostream& os, const BigInt& rhs);
		bool operator <(BigInt const & lhs, BigInt const & rhs);
		bool modulo(const string& a, const string& b);
		string number;
		~BigInt();
	private:

		string addition(string a, string b);
		string substraction(const string& a, const string& b);
		string division(const string& a, const string& b);
		string multiplication(string a, string b);
	};
}