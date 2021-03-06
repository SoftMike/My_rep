#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <iomanip>

typedef double(*uf)(double, double, int &);
void tabl(double, double, double, double, uf);
double y(double, double, int &);
double s(double, double, int &);



	void tabl(double a, double b, double h, double eps, uf fun)
	{
		int k = 0;
		double sum;
		for (double x = a; x<b + h / 2; x += h)
		{
			sum = fun(x, eps, k);
			std::cout << std::setw(8) << x << std::setw(15) << sum << std::setw(10) << k << std::endl;
		}
	}
	double y(double x, double eps, int &k)
	{
		return sin(x) / x;
	}
	double s(double x, double eps, int &k)
	{
		double a, c, sum;
		sum = a = c = x;
		k = 1;
		while (fabs(c)>eps)
		{
			c = (pow(x, 2)) / (2*k*(2*k+1));
			a *= -c;
			sum += a;
			k++;
		}
		return sum;

	}

	int main()
	{
		std::cout << std::setw(8) << "x" << std::setw(15) << "y(x)" << std::setw(10) << "k" << std::endl;
		tabl(0.1, 0.9, 0.1, 0.0001, y);
		std::cout << std::endl;
		std::cout << std::setw(8) << "x" << std::setw(15) << "s(x)" << std::setw(10) << "k" << std::endl;
		tabl(0.1, 0.9, 0.1, 0.0001, s);
		return 0;
	}

	
	
