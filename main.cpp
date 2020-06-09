// long numbers v 1.3
#include <iostream>
#include <thread>
#include "bigint.h"
#include <chrono>

BigInt fact(int N)
{
	BigInt a = 1;
	for (int i = 1; i <= N; i++)
	{
		a *= i;
	}
	return a;
}

int main()
{
	std::chrono::high_resolution_clock::time_point time_begin = std::chrono::high_resolution_clock::now();
	std::cout << fact(1000) << std::endl;
	std::chrono::high_resolution_clock::time_point time_end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>(time_end - time_begin).count();
	return 0;
}
