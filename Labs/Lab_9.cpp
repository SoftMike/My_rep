#include "stdafx.h"
#include <iostream>
#include <vector>

int iter_sum(int *A, int n)
{
	int a = 0;

	for (int i = 0; i < n; i++)
		a += A[i];

	return a;
}

int rec_sum(int *A, int n, int a = 0)
{
	n--;
	a += A[n];

	if (n == 0)
		return a;

	rec_sum(A, n, a);
}



int iter_com(int *A, int n)
{
	int a = 1;

	for (int i = 0; i < n; i++)
		a *= A[i];

	return a;
}

int rec_com(int *A, int n, int a = 1)
{
	n--;
	a *= A[n];

	if (n == 0)
		return a;

	rec_com(A, n, a);
}



int numb_count_iter(int x, int n = 1)
{
	do
	{
		x = x / 10;
		if (x > 0)
			n++;
	} while (x > 0);

	return n;
}

int numb_count_rec(int x, int n = 1)
{
	x = x / 10;
	if (x > 0)
		n++;
	else
		return n;

	numb_count_rec(x, n);
}



double iter_root(double n)
{
	double x = n;

	for (n--; n > 0; n--)
	{
		x = sqrt(x) + n;
	}

	return sqrt(x);
}

double rec_root(double n, double x = 0)
{
	if (x == n)
		return x;
	return x + sqrt(rec_root(n, x + 1));
}



double last_iter(double n)
{
	double a = 1;
	double x = 0;
	for (int i = 1; i <= n; i++)
	{
		a *= i;
		x += 1 / a;
	}
	return x;
}

double last_rec(double n, double x = 1, double a = 1)
{
	if (x == n)
		return 1 / (a*x);

	a *= x;

	return 1 / a + last_rec(n, x + 1, a);
}



int main()
{
	/*
	- 5 Tasks was done by two ways which including recursive method.
	*/

	return 0;
}