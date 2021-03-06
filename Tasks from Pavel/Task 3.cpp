#include "stdafx.h"
#include <iostream>
#include <string>

//My functions:

int char_int(char *array)
{
	/*
	- Number no more than 999999999;
	- Quantity of characters no more than 9;
	- Error code: -1.
	*/
	int out_int = 0;
	int l = strlen(array);
	int check = 0;
	char *n;
	n = array;

	if (l > 9)
		return -1;

	for (int i = 0; i < l; i++)
	{
		if (*n != '1' && *n != '2' && *n != '3' && *n != '4' && *n != '5' && *n != '6' && *n != '7' && *n != '8' && *n != '9' && *n != '0')
		{
			check++;
		}
		n++;
	}

	n = array;


	if (check == 0)
	{
		for (int i = 0; i < l; i++, n++)
		{
			if (i == 0)
			{
				if (*n == '1')
					out_int = 1;
				if (*n == '2')
					out_int = 2;
				if (*n == '3')
					out_int = 3;
				if (*n == '4')
					out_int = 4;
				if (*n == '5')
					out_int = 5;
				if (*n == '6')
					out_int = 6;
				if (*n == '7')
					out_int = 7;
				if (*n == '8')
					out_int = 8;
				if (*n == '9')
					out_int = 9;
				if (*n == '0')
					return -1;
			}
			else
			{
				if (*n == '1')
					out_int = out_int * 10 + 10 - 9;
				if (*n == '2')
					out_int = out_int * 10 + 10 - 8;
				if (*n == '3')
					out_int = out_int * 10 + 10 - 7;
				if (*n == '4')
					out_int = out_int * 10 + 10 - 6;
				if (*n == '5')
					out_int = out_int * 10 + 10 - 5;
				if (*n == '6')
					out_int = out_int * 10 + 10 - 4;
				if (*n == '7')
					out_int = out_int * 10 + 10 - 3;
				if (*n == '8')
					out_int = out_int * 10 + 10 - 2;
				if (*n == '9')
					out_int = out_int * 10 + 10 - 1;
				if (*n == '0')
					out_int = out_int * 10;
			}
		}
		return out_int;
	}
	else
		return -1;

	return 0;
}

void double_char(double a, char *p)
{
	char A[20] = {};
	double ost = 0;
	int cel, c_ost, t = 0, i;
	char P_1[10], P_2[10];

	cel = static_cast<int>(a);
	ost = a - static_cast<double>(cel);
	if (ost != 0)
	{
		ost = ost * 10000;

		c_ost = static_cast<int>(ost < 0 ? ost - 0.5 : ost + 0.5);

		while ((c_ost % 10) == 0)
			c_ost = c_ost / 10;

		sprintf_s(P_1, "%d", cel);
		sprintf_s(P_2, "%d", c_ost);
	}
	else
	{
		sprintf_s(P_1, "%d", cel);
		sprintf_s(P_2, "%d", 0);
	}

	for (i = 0; ; i++)
	{
		if (P_1[i] == '\0')
		{
			A[i] = '.';
			for (i = i + 1, t = 0; t<2; i++, t++)
			{
				A[i] = P_2[t];
				if (P_2[t] == '\0')
				{
					A[i] = '\0';
					break;
				}
			}
			break;
		}
		A[i] = P_1[i];
	}

	for (i = 0; i < strlen(A); i++)
	{
		*p = A[i];
		p++;
	}
	*p = '\0';
}

int my_strlen(const char *string)
{
	int n = 0;
	for (int i = 0; ; i++)
	{
		if (string[i] != '\0')
			n++;
		else
			break;
	}

	return n;
}

int my_strcmp(const char *string1, const char *string2)
{
	int len_string1 = 0;
	int len_string2 = 0;

	for (int i = 0; ; i++)
	{
		if (string1[i] != '\0')
			len_string1++;
		else
			break;
	}

	for (int i = 0; ; i++)
	{
		if (string2[i] != '\0')
			len_string2++;
		else
			break;
	}

	if (len_string1 == len_string2)
	{
		int n = len_string1;
		for (int i = 0; i < len_string1; i++)
			if (string1[i] == string2[i])
				n--;
		if (n == 0)
			return 0;
	}

	if (len_string1 > len_string2)
		return 1;

	if (len_string1 < len_string2)
		return -1;

}

void my_strcpy(char *string2, char *string1)
{
	for (int i = 0; ; i++)
	{
		if (string1[i] == '\0')
		{
			string2[i] = '\0';
			break;
		}
		string2[i] = string1[i];
	}
}

void my_strcat(char *string2, char *string1)
{
	char *s1; char *s2;
	s2 = string2; s1 = string1;
	do
		s2++;
	while (*s2 != '\0');

	do
	{
		*s2 = *s1;
		s1++; s2++;
	} while (*s1 != '\0');

	*s2 = '\0';
}

char *my_strstr(char *string2, char *string1)
{
	char *s1, *s2, *p;
	s1 = string1; s2 = string2;

	int n = 0;
	for (int i = 0; ; i++)
	{
		if (string1[i] != '\0')
			n++;
		else
			break;
	}

	do
	{
		s2++;
	} while (*s2 != *s1);

	p = s2;

	do
	{
		if (*s2 == *s1)
		{
			n--;
			s1++; s2++;
		}
	} while (*s1 != '\0');

	if (n == 0)
		return p;
	else
		return p = NULL;
}

char *my_strchr(char *string, int number)
{
	char *ptr;
	int n = 0;

	for (int i = 0; ; i++)
	{
		if (string[i] != '\0')
			n++;
		else
			break;
	}

	int n2 = n;

	for (int i = 0; i < n; i++)
	{
		if (string[i] == static_cast<char>(number))
		{
			ptr = &string[i];
			return ptr;
		}
		n2--;
	}
	if (n2 == 0)
		return NULL;
}

void my_strncat(char *string2, char *string1, int n)
{
	do
		string2++;
	while (*string2 != '\0');

	do
	{
		*string2 = *string1;
		string1++; string2++;
		n--;
	} while (n != 0);

	*string2 = '\0';
}

void my_strncpy(char *string1, char *string2, int n)
{
	for (int i = 0; i < n; i++)
	{
		string1[i] = string2[i];

		if (string1[i] == '\0' || string2[i] == '\0')
		{
			string1[i] = '\0';
			break;
		}
	}
}

//Another task:

int setup();
void one();
void two();
void three();
void four();
void five();
void six();


int setup()
{
	int choise;
	std::cout << "" << std::endl;
	std::cout << "Please, choose the task:" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "1 - display quantity of one character in the text." << std::endl;
	std::cout << "2 - delete character from the text." << std::endl;
	std::cout << "3 - change some character to another." << std::endl;
	std::cout << "4 - change some character to entering string." << std::endl;
	std::cout << "5 - displey all words in the text." << std::endl;
	std::cout << "6 - combine input strings." << std::endl;
	std::cout << "" << std::endl;
	std::cout << "7 - EXIT" << std::endl;

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
			return false;
		default:
			std::cout << "Please do the right choise..." << std::endl;
			break;
		}
	} while (choise < 0 || choise > 6);

	return 0;
}

void one()
{
	char A[100];
	char n;
	int l = 0;
	int q = 0;

	std::cout << std::endl;
	std::cout << "Please enter the text but no more than 100 characters:" << std::endl;
	std::cout << std::endl;
	gets_s(A);

	l = strlen(A);

	std::cout << std::endl;
	std::cout << "Now enter the character:" << std::endl;
	std::cout << std::endl;
	std::cin >> n;
	std::cin.ignore(std::numeric_limits<size_t>::max(), '\n');

	for (int i=0; i < l; i++)
	{
		if (A[i] == n)
			q++;
	}

	std::cout << std::endl;
	std::cout << "Character " << n << " is founds " << q << " times in the text." << std::endl;
	std::cout << std::endl;
}

void two()
{
	char A[100];
	char n;
	int l = 0;

	std::cout << std::endl;
	std::cout << "Please enter the text but no more than 100 characters:" << std::endl;
	std::cout << std::endl;
	gets_s(A);

	l = strlen(A);

	std::cout << std::endl;
	std::cout << "Now enter the character:" << std::endl;
	std::cout << std::endl;
	std::cin >> n;
	std::cin.ignore(std::numeric_limits<size_t>::max(), '\n');

	for (int i = 0; i < l; i++)
	{
		if (A[i] == n)
		{
			for (int k = i; k < l; k++)
			{
				A[k] = A[k + 1];
			}
			l--;
		}
	}

	A[l] = '\0';

	std::cout << "" << std::endl;
	std::cout << "Result:" << std::endl;
	std::cout << "" << std::endl;
	std::cout << A << std::endl;
	std::cout << "" << std::endl;
}

void three()
{
	char A[100];
	char n;
	char m;
	int l = 0;

	std::cout << std::endl;
	std::cout << "Please enter the text but no more than 100 characters:" << std::endl;
	std::cout << std::endl;
	gets_s(A);


	l = strlen(A);

	std::cout << std::endl;
	std::cout << "Now enter the character:" << std::endl;
	std::cout << std::endl;
	std::cin >> n;
	std::cin.ignore(std::numeric_limits<size_t>::max(), '\n');

	std::cout << std::endl;
	std::cout << "Now enter the character to which you want to change the previous one:" << std::endl;
	std::cout << std::endl;
	std::cin >> m;
	std::cin.ignore(std::numeric_limits<size_t>::max(), '\n');

	for (int i = 0; i < l; i++)
	{
		if (A[i] == n)
			A[i] = m;
	}

	std::cout << "" << std::endl;
	std::cout << "Result:" << std::endl;
	std::cout << "" << std::endl;
	std::cout << A << std::endl;
	std::cout << "" << std::endl;
}

void four()
{
	char A[100];
	char n;
	char A2[100];
	int l = 0;
	int l2 = 0;

	std::cout << std::endl;
	std::cout << "Please enter the text but no more than 100 characters:" << std::endl;
	std::cout << std::endl;
	gets_s(A);


	l = strlen(A);

	std::cout << std::endl;
	std::cout << "Now enter the character:" << std::endl;
	std::cout << std::endl;
	std::cin >> n;
	std::cin.ignore(std::numeric_limits<size_t>::max(), '\n');

	std::cout << std::endl;
	std::cout << "Now enter the string to which you want to change the previous character:" << std::endl;
	std::cout << std::endl;
	gets_s(A2);

	l2 = strlen(A2);

	for (int i = 0; i < l; i++)
	{
		if (A[i] == n)
		{

			for (int a = 0; a < l2 - 1; a++)
			{
				for (int k = l; k > i; k--)
					A[k] = A[k - 1];
				l++;
				A[l] = '\0';
			}

			for (int v = 0; v < l2; v++)
			{
				A[i] = A2[v];
				i++;
			}
		}
	}

	std::cout << "" << std::endl;
	std::cout << "Result:" << std::endl;
	std::cout << "" << std::endl;
	std::cout << A << std::endl;
	std::cout << "" << std::endl;
}

void five()
{
	char A[100];
	char *q;
	q = A;

	std::cout << std::endl;
	std::cout << "Please enter the text but no more than 100 characters:" << std::endl;
	std::cout << std::endl;
	gets_s(A);
	std::cout << std::endl;

	do
	{
		if (*q != ' ')
			std::cout << *q;
		else
			std::cout << std::endl;
		q++;
	} while (*q != '\0');
	std::cout << std::endl;
}

void six()
{
	int n = 0;
	std::cout << "" << std::endl;
	std::cout << "How many strings do you need?" << std::endl;
	std::cout << "" << std::endl;
	std::cin >> n;
	std::cin.ignore(std::numeric_limits<size_t>::max(), '\n');
	std::cout << "" << std::endl;

	std::string *A = new std::string[n];
	char ALL[1000];

	for (int i = 0; i < n; i++)
	{
		std::cout << "" << std::endl;
		std::cout << "Now enter " << i+1 << " string:" << std::endl;
		std::getline(std::cin, A[i]);
		std::cout << "" << std::endl;
	}

	int ALLn = 0;

	for (int i = 0; i < n; i++)
	{
		for (int i2 = 0; A[i][i2] != '\0'; i2++)
		{
			ALL[ALLn] = A[i][i2];
			ALLn++;
		}
		ALL[ALLn] = ' ';
		ALLn++;
	}

	ALL[ALLn] = '\0';

	std::cout << ALL << std::endl;

	delete[] A;
	A = NULL;
}


int main()
{
	setup();

    return 0;
}

