#include <iostream>
#include "BigInteger.h"

BigInteger fact(int N)
{
	BigInteger a = 1;
	for (BigInteger i = 1; i <= N; ++i)
	{
		a *= i;
	}
	return a;
}

BigInteger fibonacci(int n)
{
	BigInteger a("0");
	BigInteger b("1");
	BigInteger c("0");
	for (int i = 1; i < n; ++i)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

int main()
{
	std::cout << "Fibonacci 100000 = " << fibonacci(100000) << std::endl << std::endl;
    	std::cout << "20! = " << fact(20) << std::endl;
   	std::cout << "30! = " << fact(30) << std::endl;
    	std::cout << "1000! = " << fact(1000) << std::endl;
	std::cout << "100000! = " << fact(100000) << std::endl;
    	for(BigInteger i = -1000; i <= 1000; i++)
    	{
		std::cout << i << "   ";
    	}
    	std::cout << std::endl;
    	BigInteger i = 1000;
    	for(; i >= 1; i--)
    	{	
        	std::cout << i << ' ';
    	}
    	std::cout << i << std::endl;
    	return 0;
}
