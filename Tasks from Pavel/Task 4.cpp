#include "stdafx.h"
#include <iostream>
#include <vector>

int setup();

int negativs(int *A, int n)
{
	int *B = new int[n];
	int *B_p = B;
	int negative_count = 0;

	for (int i = 0; i < n; i++)
	{
		if (A[i] < 0)
		{
			*B_p = A[i];
			B_p++;
			negative_count++;
		}
	}

	std::cout << "All negative numbers are:" << std::endl;
	for (int i = 0; i < negative_count; i++)
		std::cout << B[i] << ", ";
	std::cout << std::endl;
	std::cout << std::endl;

	return negative_count;
}

void copy_B_to_A(int *A, int *B, int a, int b)
{
	int *A_ptr;
	A_ptr = A;
	int *B_ptr;
	B_ptr = B;
	do
	{
		*A_ptr = *B_ptr;
		A_ptr++; B_ptr++;
		a--;
	} while (a);
}

void flip(int *A, int n)
{
	do
	{
		for (int i = 1; i < n; i++)
		{
			int k;
			k = A[i];
			A[i] = A[i - 1];
			A[i - 1] = k;
		}
		n--;
	} while (n);
}

int exchange(double *a, double *b)
{
	double c_1;
	double *c = &c_1;
	*c = *a;
	*a = *b;
	*b = *c;

	return 0;
}

int my_log(int x)
{
	std::cout << "" << std::endl;
	std::cout << "log(x) = " << log(x) << std::endl;
	std::cout << "" << std::endl;

	return setup();
}

int root(int x)
{
	std::cout << "sqrt(x) = " << sqrt(x) << std::endl;

	return setup();
}

int my_summ(double a, double b)
{
	std::cout << "" << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "" << std::endl;

	return setup();
}

double my_sin(long double x)
{
	long double mn = x;
	double s = x;
	const long double pi = 3.14159;
	double *p = &s;


	for (int n = 1; n < 9999999; n++)
	{
		mn *= (pow(x, 2)) / (2 * n * (2 * n + 1)) * (-1);
		s += mn;
	}

	std::cout << "" << std::endl;
	std::cout << "Ansver: " << *p << std::endl;
	std::cout << "" << std::endl;

	return setup();
}

double my_pow(double x, double n)
{
	int a = x;
	for (int i = 1; i < n; i++)
		a *= x;

	std::cout << "" << std::endl;
	std::cout << "Ansver: " << a << std::endl;
	std::cout << "" << std::endl;

	return setup();
}

int setup()
{
	double a = 0;
	double b = 0;
	double n = 0;
	int A[100];
	int B[7] = { 1,2,3,4,5,6,7 };
	int B_lenght = 7;
	int C[10] = { 0,9,8,7,6,5,4,3,2,1 };
	int C_lenght = 10;
	std::cout << "Please choose one:" << std::endl;
	std::cout << std::endl;
	std::cout << "1 - add numbers" << std::endl;
	std::cout << "2 - raise to degree" << std::endl;
	std::cout << "3 - extract root" << std::endl;
	std::cout << "4 - calculate the logarithm" << std::endl;
	std::cout << "5 - find sine" << std::endl;
	std::cout << "6 - exchange values: a and b" << std::endl;
	std::cout << "7 - flip the array" << std::endl;
	std::cout << "8 - copy array B to array A" << std::endl;
	std::cout << "9 - display negative numbers of the array" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "10 - EXIT" << std::endl;
	std::cout << "" << std::endl;
	int choise;
	std::cin >> choise;

	do
	{
		if (choise < 1 || choise > 10)
		{
			std::cout << "" << std::endl;
			std::cout << "Please choose correctly!" << std::endl;
			std::cout << "" << std::endl;
			std::cin >> choise;
		}
	} while (choise < 1 || choise > 10);

	switch (choise)
	{
	case 1:
		std::cout << "" << std::endl;
		std::cout << "Please enter a:" << std::endl;
		std::cin >> a;
		std::cout << "" << std::endl;
		std::cout << "Now enter b:" << std::endl;
		std::cin >> b;
		std::cout << "" << std::endl;
		my_summ(a, b);
		std::cout << "" << std::endl;
		break;
	case 2:
		std::cout << "" << std::endl;
		std::cout << "Please enter your number:" << std::endl;
		std::cin >> a;
		std::cout << "" << std::endl;
		std::cout << "Now enter degree:" << std::endl;
		std::cin >> n;
		std::cout << "" << std::endl;
		my_pow(a, n);
		std::cout << "" << std::endl;
		break;
	case 3:
		std::cout << "" << std::endl;
		std::cout << "Please enter x:" << std::endl;
		std::cin >> a;
		std::cout << "" << std::endl;
		root(a);
		break;
	case 4:
		std::cout << "" << std::endl;
		std::cout << "Please enter x:" << std::endl;
		std::cin >> a;
		std::cout << "" << std::endl;
		my_log(a);
		break;
	case 5:
		std::cout << "" << std::endl;
		std::cout << "Please enter x:" << std::endl;
		std::cin >> a;
		std::cout << "" << std::endl;
		my_sin(a);
		break;
	case 6:
		std::cout << "Please enter a:" << std::endl;
		std::cin >> a;
		std::cout << "" << std::endl;
		std::cout << "Now enter b:" << std::endl;
		std::cin >> b;
		std::cout << "" << std::endl;
		std::cout << "a = " << a << "  b = " << b << std::endl;
		std::cout << "Changing..." << std::endl;
		exchange(&a, &b);
		std::cout << "" << std::endl;
		std::cout << "a = " << a << "  b = " << b << std::endl;
		std::cout << "" << std::endl;
		setup();
	case 7:
		std::cout << "" << std::endl;
		std::cout << "what is the length of the array?" << std::endl;
		std::cin >> n;
		std::cout << "" << std::endl;
		std::cout << "Now enter the array:" << std::endl;
		for (int i = 0; i < n; i++)
			std::cin >> A[i];
		std::cout << "" << std::endl;
		std::cout << "Your array is:" << std::endl;
		for (int i = 0; i < n; i++)
			std::cout << A[i];
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "Changing..." << std::endl;
		flip(A, n);
		std::cout << "" << std::endl;
		std::cout << "New array is:" << std::endl;
		for (int i = 0; i < n; i++)
			std::cout << A[i];
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		setup();
		break;
	case 8:
		std::cout << "" << std::endl;
		std::cout << "Array A:" << std::endl;
		for (int i = 0; i < 7; i++)
			std::cout << B[i];
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "Array B:" << std::endl;
		for (int i = 0; i < 10; i++)
			std::cout << C[i];
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "Copy B to A..." << std::endl;
		copy_B_to_A(B, C, B_lenght, C_lenght);
		std::cout << "" << std::endl;
		std::cout << "Array A:" << std::endl;
		for (int i = 0; i < 7; i++)
			std::cout << B[i];
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		setup();
		break;
	case 9:
		std::cout << "" << std::endl;
		std::cout << "what is the length of the array?" << std::endl;
		std::cin >> n;
		std::cout << "" << std::endl;
		std::cout << "Now enter the array:" << std::endl;
		for (int i = 0; i < n; i++)
			std::cin >> A[i];
		std::cout << "" << std::endl;
		negativs(A, n);
		setup();
		break;
	case 10:
		return 0;
	default:
		break;
	}
	return 0;
}

int main()
{
	setup();

	return 0;
}