#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <math.h>

int task_3_1();
int task_3_2();
int task_3_4();
int task_3_5();
int task_3_6();

int SETUP()
{
	std::cout << "Please chose task:" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "1 - Task 1" << std::endl;
	std::cout << "2 - Task 2" << std::endl;
	std::cout << "3 - Task 4" << std::endl;
	std::cout << "4 - Task 5" << std::endl;
	std::cout << "5 - Task 6" << std::endl;
	std::cout << "6 - EXIT" << std::endl;
	std::cout << "" << std::endl;
	int choise = 0;
	do
	{
		std::cout << "" << std::endl;
		std::cin >> choise;
		switch (choise)
		{
		case 1:
			task_3_1();
			break;
		case 2:
			task_3_2();
			break;
		case 3:
			task_3_4();
			break;
		case 4:
			task_3_4();
			break;
		case 5:
			task_3_5();
			break;
		case 6:
			return 0;
		default:
			std::cout << "" << std::endl;
			std::cout << "Please do the right choise..." << std::endl;
			break;
		}
	} 
	while (choise < 1 || choise > 6);
}

int task_3_1()
{
	std::cout << std::setw(15) << "////////// Task 3.1 //////////" << std::endl;
	std::cout << std::setw(15) << "//////////////////////////////" << std::endl;
	std::cout << "" << std::endl;
	double a, b, h, x, y, s, p;
	int n, i;
	a = 0.1;
	b = 1;
	h = (b - a) / 10;
	n = 160;
	x = a;
	do
	{
		p = s = 1;
		for (i = 1; i <= n; i++)
		{
			p *= (-1) * pow(x, 2) / (2 * i * (2 * n + 1));
			s += p;
		}
		y = sin(x);
		std::cout << std::setw(15) << x << std::setw(15) << y << std::setw(15) << s << std::endl;
		x += h;
	} while (x <= b + h / 2);
	std::cout << std::endl;
	std::cout << "" << std::endl;
	std::cout << "1 - Main menu" << std::endl;
	std::cout << "2 - EXIT" << std::endl;
	std::cout << "" << std::endl;
	int choise;
	do
	{
		std::cin >> choise;
		switch (choise)
		{
		case 1:
			SETUP();
			break;
		case 2:
			return 0;

		default:
			std::cout << "" << std::endl;
			std::cout << "Please do the right choise..." << std::endl;
			break;
		}
	}
	while (choise < 1 || choise > 2);
	return 0;
}

int task_3_2()
{
	std::cout << std::setw(15) << "////////// Task 3.2 //////////" << std::endl;
	std::cout << std::setw(15) << "//////////////////////////////" << std::endl;
	std::cout << "" << std::endl;
	double a, b, h, x, y, s, p;
	int n, i;
	a = 0.1;
	b = 1;
	h = (b - a) / 10;
	n = 100;
	x = a;
	do
	{
		p = s = 1;
		for (i = 1; i <= n; i++)
		{
			p *= pow(x , 2) / (2 * i * (2 * i - 1));
			s += p;
		}
		y = (exp(x) + exp((-1) * x)) / 2;
		std::cout << std::setw(15) << x << std::setw(15) << y << std::setw(15) << s << std::endl;
		x += h;
	} while (x <= b + h / 2);
	std::cout << std::endl;
	std::cout << "" << std::endl;
	std::cout << "1 - Main menu" << std::endl;
	std::cout << "2 - EXIT" << std::endl;
	std::cout << "" << std::endl;
	int choise;
	do
	{
		std::cin >> choise;
		switch (choise)
		{
		case 1:
			SETUP();
			break;
		case 2:
			return 0;

		default:
			std::cout << "" << std::endl;
			std::cout << "Please do the right choise..." << std::endl;
			break;
		}
	} while (choise < 1 || choise > 2);
	return 0;
}

int task_3_4()
{
	std::cout << std::setw(15) << "////////// Task 3.4 //////////" << std::endl;
	std::cout << std::setw(15) << "//////////////////////////////" << std::endl;
	std::cout << "" << std::endl;
	double a, b, h, x, y, s, p;
	int n, i;
	a = 0.1;
	b = 1;
	h = (b - a) / 10;
	n = 80;
	x = a;
	do
	{
		p = s = 1;
		for (i = 1; i <= n; i++)
		{
			p *= (-1) * (pow(x, 2) / (2 * i * (2 * i - 1)));
			s += p;
		}
		y = cos(x);
		std::cout << std::setw(15) << x << std::setw(15) << y << std::setw(15) << s << std::endl;
		x += h;
	} while (x <= b + h / 2);
	std::cout << std::endl;
	std::cout << "" << std::endl;
	std::cout << "1 - Main menu" << std::endl;
	std::cout << "2 - EXIT" << std::endl;
	std::cout << "" << std::endl;
	int choise;
	do
	{
		std::cin >> choise;
		switch (choise)
		{
		case 1:
			SETUP();
			break;
		case 2:
			return 0;

		default:
			std::cout << "" << std::endl;
			std::cout << "Please do the right choise..." << std::endl;
			break;
		}
	} while (choise < 1 || choise > 2);
	return 0;
}

int task_3_5()
{
	std::cout << std::setw(15) << "////////// Task 3.5 //////////" << std::endl;
	std::cout << std::setw(15) << "//////////////////////////////" << std::endl;
	std::cout << "" << std::endl;
	double a, b, h, x, y, s, p;
	int n, i;
	a = 0.1;
	b = 1;
	h = (b - a) / 10;
	n = 140;
	x = a;
	do
	{
		p = s = 1;
		for (i = 1; i <= n; i++)
		{
			p *= ((i * 2 + 1) / i) * pow(x , 2);
			s += p;
		}
		y = (1 + 2 * pow(x , 2)) * exp(pow(x , 2));
		std::cout << std::setw(15) << x << std::setw(15) << y << std::setw(15) << s << std::endl;
		x += h;
	} while (x <= b + h / 2);
	std::cout << std::endl;
	std::cout << "" << std::endl;
	std::cout << "1 - Main menu" << std::endl;
	std::cout << "2 - EXIT" << std::endl;
	std::cout << "" << std::endl;
	int choise;
	do
	{
		std::cin >> choise;
		switch (choise)
		{
		case 1:
			SETUP();
			break;
		case 2:
			return 0;

		default:
			std::cout << "" << std::endl;
			std::cout << "Please do the right choise..." << std::endl;
			break;
		}
	} while (choise < 1 || choise > 2);
	return 0;
}

int task_3_6()
{
	std::cout << std::setw(15) << "////////// Task 3.6 //////////" << std::endl;
	std::cout << std::setw(15) << "//////////////////////////////" << std::endl;
	std::cout << "" << std::endl;
	double a, b, h, x, y, s, p;
	int n, i;
	a = 0.1;
	b = 1;
	h = (b - a) / 10;
	n = 80;
	x = a;
	do
	{
		p = s = 1;
		for (i = 1; i <= n; i++)
		{
			p *= pow(x , 2) / (2 * i * (2 * n + 1));
			s += p;
		}
		y = (exp(x) - exp((-1) * x)) / 2.;
		std::cout << std::setw(15) << x << std::setw(15) << y << std::setw(15) << s << std::endl;
		x += h;
	} while (x <= b + h / 2);
	std::cout << std::endl;
	std::cout << "" << std::endl;
	std::cout << "1 - Main menu" << std::endl;
	std::cout << "2 - EXIT" << std::endl;
	std::cout << "" << std::endl;
	int choise;
	do
	{
		std::cin >> choise;
		switch (choise)
		{
		case 1:
			SETUP();
			break;
		case 2:
			return 0;

		default:
			std::cout << "" << std::endl;
			std::cout << "Please do the right choise..." << std::endl;
			break;
		}
	} while (choise < 1 || choise > 2);
	return 0;
}

int main()
{
	std::cout << "////////////////////////////" << std::endl;
	std::cout << "/// Laboratory work N: 3 ///" << std::endl;
	std::cout << "////////////////////////////" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "" << std::endl;

	SETUP();
	
	return 0;
}