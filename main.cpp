// long numbers v 1.3
#include <iostream>
#include "bigint.h"
using namespace std;

BigInt fact(int N);

int main()
{
	cout << fact(1000) << endl;
	return 0;
}

BigInt fact(int N)
{
	BigInt a = 1;
	if (N != 0)
	{
		for (int i = 2; i <= N; i++)
		{
			a = a * i;
			cout << a << endl;
		}
	}
	return a;
}
