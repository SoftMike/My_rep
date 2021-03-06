#include "stdafx.h"
#include <iostream>
#include <ctime>


int one();
int two();
int three();


int setup()
{
	int choise;
	std::cout << "" << std::endl;
	std::cout << "What need to do next?" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "1 - Assign value 0 for 'k' member of array (B) if all members of 'k' column of the matrix equal to 0." << std::endl;
	std::cout << "2 - In the matrix N x M need to change to each other strings which has maximum and minimum value of matrix." << std::endl;
	std::cout << "3 - In the matrix M x N need to display the biggest values in the strings on the main diagonal." << std::endl;
	std::cout << "" << std::endl;
	std::cout << "4 - EXIT" << std::endl;

	std::cout << "" << std::endl;
	do
	{
		std::cin >> choise;
		std::cin.ignore(std::numeric_limits<size_t>::max(), '\n');
		std::cout << std::endl;
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
			return false;
		default:
			std::cout << "Please do the right choise..." << std::endl;
			break;
		}
	} while (choise < 0 || choise > 4);

	return 0;
}

int one()
{
	int n = 0, m = 0;
	int zero = 0;

	std::srand(std::time(NULL));

	std::cout << "Need matrix N x M..." << std::endl;
	std::cout << std::endl;
	std::cout << "Please, enter n:" << std::endl;
	std::cin >> n;
	std::cout << std::endl;
	std::cout << "Please, enter m:" << std::endl;
	std::cin >> m;

	int **A = new int *[n];
	for (int i = 0; i < n; i++)
		A[i] = new int[m];

	int *B = new int[n];

	for (int i = 0; i < n; i++)
		for (int k = 0; k < m; k++)
			A[i][k] = rand() % 2;

	std::cout << "Random generation of Matrix N x M:" << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < m; k++)
			std::cout << A[i][k] << " ";
		std::cout << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < m; k++)
		{
			if (A[i][k] == 0)
				zero++;
		}
		if (zero == m)
			B[i] = 0;
		else
			B[i] = 1;
		zero = 0;
	}

	std::cout << "Array B:" << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < n; i++)
		std::cout << B[i] << std::endl;

	//deleting the arrays:

	for (int i = 0; i < n; i++)
		delete[] A[i];
	delete[] A;
	A = NULL;
	delete[] B;
	B = NULL;

	setup();

	return 0;
}

int two()
{
	int n = 0, m = 0;

	std::srand(std::time(NULL));

	std::cout << "Need matrix N x M..." << std::endl;
	std::cout << std::endl;
	std::cout << "Please, enter n:" << std::endl;
	std::cin >> n;
	std::cout << std::endl;
	std::cout << "Please, enter m:" << std::endl;
	std::cin >> m;

	int **A = new int *[n];
	for (int i = 0; i < n; i++)
		A[i] = new int[m];

	for (int i = 0; i < n; i++)
		for (int k = 0; k < m; k++)
			A[i][k] = rand() % 1001;

	int max = A[0][0]; int min = A[0][0];

	std::cout << "Random generation of Matrix N x M:" << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < m; k++)
		{
			std::cout << A[i][k];
			if (A[i][k] > 0 && A[i][k] < 10)
				std::cout << "    ";
			if (A[i][k] > 9 && A[i][k] < 100)
				std::cout << "   ";
			if (A[i][k] > 99 && A[i][k] < 1000)
				std::cout << "  ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < n; i++)
		for (int k = 1; k < m; k++)
		{
			if (min > A[i][k])
				min = A[i][k];
			if (max < A[i][k])
				max = A[i][k];
		}


	int max_string_index = 0;
	int min_string_index = 0;
	int iter_max = 0, iter_min = 0;

	for (int i = 0; i < n; i++)
		for (int k = 0; k < m; k++)
		{
			if (A[i][k] == max)
			{
				max_string_index = i;
				iter_max++;
			}
			if (A[i][k] == min)
			{
				min_string_index = i;
				iter_min++;
			}
		}


	if (iter_max == 1 && iter_min == 1)
	{
		std::cout << std::endl;
		std::cout << "Max value: " << max << ", in the " << max_string_index + 1 << " string. Min value: " << min << ", in the " << min_string_index + 1 << " string." << std::endl;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "The array has three or more strings with the biggest and the smallest values of the matrix. Please, TRY AGAIN!" << std::endl;
		setup();
	}

	std::cout << std::endl;
	std::cout << "We change this strings to each other:" << std::endl;
	std::cout << std::endl;

	if (max_string_index == min_string_index)
	{
		std::cout << "Maximal and minimal values are situated in the same string." << std::endl;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			int t;
			t = A[max_string_index][i];
			A[max_string_index][i] = A[min_string_index][i];
			A[min_string_index][i] = t;
		}

		for (int i = 0; i < n; i++)
		{
			for (int k = 0; k < m; k++)
			{
				std::cout << A[i][k];
				if (A[i][k] > 0 && A[i][k] < 10)
					std::cout << "    ";
				if (A[i][k] > 9 && A[i][k] < 100)
					std::cout << "   ";
				if (A[i][k] > 99 && A[i][k] < 1000)
					std::cout << "  ";
			}
			std::cout << std::endl;
		}
	}

	for (int i = 0; i < n; i++)
		delete[] A[i];
	delete[] A;
	A = NULL;

	std::cout << std::endl;

	setup();

	return 0;
}

int three()
{
	int n = 0, m = 0;
	int max=0;

	std::srand(std::time(NULL));

	std::cout << "Need matrix N x M..." << std::endl;
	std::cout << std::endl;
	std::cout << "Please, enter n:" << std::endl;
	std::cin >> n;
	std::cout << std::endl;
	std::cout << "Please, enter m:" << std::endl;
	std::cin >> m;
	std::cout << std::endl;

	int **A = new int *[n];
	for (int i = 0; i < n; i++)
		A[i] = new int[m];

	for (int i = 0; i < n; i++)
		for (int k = 0; k < m; k++)
			A[i][k] = rand() % 1000;

	std::cout << "Generating matrix:" << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < m; k++)
		{
			std::cout << A[i][k];
			if (A[i][k] > 0 && A[i][k] < 10)
				std::cout << "    ";
			if (A[i][k] > 9 && A[i][k] < 100)
				std::cout << "   ";
			if (A[i][k] > 99 && A[i][k] < 1000)
				std::cout << "  ";
		}
		std::cout << std::endl;
	}

	int d = 0;

	for (int i = 0; i < n; i++)
	{
		int max = 0;
		int imax = 0;
		for (int k = 0; k < m; k++)
		{
			if (max < A[i][k])
			{
				max = A[i][k];
				imax = k;
			}
		}
		int t = 0;
		t = A[i][d];
		A[i][d] = A[i][imax];
		A[i][imax] = t;

		d++;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Sort result:" << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < m; k++)
		{
			std::cout << A[i][k];
			if (A[i][k] > 0 && A[i][k] < 10)
				std::cout << "    ";
			if (A[i][k] > 9 && A[i][k] < 100)
				std::cout << "   ";
			if (A[i][k] > 99 && A[i][k] < 1000)
				std::cout << "  ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < n; i++)
		delete[] A[i];
	delete[] A;
	A = NULL;

	std::cout << std::endl;

	setup();

	return 0;
}


int main()
{
	setup();

	return 0;
}