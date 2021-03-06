#include "stdafx.h"
#include <iostream>
#include <math.h>
using namespace std;

int equation()
{
	double a, b, c, d, o, t; // (a, b, c) - coefficients; d - discriminant; x - root; (x1 = o, x2 - t)
	cout << "Please select the coefficients of the quadratic equation but (a) should not be 0 (!)" << endl;
	cout << "" << endl;
	cout << "Select a:" << endl;
	cin >> a;
	do
	{
		if (a == 0)
		{
			cout << "" << endl;
			cout << "a should not be 0!" << endl;
			cout << "" << endl;
			cout << "Select a:" << endl;
			cin >> a;
		}
	} 
	while (a == 0);
	cout << "Select b:" << endl;
	cin >> b;
	cout << "Select c:" << endl;
	cin >> c;
	cout << "" << endl;
	d = pow(b, 2) - (4 * a * c);
	cout << "If:" << endl;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "" << endl;
	o = ((-1 * b) + pow(d, 1 / 2.)) / (2 * a);
	t = ((-1 * b) - pow(d, 1 / 2.)) / (2 * a);
	if (d < 0)
		cout << "There are no roots of the quadratic equation..." << endl;
	if (d > 0)
	{
		cout << "This quadratic equation has two roots:" << endl;
		cout << "" << endl;
		cout << "x1 = " << o << endl;
		cout << "x2 = " << t << endl;
		cout << "" << endl;
	}
	if (d == 0)
		cout << "x = " << o << endl;
	cout << "" << endl;
	int choise;
	cout << "Try again?" << endl;
	cout << "" << endl;
	cout << "1 - YES" << endl;
	cout << "2 - EXIT" << endl;
	cout << "" << endl;
	cin >> choise;
	switch (choise)
	{
	case 1:
		equation();
		break;
	case 2:
		return 0;
	}
	return 0;
}


int main()
{
	cout << "//////////  Task 1 from Pavel  //////////" << endl;
	cout << "////////////////////////////////////////" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "If some quadratic equation type is:" << endl;
	cout << "" << endl;
	cout << "a * x^2 + b * x + c = 0" << endl;
	cout << "" << endl;

	equation();
	
return 0;
}