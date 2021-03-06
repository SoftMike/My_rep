#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>


int one();
int two();
int three();
int four();
int five();

int setup()
{
	int choise;
	std::cout << "" << std::endl;
	std::cout << "What need to do next?" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "1 - Find groups in the array that has 5 characters" << std::endl;
	std::cout << "2 - Print decimal numbers in ascending order" << std::endl;
	std::cout << "3 - Display characters of which the entering text is consist in alphabetical order" << std::endl;
	std::cout << "4 - Display number of word that was choosen after entering a number" << std::endl;
	std::cout << "5 - Display the word which has more of them characters. Display number of this word and position after which this word starts" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "6 - EXIT" << std::endl;

	std::cout << "" << std::endl;
	do
	{
		std::cin >> choise;
		std::cin.ignore(std::numeric_limits<size_t>::max(), '\n');
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
			return false;
		default:
			std::cout << "Please do the right choise..." << std::endl;
			break;
		}
	} while (choise < 0 || choise > 6);

	return 0;
}

int one()
{
	char A[100];
	char *q;
	int groups = 0;

	q = A;

	std::cout << "" << std::endl;
	std::cout << "Please enter your string:" << std::endl;
	std::cout << "" << std::endl;

	gets_s(A);
	std::cout << "" << std::endl;

	int l = strlen(A);
	A[l] = ' ';

	int n = 0;

	for (int i = 0; i <= l; i++)
	{
		n++;
		if (*q == ' ')
		{
			if (n != 6)
				n = 0;
			else
			{
				groups++;
				n = 0;
			}
		}
		q++;
	}

	std::cout << "Groups with 5 characters are: " << groups << std::endl;
	std::cout << "" << std::endl;

	setup();

	return 0;
}

int two()
{
	int n=0;

	std::cout << "" << std::endl;
	std::cout << "How many numbers are you need?" << std::endl;
	std::cout << "" << std::endl;
	std::cin >> n;
	std::cout << "" << std::endl;
	std::cout << "Please enter your numbers with point:" << std::endl;
	std::cout << "" << std::endl;

	double *A = new double[n];

	for (int i = 0; i < n; i++)
		std::cin >> A[i];

	for (int i = 1; i<n; i++)
		for (int o = 1; o < n; o++)
			if (A[o] < A[o - 1])
			{
				double a;
				a = A[o - 1];
				A[o - 1] = A[o];
				A[o] = a;
			}

	std::cout << "" << std::endl;
	std::cout << "Sort results:" << std::endl;
	std::cout << "" << std::endl;

	for (int i = 0; i < n; i++)
		std::cout << A[i] << std::endl;

	std::cout << "" << std::endl;

	delete[] A;
	A = nullptr;

	setup();

	return 0;
}

int three()
{
	char A[200];
	std::cout << "Please enter yout text but no more than 200 characters:" << std::endl;
	std::cout << "" << std::endl;
	gets_s(A);
	int n = strlen(A);

	for (int i = 1; i<n; i++)
		for (int o = 1; o < n; o++)
			if (A[o] < A[o - 1])
			{
				char a;
				a = A[o - 1];
				A[o - 1] = A[o];
				A[o] = a;
			}

	std::cout << "" << std::endl;
	std::cout << "Sort results:" << std::endl;


	for (int i = 0; i < n; i++)
	{
		std::cout << A[i] << std::endl;
		if (A[i] == ' ')
			i++;
	}


	setup();

	return 0;
}

int four()
{
	char A[200];
	std::cout << "" << std::endl;
	std::cout << "Please, enter your text:" << std::endl;
	std::cout << "" << std::endl;
	gets_s(A);
	int l = strlen(A);
	int n;
	int spaces=0;
	std::cout << "Enter your number, but no more than " << l << " characters:" << std::endl;
	std::cin >> n;


	for (int i = 0; i < n; i++)
	{
		if (A[i] == ' ')
			spaces++;
	}

	std::cout << "" << std::endl;
	std::cout << "Your word number:" << std::endl;
	std::cout << spaces+1 << std::endl;
	std::cout << "" << std::endl;

	setup();

	return 0;
}

int five()
{
	char A[200];
	std::cout << "" << std::endl;
	std::cout << "Please, enter your text:" << std::endl;
	std::cout << "" << std::endl;
	gets_s(A);
	int l = strlen(A);
	int a = 0; int b = 0;
	int position = 0; int biggest_word = 1;

	for (int i = 0; i < l; i++)
	{
		if (A[i] != ' ')
		{
			b++;
			if (a < b)
				a = b;
		}
		else
			b = 0;
	}

	for (int i = 0; i < l; i++)
	{
		if (A[i] != ' ')
			b++;
		else
		{
			if (b != a)
			{
				biggest_word++;
				b = 0;
			}
			else
			{
				position = i - a;
				break;
			}
		}
	}

	std::cout << "" << std::endl;
	std::cout << "The biggest word number " << biggest_word << " has " << a << " characters, and starts from " << position << " position in the array." << std::endl;

	setup();

	return 0;
}


int main()
{

	setup();

	return 0;
}