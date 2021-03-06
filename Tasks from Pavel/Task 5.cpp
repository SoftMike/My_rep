#include "stdafx.h"
#include <iostream>

void int_bytes(int x)
{
	char bytes[36];
	int n = 0;

	for (int i = 0; ; i++)
	{
		if (n == 8 || n == 16 || n == 24)
		{
			bytes[i] = ' ';
			i++;
		}

		if (x == 0)
		{
			for (i; i < 35; i++)
			{
				if (n == 8 || n == 16 || n == 24)
				{
					bytes[i] = ' ';
					i++;
				}
				bytes[i] = '0';
				n++;
			}
			bytes[i] = '\0';
			break;
		}

		if (x % 2)
		{
			bytes[i] = '1';
			n++;
		}
		else
		{
			bytes[i] = '0';
			n++;
		}

		x /= 2;
	}


	int c = 34;
	for (int i = 0; i != c; i++, c--)
	{
		char u;
		u = bytes[i];
		bytes[i] = bytes[c];
		bytes[c] = u;

	}

	bytes[35] = '\0';

	std::cout << bytes << std::endl;
}

void my_binary(int x)
{
	if (x == 0)
		return;

	my_binary(x / 2);

	std::cout << x % 2;
}

int one_bits(int x)
{
	int n = 0;

	for (int i = 0; ; i++)
	{
		if (x == 0)
			break;
		if (x % 2)
			n++;

		x /= 2;
	}

	return n;
}

int main()
{
	int x = 0;
	std::cout << "Please enter value:" << std::endl;
	std::cin >> x;
	std::cout << std::endl;
	std::cout << "Value:            " << x << std::endl;
	std::cout << "Binary value:     ";
	my_binary(x);
	std::cout << std::endl;
	std::cout << "Bytes view:       ";
	int_bytes(x);
	std::cout << "Single bits:      " << one_bits(x) << std::endl;
	std::cout << std::endl;

	return 0;
}