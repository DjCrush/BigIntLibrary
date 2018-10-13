// long numbers v 1.1
#include <iostream>
#include "bigint.h"
using namespace std;

BigInt fact(int N);
//BigInt fibonacci(int N);

int main()
{
	BigInt a;
	a = 3;
	int i = 3;
	a = a * i;
	cout << a;
	//cout << fact(12) << endl;
	return 0;
}


BigInt fact(int N)
{
	BigInt a = 1;
	if (N != 0)
	{
		for (int i = 1; i <= N; i++)
		{
			a = a * i;
			cout << a << endl;
		}
	}
	return a;
}
/*

BigInt fibonacci(string N)
{
	int index = 0;
	BigInt a, b, c;
	do {
		if (index == 0)
		{
			a = "0"; b = "0";
		}
		if (index == 1)
		{
			a = "1";
		}
		c = a + b;
		a = b;
		b = c;
		++index;
	} while (c != N);
	return c;
}
*/