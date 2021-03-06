#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <cstdio>

int i = 0, k = 0, n = 0, l = 0;
char A[100];
char B[100];
char C[100];

int one();
int two();
int three();
int four();
int five();
int six();
int seven();
int eight();
int nine();
int ten();
int eleven();
int tvelve();
int thirteen();
int fourteen();
int fifteen();
int setup();

int new_array()
{
	std::cout << "" << std::endl;
	std::cout << "Select new array but no more than 100:" << std::endl;
	std::cout << "" << std::endl;
	gets_s(A);
	std::cout << "" << std::endl;
	setup();
	return 0;
}

int setup()
{
	int choise;
	std::cout << "" << std::endl;
	std::cout << "What need to do next?" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "1 - sort numbers first then characters" << std::endl;
	std::cout << "2 - sort the characters  in reverse order" << std::endl;
	std::cout << "3 - more of them numbers sort" << std::endl;
	std::cout << "4 - sort array from minimal to maximal" << std::endl;
	std::cout << "5 - one time numbers of array" << std::endl;
	std::cout << "6 - move elements of array on /n/ times in right" << std::endl;
	std::cout << "7 - move elements of array on /n/ times in left" << std::endl;
	std::cout << "8 - negative numbers first" << std::endl;
	std::cout << "9 - separating array on numbers and characters" << std::endl;
	std::cout << "10 - checking for array simmetry" << std::endl;
	std::cout << "11 - find some elements in first array that are no in the second array" << std::endl;
	std::cout << "12 - determine number of inversions" << std::endl;
	std::cout << "13 - delete duplicate characters from the array" << std::endl;
	std::cout << "14 - display quantity of all elements of the array" << std::endl;
	std::cout << "15 - display all elements in alphabet order" << std::endl;
	std::cout << "16 - select new array" << std::endl;
	std::cout << "17 - EXIT..." << std::endl;
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
			ten();
			break;
		case 16:
			new_array();
			break;
		case 11:
			eleven();
			break;
		case 12:
			tvelve();
			break;
		case 13:
			thirteen();
			break;
		case 14:
			fourteen();
			break;
		case 15:
			fifteen();
			break;
		case 17:
			return false;
		default:
			std::cout << "Please do the right choise..." << std::endl;
			break;
		}
	} while (choise < 0 || choise > 17);

	return 0;
}

int one()
{
	l = strlen(A);

	for (i = 0; i < l; i++)
		if (A[i] >= '0' && A[i] <= '9')
		{
			C[i] = '0';
			B[i] = A[i];
		}
		else
		{
			C[i] = A[i];
			B[i] = '0';
		}

	for (i = 1; i<l; i++)
		for (n = 1; n<l; n++)
			if (B[n - 1] == '0')
			{
				k = B[n - 1];
				B[n - 1] = B[n];
				B[n] = k;
			}

	for (i = (l - 1); i > 0; i--)
		for (n = (l - 1); n > 0; n--)
			if (C[n] == '0')
			{
				k = C[n - 1];
				C[n - 1] = C[n];
				C[n] = k;
			}

	for (i = 0; i < l; i++)
		if (B[i] == '0')
			A[i] = C[i];
		else
			A[i] = B[i];

	for (i = 1; i<l; i++)
		for (n = 1; n<l; n++)
			if (A[n - 1] == ' ')
			{
				k = A[n - 1];
				A[n - 1] = A[n];
				A[n] = k;
			}

	std::cout << "" << std::endl;
	std::cout << "////////// SORT RESULT //////////" << std::endl;
	std::cout << A << std::endl;
	std::cout << "////////////////////////////////" << std::endl;

	setup();

	return 0;
}

int two()
{
	l = strlen(A);

	std::cout << "////////// SORT RESULT //////////" << std::endl;
	std::cout << "" << std::endl;
	for (i = l - 1; i >= 0; i--)
		std::cout << A[i] << std::endl;
	std::cout << "" << std::endl;
	std::cout << "////////////////////////////////" << std::endl;

	setup();
	return 0;
}

int three()
{
	int t, x;
	char k = '0';
	char M[10][2];

	for (i = 0; i < 10; i++)
		M[i][1] = k++;

	for (i = 0; i < 10; i++)
		M[i][0] = '0';

	l = strlen(A);

	for (i = 0; i < l; i++)
		for (k = 0; k < 10; k++)
			if (A[i] == M[k][1])
				M[k][0]++;

	for (i = 1; i<10; i++)
		for (n = 1; n<10; n++)
			if (M[n - 1][0] > M[n][0])
			{
				t = M[n - 1][0];
				x = M[n - 1][1];
				M[n - 1][0] = M[n][0];
				M[n - 1][1] = M[n][1];
				M[n][0] = t;
				M[n][1] = x;
			}

	std::cout << "////////// SORT RESULT //////////" << std::endl;
	if (M[9][0] == M[8][0] && M[9][0] != M[7][0])
	{
		std::cout << "" << std::endl;
		std::cout << "The array has two the most common numbers:" << std::endl;
		std::cout << M[9][1] << " and " << M[8][1] << std::endl;
		std::cout << "" << std::endl;
	}
	if (M[9][0] == M[8][0] && M[9][0] == M[7][0] && M[9][0] != '1' && M[9][0] != M[6][0])
	{
		std::cout << "" << std::endl;
		std::cout << "The most common numbers in the array are:" << std::endl;
		std::cout << M[9][1] << "; " << M[8][1] << " and " << M[7][1] << std::endl;
		std::cout << "" << std::endl;
	}
	if (M[9][0] != M[8][0])
	{
		std::cout << "" << std::endl;
		std::cout << "The most common number:" << std::endl;
		std::cout << M[9][1] << std::endl;
		std::cout << "" << std::endl;
	}
	if (M[9][0] == '1')
	{
		std::cout << "" << std::endl;
		std::cout << "The array has no one common number..." << std::endl;
		std::cout << "" << std::endl;
	}
	if (M[9][0] == M[8][0] && M[9][0] == M[7][0] && M[9][0] == M[6][0])
	{
		std::cout << "" << std::endl;
		std::cout << "The array has more 3 common numbers..." << std::endl;
		std::cout << "" << std::endl;
	}
	std::cout << "////////////////////////////////" << std::endl;

	setup();

	return 0;
}

int four()
{
	l = strlen(A);

	for (i = 1; i<l; i++)
		for (k = 1; k<l; k++)
			if (A[k - 1] > A[k])
			{
				n = A[k - 1];
				A[k - 1] = A[k];
				A[k] = n;
			}

	std::cout << "" << std::endl;
	std::cout << "////////// SORT RESULT //////////" << std::endl;
	for (i = 0; i<l; i++)
		std::cout << A[i] << std::endl;
	std::cout << "////////////////////////////////" << std::endl;

	setup();

	return 0;
}

int five()
{
	int t, x;
	char k = '0';
	char M[10][2];

	for (i = 0; i < 10; i++)
		M[i][1] = k++;

	for (i = 0; i < 10; i++)
		M[i][0] = '0';

	l = strlen(A);

	for (i = 0; i < l; i++)
		for (k = 0; k < 10; k++)
			if (A[i] == M[k][1])
				M[k][0]++;

	for (i = 1; i<10; i++)
		for (n = 1; n<10; n++)
			if (M[n - 1][0] > M[n][0])
			{
				t = M[n - 1][0];
				x = M[n - 1][1];
				M[n - 1][0] = M[n][0];
				M[n - 1][1] = M[n][1];
				M[n][0] = t;
				M[n][1] = x;
			}

	std::cout << "////////// SORT RESULT //////////" << std::endl;
	std::cout << "One time numbers are:" << std::endl;
	for (i = 0; i<10; i++)
		if (M[i][0] == '1')
		{
			std::cout << M[i][1] << std::endl;
		}

	std::cout << "////////////////////////////////" << std::endl;

	setup();

	return 0;
}

int six()
{
	int f, c;
	l = strlen(A);

	std::cout << "" << std::endl;
	std::cout << "Please select /n/:" << std::endl;
	std::cout << "" << std::endl;
	std::cin >> n;
	std::cout << "" << std::endl;

	for (i = 0; i < n; i++)
	{
		f = l - 1;
		c = f - 1;

		k = A[f];
		for (f, c; f > 0, c >= 0; f--, c--)
		{
			A[f] = A[c];
		}
		A[0] = k;

	}

	std::cout << "////////// SORT RESULT //////////" << std::endl;
	std::cout << "Moving array on " << n << " times right:" << std::endl;
	std::cout << A << std::endl;
	std::cout << "////////////////////////////////" << std::endl;
	std::cout << "" << std::endl;

	setup();

	return 0;
}

int seven()
{
	int f, c;
	l = strlen(A);

	std::cout << "Please select /n/:" << std::endl;
	std::cout << "" << std::endl;
	std::cin >> n;
	std::cout << "" << std::endl;

	for (i = 0; i < n; i++)
	{
		f = 0;
		c = 1;

		k = A[0];
		for (f, c; f < (l - 1), c < l; f++, c++)
		{
			A[f] = A[c];
		}
		A[l - 1] = k;

	}

	std::cout << "////////// SORT RESULT //////////" << std::endl;
	std::cout << "Moving array on " << n << " times left:" << std::endl;
	std::cout << A << std::endl;
	std::cout << "////////////////////////////////" << std::endl;
	std::cout << "" << std::endl;

	setup();

	return 0;
}

int eight()
{
	int A[100];
	int B[100];
	int C[100];
	int t;
	std::cout << "" << std::endl;
	std::cout << "This array works only with numbers..." << std::endl;
	std::cout << "How much numbers have to be in the array?" << std::endl;
	std::cout << "" << std::endl;
	std::cin >> n;
	std::cout << "Now select an array:" << std::endl;
	std::cout << "" << std::endl;
	for (i = 0; i<n; i++)
		std::cin >> A[i];


	for (i = 0; i < n; i++)
		if (A[i] >= 0)
		{
			C[i] = 0;
			B[i] = A[i];
		}
		else
		{
			C[i] = A[i];
			B[i] = 0;
		}

	for (i = 1; i<n; i++)
		for (t = 1; t<n; t++)
			if (C[t - 1] == 0)
			{
				k = C[t - 1];
				C[t - 1] = C[t];
				C[t] = k;
			}

	for (i = (n - 1); i > 0; i--)
		for (t = (n - 1); t > 0; t--)
			if (B[t] == 0)
			{
				k = B[t - 1];
				B[t - 1] = B[t];
				B[t] = k;
			}


	for (i = 0; i < n; i++)
		if (B[i] == 0)
			A[i] = C[i];
		else
			A[i] = B[i];

	std::cout << "////////// SORT RESULT //////////" << std::endl;
	for (i = 0; i<n; i++)
		std::cout << A[i] << std::endl;
	std::cout << "////////////////////////////////" << std::endl;

	setup();

	return 0;
}

int nine()
{
	l = strlen(A);

	for (i = 0; i < l; i++)
		if (A[i] >= '0' && A[i] <= '9')
		{
			C[i] = '0';
			B[i] = A[i];
		}
		else
		{
			C[i] = A[i];
			B[i] = '0';
		}

	for (i = 1; i<l; i++)
		for (n = 1; n<l; n++)
			if (B[n - 1] == '0')
			{
				k = B[n - 1];
				B[n - 1] = B[n];
				B[n] = k;
			}

	for (i = 1; i<l; i++)
		for (n = 1; n<l; n++)
			if (C[n - 1] == '0')
			{
				k = C[n - 1];
				C[n - 1] = C[n];
				C[n] = k;
			}

	std::cout << "" << std::endl;

	for (i = 0; i < l; i++)
	{
		if (B[i] == '0')
			B[i] = ' ';
		if (C[i] == '0')
			C[i] = ' ';
	}

	std::cout << "////////// SORT RESULT //////////" << std::endl;
	std::cout << "Numbers of array:   " << "Characters of array:" << std::endl;
	for (i = 0; i < l; i++)
		std::cout << "             " << B[i] << "                   " << C[i] << std::endl;
	std::cout << "////////////////////////////////" << std::endl;

	setup();

	return 0;
}

int ten()
{
	l = strlen(A);
	int f;
	f = l - 1;

	if (l % 2 == 0)
	{
		std::cout << "" << std::endl;
		std::cout << "////////// SORT RESULT //////////" << std::endl;
		std::cout << "The array is not simmetric..." << std::endl;
		std::cout << "////////////////////////////////" << std::endl;
		std::cout << "" << std::endl;
	}
	else
	{
		f = l - 1;
		k = 0;
		for (i = 0; i < l; i++)
			B[i] = A[i];

		for (n = 0, f; n<(l / 2), f>(l / 2); n++, f--)
			if (A[n] == B[f])
				k++;

		if (k == l / 2)
		{
			std::cout << "" << std::endl;
			std::cout << "////////// SORT RESULT //////////" << std::endl;
			std::cout << "The array is simmetric..." << std::endl;
			std::cout << "////////////////////////////////" << std::endl;
			std::cout << "" << std::endl;
		}
		else
		{
			std::cout << "" << std::endl;
			std::cout << "////////// SORT RESULT //////////" << std::endl;
			std::cout << "The array is not simmetric..." << std::endl;
			std::cout << "////////////////////////////////" << std::endl;
			std::cout << "" << std::endl;
		}
	}

	setup();

	return 0;
}

int eleven()
{
	std::cout << "Please enter the second array:" << std::endl;
	std::cout << "" << std::endl;
	gets_s(B);
	std::cout << "" << std::endl;

	l = strlen(A);

	for (i = 0; i < l; i++)
		C[i] = '0';

	for (i = 0; i < l; i++)
		for (k = 0; k < l; k++)
			if (A[i] == B[k])
				C[i] = A[i];

	for (i = 0; i < l; i++)
		if (C[i] == A[i])
			A[i] = '0';

	for (i = 1; i<l; i++)
		for (k = 1; k<l; k++)
			if (A[k - 1] < A[k])
			{
				n = A[k - 1];
				A[k - 1] = A[k];
				A[k] = n;
			}

	std::cout << "////////// SORT RESULT //////////" << std::endl;
	std::cout << "The smallest elements are:" << std::endl;
	std::cout << "" << std::endl;
	for (i = 2; i >= 0; i--)
		if (A[i] != '0')
			std::cout << A[i] << std::endl;
	std::cout << "" << std::endl;
	std::cout << "////////////////////////////////" << std::endl;

	setup();

	return 0;
}

int tvelve()
{
	int onemore;
	l = strlen(A);

onemore:
	for (i = 0; i<l; i++)
		if (A[i] > '9')
		{
			std::cout << "" << std::endl;
			std::cout << "This array works only with numbers..." << std::endl;
			std::cout << "Please sellect the array of numbers:" << std::endl;
			std::cout << "" << std::endl;
			gets_s(A);
			goto onemore;
		}
	std::cout << "" << std::endl;
	std::cout << "OK!" << std::endl;

	for (i = 1; i < l; i++)
		if (A[i - 1] > A[i])
			k++;

	std::cout << "////////// SORT RESULT //////////" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "In this array there are " << k << " elements of the inverse pairs" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "////////////////////////////////" << std::endl;
	k = 0;

	setup();

	return 0;
}

int thirteen()
{
	l = strlen(A);

	for (i = 0; i < l; i++)
		B[i] = A[i];

	for (i = 0; i < l; i++)
	{
		n = 0;
		for (k = 0; k < l; k++)
			if (A[i] == B[k])
			{
				n++;
				if (n > 1)
					B[i] = '0';
			}
	}

	for (i = 1; i<l; i++)
		for (n = 1; n<l; n++)
			if (B[n - 1] == '0')
			{
				k = B[n - 1];
				B[n - 1] = B[n];
				B[n] = k;
			}

	for (i = 0; i < l; i++)
		if (B[i] == '0')
			break;
		else
			C[i] = B[i];

	std::cout << "////////// SORT RESULT //////////" << std::endl;
	std::cout << C << std::endl;
	std::cout << "////////////////////////////////" << std::endl;

	setup();

	return 0;
}

int fourteen()
{
	char n, o;
	l = strlen(A);

	char B[100][2];
	char C[100][2];

	for (i = 0; i < l; i++)
		B[i][1] = A[i];

	for (i = 0; i < l; i++)
	{
		n = '0';
		for (k = 0; k < l; k++)
			if (A[i] == A[k])
				n++;
		B[i][0] = n;
	}

	for (i = 0; i < l; i++)
	{
		n = 0;
		for (k = 0; k < l; k++)
			if (A[i] == B[k][1])
			{
				n++;
				if (n > 1)
				{
					B[i][1] = '0';
					B[i][0] = '0';
				}
			}
	}

	for (i = 1; i<l; i++)
		for (n = 1; n<l; n++)
			if (B[n - 1][0] == '0' && B[n - 1][1] == '0')
			{
				k = B[n - 1][0];
				o = B[n - 1][1];
				B[n - 1][0] = B[n][0];
				B[n - 1][1] = B[n][1];
				B[n][0] = k;
				B[n][1] = o;
			}
	for (i = 0; i < l; i++)
		std::cout << B[i][0] << "    " << B[i][1] << std::endl;
	n = 0;
	for (i = 0; i < l; i++)
		if (B[i][0] == '0' && B[i][1] == '0')
			break;
		else
		{
			C[i][0] = B[i][0];
			C[i][1] = B[i][1];
			n++;
		}

	std::cout << "////////// SORT RESULT //////////" << std::endl;
	std::cout << "Element:" << "     " << "quantity:" << std::endl;
	std::cout << "" << std::endl;
	for (i = 0; i < n; i++)
		std::cout << "       " << C[i][1] << "    " << C[i][0] << std::endl;
	std::cout << "" << std::endl;
	std::cout << "////////////////////////////////" << std::endl;

	setup();

	return 0;
}

int fifteen()
{
	l = strlen(A);
	int o = 0;

	for (i = 0; i < l; i++)
		B[i] = A[i];

	for (i = 0; i < l; i++)
	{
		n = 0;
		for (k = 0; k < l; k++)
			if (A[i] == B[k])
			{
				n++;
				if (n > 1)
					B[i] = '0';
			}
	}

	for (i = 1; i<l; i++)
		for (n = 1; n<l; n++)
			if (B[n - 1] == '0')
			{
				k = B[n - 1];
				B[n - 1] = B[n];
				B[n] = k;
			}

	for (i = 0; i < l; i++)
		if (B[i] == '0')
			break;
		else
		{
			C[i] = B[i];
			o++;
		}

	for (i = 1; i<o; i++)
		for (k = 1; k<o; k++)
			if (C[k - 1] > C[k])
			{
				n = C[k - 1];
				C[k - 1] = C[k];
				C[k] = n;
			}



	std::cout << "////////// SORT RESULT //////////" << std::endl;
	std::cout << "" << std::endl;
	for (i = 0; i<o; i++)
		std::cout << C[i] << std::endl;
	std::cout << "" << std::endl;
	std::cout << "////////////////////////////////" << std::endl;

	setup();

	return 0;
}

int main()
{

	std::cout << "Select an array but no more than 100 elements:" << std::endl;
	std::cout << "" << std::endl;
	gets_s(A);
	std::cout << "" << std::endl;
	setup();

	return 0;
}
