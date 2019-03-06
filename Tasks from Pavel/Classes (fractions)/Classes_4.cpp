#include "pch.h"
#include <iostream>
#include "frac.h"

int main()
{
	fraction a(5, 7), b(20,5), c;
	c = a * b;

	double x = c.doub();
	std::cout << x << "\n";
}