#include "pch.h"
#include <string>
#include <iostream>
#include "bigint.h"

int main()
{
	bigint a, b;
	a = "100";
	b = 100 + a + 100;

	b.display();
	return 0;
}