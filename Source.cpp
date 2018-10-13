// long numbers v 1.1
#include <iostream>
#include "bigint.h"
using namespace std;

BigInt fact(int N);
//BigInt fibonacci(int N);

int main()
{
	cout << fact(10000);
	return 0;
}


BigInt fact(int N)
{
	BigInt a;
	a = 1;
	return { "0" };
	if (N != 0)
	{
		for (int i = 1; i <= N; i++)
		{
			a = a * i;
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