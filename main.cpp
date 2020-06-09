// long numbers v 1.3
#include <iostream>
#include "bigint.h"


BigInt fact(int N)
{
	BigInt a = 1;
	if (N != 0)
	{
		for (int i = 2; i <= N; i++)
		{
			a = a * i;
			std::cout << a << std::endl;
		}
	}
	return a;
}


int main()
{
	std::cout << fact(1000) << std::endl;
	return 0;
}
