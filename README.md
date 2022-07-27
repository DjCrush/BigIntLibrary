# BigInteger Library
Library for working with large numbers (Version 1.3)

The built-in primitive numeric types may not always be suitable for certain programs. For example, it is necessary to store and use very large numbers in the program, which go beyond the allowable values for the long and double types. In this case to work with numeric data you can use BigInteger library


Example of use:
------------

	#include <iostream>
	#include "bigint.h"

	BigInteger fact(int N)
	{
		BigInteger a = 1;
		for (BigInteger i = 1; i <= N; ++i)
		{
			a *= i;
		}
		return a;
	}

	int main()
	{
	    std::cout << "20! = " << fact(20) << std::endl;
	    std::cout << "30! = " << fact(30) << std::endl;
	    std::cout << "1000! = " << fact(1000) << std::endl;
	    for(BigInteger i = -1000; i <= 1000; i++)
	    {
		std::cout << i << "   ";
	    }
	    std::cout << '\n';
	    BigInteger i = 1000;
	    for(; i >= 1; i--)
	    {
		std::cout << i << ' ';
	    }
	    std::cout << i << '\n';
		return 0;
	}

