#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <cstdio>

int one();
int two();
int three();
int four();
int five();
int six();
int seven();
int eight();
int nine();

int setup()
{
	int choise;
	std::cout << "" << std::endl;
	std::cout << "Please choose the task:" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "1 - program read numbers from user before entering '0' and then show all entering numbers" << std::endl;
	std::cout << "2 - program sort floating-point entering numbers from minimal to maximal" << std::endl;
	std::cout << "3 - average arithmetic value of 'n' numbers" << std::endl;
	std::cout << "4 - sum of all numbers from 0 to entered number" << std::endl;
	std::cout << "5 - find factorial of a number using 3 different ways" << std::endl;
	std::cout << "6 - to raise a number to the power" << std::endl;
	std::cout << "7 - raises an exponent to the entered power" << std::endl;
	std::cout << "8 - sinus of number" << std::endl;
	std::cout << "9 - cosinus of number" << std::endl;
	std::cout << "10 - EXIT..." << std::endl;
	std::cout << "" << std::endl;
	do
	{
		std::cin >> choise;
		switch (choise)
		{
		case 1:
			one();
			break;
		case 2:
			two();
			break;
		case 3:
			three();
			break;
		case 4:
			four();
			break;
		case 5:
			five();
			break;
		case 6:
			six();
			break;
		case 7:
			seven();
			break;
		case 8:
			eight();
			break;
		case 9:
			nine();
			break;
		case 10:
			return false;
		default:
			std::cout << "Please do the right choise..." << std::endl;
			break;
		}
	} while (choise < 0 || choise > 10);

	return 0;
}

int one()
{
	int i = 0;
	char A[100];

	std::cout << "" << std::endl;
	std::cout << "Please enter some numbers:" << std::endl;

	for (i = 0; ; i++)
	{
		std::cin >> A[i];
		if (A[i] == '0')
		{
			A[i] = '\0';
			break;
		}
	}

	std::cout << "////////////////////" << std::endl;
	std::cout << "" << std::endl;
	std::cout << A << std::endl;
	std::cout << "" << std::endl;
	std::cout << "Total of " << i << " rooms" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "////////////////////" << std::endl;

	setup();

	return 0;
}
int two()
{
	float A[100], c;
	int a = 0, l = 0, i = 0;

	std::cout << "Please enter an array and then enter '0':" << std::endl;
	std::cout << "" << std::endl;

	for (i = 0; ; i++)
	{
		std::cin >> A[i];
		if (A[i] == 0)
		{
			A[i] = '\0';
			break;
		}
	}

	l = i;

	for (i = 1; i<l; i++)
		for (a = 1; a<l; a++)
			if (A[a - 1] > A[a])
			{
				c = A[a - 1];
				A[a - 1] = A[a];
				A[a] = c;
			}

	std::cout << "////////////////////" << std::endl;
	std::cout << "SORT RESULTS:" << std::endl;
	for (i = 0; i<l; i++)
		std::cout << A[i] << std::endl;
	std::cout << "////////////////////" << std::endl;

	setup();

	return 0;
}
int three()
{
	int n = 0, k = 0, i = 0;
	int A[100];
	float m = 0;

	std::cout << "Please enter 'n' (quantity of numbers):" << std::endl;
	std::cout << "" << std::endl;
	std::cin >> n;
	std::cout << "" << std::endl;
	std::cout << "Now enter numbers:" << std::endl;
	std::cout << "" << std::endl;

	for (i = 0; i < n; i++)
		std::cin >> A[i];

	for (i = 0; i < n; i++)
		k = k + A[i];

	m = float(k) / float(n);

	std::cout << "////////////////////" << std::endl;
	std::cout << "Average arithmetic value:" << std::endl;
	std::cout << m << std::endl;
	std::cout << "////////////////////" << std::endl;

	setup();

	return 0;
}
int four()
{
	int n = 0, i = 0, k = 0;
	std::cout << "Please enter your number:" << std::endl;
	std::cout << "" << std::endl;
	std::cin >> n;

	for (i = 0, k = 1; k <= n; k++)
		i = i + k;

	std::cout << "////////////////////" << std::endl;
	std::cout << "Sum is:" << std::endl;
	std::cout << i << std::endl;
	std::cout << "////////////////////" << std::endl;

	setup();

	return 0;
}
int five()
{
	int n = 0, i = 0, k = 0, choise = 0;
	std::cout << "Please enter your number:" << std::endl;
	std::cout << "" << std::endl;
	std::cin >> n;

	std::cout << "" << std::endl;
	std::cout << "Please choose the way of finding decision:" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "1 - cycle /for/" << std::endl;
	std::cout << "2 - cycle /while/" << std::endl;
	std::cout << "3 - cycle /do while/" << std::endl;
	do
	{
		std::cin >> choise;
		switch (choise)
		{
		case 1:
			for (i = 1, k = 1; k <= n; k++)
				i = i * k;
		case 2:
			i = 1;
			k = 1;
			while (k <= n)
			{
				i = i * k;
				k++;
			}
		case 3:
			i = 1;
			k = 1;
			do
			{
				i = i * k;
				k++;
			} while (k <= n);
		default:
			if (choise <= 0 || choise > 3)
				std::cout << "Please do the right choise..." << std::endl;
			break;
		}
	} while (choise <= 0 || choise > 3);

	std::cout << "////////////////////" << std::endl;
	std::cout << "Sum is:" << std::endl;
	std::cout << i << std::endl;
	std::cout << "////////////////////" << std::endl;

	setup();

	return 0;
}
int six()
{
	int n = 0, k = 0, i = 0, p = 0;

	std::cout << "Please enter your number:" << std::endl;
	std::cout << "" << std::endl;
	std::cin >> n;
	p = n;

	std::cout << "Now enter the power of:" << std::endl;
	std::cout << "" << std::endl;
	std::cin >> k;

	for (i = 1; i < k; i++)
		n = n * p;

	std::cout << "////////////////////" << std::endl;
	std::cout << p << " to the power of " << k << " is:" << std::endl;
	std::cout << n << std::endl;
	std::cout << "////////////////////" << std::endl;

	setup();

	return 0;
}
int seven()
{
	float i = 1, x = 0, k = 1, n = 1;
	int q;

	std::cout << "Please enter the power:" << std::endl;
	std::cout << "" << std::endl;
	std::cin >> x;

	for (q = 1; q<20; q++)
	{
		n = n * k;
		i = i + pow(x, k) / n;
		k++;
	}

	std::cout << "////////////////////" << std::endl;
	std::cout << "exp^" << x << ":" << std::endl;
	std::cout << i << std::endl;
	std::cout << "////////////////////" << std::endl;

	setup();

	return 0;
}
int eight()
{
	float i = 0, x = 0, k = 0, n = 1;
	int o = 0;

	std::cout << "Please enter your number:" << std::endl;
	std::cout << "" << std::endl;
	std::cin >> x;

	i = x;

	for (o = 1; o < 100; o++)
	{
		k = 2 * o + 1;
		n = n * (2 * o)*(2 * o + 1);
		i = i + (pow(-1, o) * pow(x, k)) / n;
	}

	std::cout << "////////////////////" << std::endl;
	std::cout << "sin of " << x << ":" << std::endl;
	std::cout << i << std::endl;
	std::cout << "////////////////////" << std::endl;

	setup();

	return 0;
}
int nine()
{
	float i = 1, x = 0, k = 0, n = 1, o = 0;

	std::cout << "Please enter your number:" << std::endl;
	std::cout << "" << std::endl;
	std::cin >> x;

	for (o = 1; o < 100; o++)
	{
		k = o * 2;
		n = n * (2 * o)*(2 * o - 1);
		i = i + (pow(-1, o) * pow(x, k)) / n;
	}

	std::cout << "////////////////////" << std::endl;
	std::cout << "cos of " << x << ":" << std::endl;
	std::cout << i << std::endl;
	std::cout << "////////////////////" << std::endl;

	setup();

	return 0;
}

int main()
{
	setup();

	return 0;
}