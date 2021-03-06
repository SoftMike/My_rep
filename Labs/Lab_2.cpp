#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

int setup();

int example()
{
	cout << "" << endl;
	cout << "You chose example lab" << endl;
	cout << "" << endl;
		double x, y, f, a, s;
		int k;
		cout << "Enter x:" << endl;
		cout << "" << endl;
		cin >> x;
		cout << "" << endl;
		cout << "Enter y;" << endl;
		cout << "" << endl;
		cin >> y;
		cout << "" << endl;
		cout << "Select f:" << endl;
		cout << "" << endl;
		cout << "1 - sh(x)" << endl;
		cout << "2 - x^2" << endl;
		cout << "3 - e^x" << endl;
		cout << "" << endl;
		do
		{
			cin >> k;
			switch (k)
			{
			case 1:
				f = sinh(x);
				cout << "f = sh(x)" << endl;
				cout << "" << endl;
				break;
			case 2:
				f = pow(x, 2);
				cout << "f = x^2" << endl;
				cout << "" << endl;
				break;
			case 3:
				f = exp(x);
				cout << "f = e^x" << endl;
				cout << "" << endl;
				break;
			default:
				cout << "" << endl;
				cout << "You did not select a function." << endl;
				cout << "Try again please..." << endl;
				cout << "" << endl;
				break;
			}
		} while (k < 1 || k > 3);
		a = fabs(x*y);
		if (a < 5)
		{
			cout << "Not result" << endl;
			return 1;
		}
		else
			if (a > 10)
				s = fabs(f) + log(y);
			else
				if (a > 5 || a <= 10)
					s = exp(f + y);
				else
					s = sin(x) + tan(y);
		cout << "" << endl;
		cout << "RESULT = " << s << endl;
		cout << "" << endl;
		cout << "" << endl;
		setup();
		return 0;
	}

int lab2_1()
{
	cout << "" << endl;
	cout << "You chose lab 2.1" << endl;
	cout << "" << endl;
	double x, y, f, a, c;
	int k;
	cout << "Enter x:" << endl;
	cout << "" << endl;
	cin >> x;
	cout << "" << endl;
	cout << "Enter y;" << endl;
	cout << "" << endl;
	cin >> y;
	cout << "" << endl;
	cout << "Select f:" << endl;
	cout << "" << endl;
	cout << "1 - sh(x)" << endl;
	cout << "2 - x^2" << endl;
	cout << "3 - e^x" << endl;
	cout << "" << endl;
	do
	{
		cin >> k;
		switch (k)
		{
		case 1:
			f = sinh(x);
			cout << "f = sh(x)" << endl;
			cout << "" << endl;
			break;
		case 2:
			f = pow(x, 2);
			cout << "f = x^2" << endl;
			cout << "" << endl;
			break;
		case 3:
			f = exp(x);
			cout << "f = e^x" << endl;
			cout << "" << endl;
			break;
		default:
			cout << "" << endl;
			cout << "You did not select a function." << endl;
			cout << "Try again please..." << endl;
			cout << "" << endl;
			break;
		}
	} while (k < 1 || k > 3);
	c = x * y;
	if (c > 0)
		a = pow((f + y), 2) - pow(f, (1 / 3.));
	else
		a = pow((f + y), 2) + sin(x);
	if (c == 0)
		a = pow((f + y), 2) + pow(y, 3);
	cout << "" << endl;
	cout << "RESULT = " << a << endl;
	cout << "" << endl;
	cout << "" << endl;
	setup();

	return 0;
}

int lab2_2()
{
	cout << "" << endl;
	cout << "You chose lab 2.2" << endl;
	cout << "" << endl;
	double x, y, f, b, c;
	int k;
	cout << "Enter x:" << endl;
	cout << "" << endl;
	cin >> x;
	cout << "" << endl;
	cout << "Enter y;" << endl;
	cout << "" << endl;
	cin >> y;
	cout << "" << endl;
	cout << "Select f:" << endl;
	cout << "" << endl;
	cout << "1 - sh(x)" << endl;
	cout << "2 - x^2" << endl;
	cout << "3 - e^x" << endl;
	cout << "" << endl;
	do
	{
		cin >> k;
		switch (k)
		{
		case 1:
			f = sinh(x);
			cout << "f = sh(x)" << endl;
			cout << "" << endl;
			break;
		case 2:
			f = pow(x, 2);
			cout << "f = x^2" << endl;
			cout << "" << endl;
			break;
		case 3:
			f = exp(x);
			cout << "f = e^x" << endl;
			cout << "" << endl;
			break;
		default:
			cout << "" << endl;
			cout << "You did not select a function." << endl;
			cout << "Try again please..." << endl;
			cout << "" << endl;
			break;
		}
	} while (k < 1 || k > 3);
	c = x / y;
	if (c > 0)
		b = log(f) + pow(f, (1 / 3.));
	else
		b = log(fabs(f / y)) * pow((x + y) , 3);
	if (c == 0)
		b = pow((pow(f , 2) + y) , 3);
	cout << "" << endl;
	cout << "RESULT = " << b << endl;
	cout << "" << endl;
	cout << "" << endl;
	setup();
	return 0;
}

int lab2_3()
{
	cout << "" << endl;
	cout << "You chose lab 2.3" << endl;
	cout << "" << endl;
	double x, y, f, c, z;
	int k;
	cout << "Enter x:" << endl;
	cout << "" << endl;
	cin >> x;
	cout << "" << endl;
	cout << "Enter y;" << endl;
	cout << "" << endl;
	cin >> y;
	cout << "" << endl;
	cout << "Select f:" << endl;
	cout << "" << endl;
	cout << "1 - sh(x)" << endl;
	cout << "2 - x^2" << endl;
	cout << "3 - e^x" << endl;
	cout << "" << endl;
	do
	{
		cin >> k;
		switch (k)
		{
		case 1:
			f = sinh(x);
			cout << "f = sh(x)" << endl;
			cout << "" << endl;
			break;
		case 2:
			f = pow(x, 2);
			cout << "f = x^2" << endl;
			cout << "" << endl;
			break;
		case 3:
			f = exp(x);
			cout << "f = e^x" << endl;
			cout << "" << endl;
			break;
		default:
			cout << "" << endl;
			cout << "You did not select a function." << endl;
			cout << "Try again please..." << endl;
			cout << "" << endl;
			break;
		}
	} while (k < 1 || k > 3);
	z = x - y;
	if (z > 0)
		c = pow((f - y) , 2) + log(x);
	else
		c = pow((y - f) , 2) + tan(y);
	if (z == 0)
		c = pow(f , 2) + pow(y , (1/3)) + sin(y);
	cout << "" << endl;
	cout << "RESULT = " << c << endl;
	cout << "" << endl;
	cout << "" << endl;
	setup();
	return 0;
}

int lab2_4()
{
	cout << "" << endl;
	cout << "You chose lab 2.4" << endl;
	cout << "" << endl;
	double x, y, f, d, z;
	int k;
	cout << "Enter x:" << endl;
	cout << "" << endl;
	cin >> x;
	cout << "" << endl;
	cout << "Enter y;" << endl;
	cout << "" << endl;
	cin >> y;
	cout << "" << endl;
	cout << "Select f:" << endl;
	cout << "" << endl;
	cout << "1 - sh(x)" << endl;
	cout << "2 - x^2" << endl;
	cout << "3 - e^x" << endl;
	cout << "" << endl;
	do
	{
		cin >> k;
		switch (k)
		{
		case 1:
			f = sinh(x);
			cout << "f = sh(x)" << endl;
			cout << "" << endl;
			break;
		case 2:
			f = pow(x, 2);
			cout << "f = x^2" << endl;
			cout << "" << endl;
			break;
		case 3:
			f = exp(x);
			cout << "f = e^x" << endl;
			cout << "" << endl;
			break;
		default:
			cout << "" << endl;
			cout << "You did not select a function." << endl;
			cout << "Try again please..." << endl;
			cout << "" << endl;
			break;
		}
	} while (k < 1 || k > 3);
	if (x > y)
		d = pow((fabs(f - y)) , (1/3)) + tan(f);
	else
		d = pow((y - f) , 3) + cos(f);
	if (x == y)
		d = pow((y + f) , 2) + pow(x , 3);
	cout << "" << endl;
	cout << "RESULT = " << d << endl;
	cout << "" << endl;
	cout << "" << endl;
	setup();
	return 0;
}

int lab2_5()
{
	cout << "" << endl;
	cout << "You chose lab 2.5" << endl;
	cout << "" << endl;
	double x, y, f, e;
	int k;
	cout << "Enter x:" << endl;
	cout << "" << endl;
	cin >> x;
	cout << "" << endl;
	cout << "Enter y;" << endl;
	cout << "" << endl;
	cin >> y;
	cout << "" << endl;
	cout << "Select f:" << endl;
	cout << "" << endl;
	cout << "1 - sh(x)" << endl;
	cout << "2 - x^2" << endl;
	cout << "3 - e^x" << endl;
	cout << "" << endl;
	do
	{
		cin >> k;
		switch (k)
		{
		case 1:
			f = sinh(x);
			cout << "f = sh(x)" << endl;
			cout << "" << endl;
			break;
		case 2:
			f = pow(x, 2);
			cout << "f = x^2" << endl;
			cout << "" << endl;
			break;
		case 3:
			f = exp(x);
			cout << "f = e^x" << endl;
			cout << "" << endl;
			break;
		default:
			cout << "" << endl;
			cout << "You did not select a function." << endl;
			cout << "Try again please..." << endl;
			cout << "" << endl;
			break;
		}
	} while (k < 1 || k > 3);
	if (x > y)
		e = pow(f , (1/y)) + 3 * sin(x);
	else
		e = pow((fabs(f)) , (1/x));
	if (x == y)
		e = pow((fabs(f)), (1 / 3)) + pow(x , 3) / y;
	cout << "" << endl;
	cout << "RESULT = " << e << endl;
	cout << "" << endl;
	cout << "" << endl;
	setup();
	return 0;
}


int setup()
{
	cout << "" << endl;
	cout << "Choose the chapter of labs please..." << endl;
	cout << "" << endl;
	cout << "1 - example lab" << endl;
	cout << "2 -  2.1" << endl;
	cout << "3 -  2.2" << endl;
	cout << "4 -  2.3" << endl;
	cout << "5 -  2.4" << endl;
	cout << "6 -  2.5" << endl;
	cout << "7 -  Exit..." << endl;
	cout << "" << endl;
	int k;
	do
	{
		cin >> k;
		switch (k)
		{
		case 1:
			example();
			break;
		case 2:
			lab2_1();
			break;
		case 3:
			lab2_2();
			break;
		case 4:
			lab2_3();
			break;
		case 5:
			lab2_4();
			break;
		case 6:
			lab2_5();
			break;
		case 7:
			cout << "Exit..." << endl;
			return 1;
		default:
			cout << "" << endl;
			cout << "Choose the right chapter please..." << endl;
			cout << "" << endl;
			break;
		}
	} while (k < 1 || k > 6);
	return 0;
}



int main()
{
	cout << "////////// Labs № 2 //////////" << endl;
	cout << "" << endl;
	setup();

	return 0;
}
