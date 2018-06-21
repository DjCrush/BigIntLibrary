// long numbers v 1.0
#include <iostream>
#include <fstream>
#include "bigint.h"
using namespace std;

int main()
{
	ofstream o("e://out.txt");
	o << fact(30000);
	o.close();
	return 0;
}


