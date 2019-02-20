#include "stdafx.h"
#include <iostream>
#include <string>

class strings
{
	char *string;
	int strings_count;
	int size;

public:

	strings(int siz = 10)
	{
		size = siz;
		strings_count = 0;
		string = new char[size];
		string[0] = '\0';
	}
	~strings()
	{
		std::cout << "DEST" << std::endl;
		delete [] string;
		string = NULL;
		delete basestring;
		basestring = NULL;
	}
	strings(const strings &obj)
	{
		std::cout << "COPY_DEST" << std::endl;
		string = new char[size];
		string = obj.string;
	}


	void resize_char(char *&mas, int newsize)
	{
		std::cout << "resize: " << newsize << std::endl;
		char *temp = new char[newsize];
		for (int i = 0; i < size; i++)
			temp[i] = mas[i];
		delete[] mas;
		mas = temp;
		size = newsize;
	}
	void add(char *mass)
	{
		int res = (size - strlen(string) - strlen(mass));

		if (res <= 1)
		{
			int size2 = size;
			while (res <= 1)
			{
				size2 *= 2;
				res = (size2 - strlen(string) - strlen(mass));
			}
			resize_char(string, size2);
		}

		if (!strings_count)
			strings_count++;
		int i = 0;
		int m = 0;

		if (string[0])
		{
			while (string[i])
				i++;
			while (mass[m])
				string[i++] = mass[m++];
			string[i++] = ' ';
			string[i] = '\0';
		}
		else
		{
			while (mass[m])
				string[i++] = mass[m++];
			string[i++] = ' ';
			string[i] = '\0';
		}
	}
	void display()
	{
		system("cls");
		if (string[0])
			std::cout << string << std::endl;
		else
		{
			std::cout << std::endl;
			std::cout << "The strings are empty..." << std::endl;
			std::cout << std::endl;
		}
		system("pause");
	}
	void new_string()
	{
		int n = strlen(string);
		string[n++] = '\n';
		string[n] = '\0';
		strings_count++;
	}
	void delete_string()
	{
		if (string[0])
		{
			std::cout << std::endl;
			std::cout << "Which string need delete?" << std::endl;

			int i = 0;
			int n = 1;
			int del_n = 0;
			char *temp = NULL;

			while (string[i])
			{
				if (i == 0)
					std::cout << "\n" << n++ << ": ";
				if (string[i] == '\n')
				{
					std::cout << "\n" << n++ << ": ";
					i++;
				}
				std::cout << string[i++];
			}

			std::cout << std::endl;
			std::cout << std::endl;

			i = 0;
			n = 0;

			std::cin >> del_n;

			if (strings_count != 1 && strings_count != 0)
			{
				while (string[i])
				{
					if (n == del_n)
					{
						temp = &string[i];
						break;
					}
					if (string[i++] == '\n')
						n++;
				}

				i = 0;
				n = 0;

				while (string[i])
				{
					if (n == del_n - 1)
						break;
					if (string[i++] == '\n')
						n++;
				}
				n = 0;
				if (temp)
				{
					while (temp[n])
						string[i++] = temp[n++];
					string[i] = '\0';
				}
				else
					string[i - 1] = '\0';

				strings_count--;
			}
			else
			{
				string[0] = '\0';
				if(strings_count > 0)
					strings_count--;
			}
			std::cout << std::endl;
			std::cout << "Done!" << std::endl;
		}
		else
		{
			std::cout << std::endl;
			std::cout << "The strings are empty..." << std::endl;
			std::cout << std::endl;
		}
	}
	void clear()
	{
		string[0] = '\0';
		strings_count = 0;
		std::cout << std::endl;
		std::cout << "Done!" << std::endl;
		system("pause");
	}
	void info()
	{
		system("cls");
		std::cout << std::endl;
		std::cout << "Characters:   " << strlen(string) << std::endl;
		std::cout << "Strings:      " << strings_count << std::endl;
		std::cout << std::endl;
		system("pause");
	}
	void display_current_string()
	{
		if (!string[0])
		{
			std::cout << std::endl;
			std::cout << "The strings are empty..." << std::endl;
			std::cout << std::endl;
			return;
		}
		else if (strings_count == 1)
		{
			std::cout << std::endl;
			std::cout << string << std::endl;
			std::cout << std::endl;
		}
		else
		{
			int i = 0;
			int n = 0;
			char *temp = NULL;
			while (string[i])
			{
				if (n == strings_count - 1)
				{
					temp = &string[i];
					break;
				}
				if (string[i++] == '\n')
					n++;
			}
			if (temp)
			{
				std::cout << std::endl;
				std::cout << temp << std::endl;
				std::cout << std::endl;
			}
			else
			{
				std::cout << std::endl;
				std::cout << "Current string is empty..." << std::endl;
				std::cout << std::endl;
			}
		}
	}
	
} *basestring;

int main()
{
	basestring = new strings;
	char mass[1000];

	int choice = 0;
	do
	{
		system("cls");
		std::cout << std::endl;
		std::cout << "       Menu:" << std::endl;
		std::cout << std::endl;
		std::cout << "0 - display string" << std::endl;
		std::cout << std::endl;
		std::cout << "1 - add text" << std::endl;
		std::cout << "2 - new string" << std::endl;
		std::cout << "3 - delete string" << std::endl;
		std::cout << "4 - clean string" << std::endl;
		std::cout << "5 - display current string" << std::endl;
		std::cout << std::endl;
		std::cout << "6 - EXIT" << std::endl;
		std::cout << std::endl;
		std::cin >> choice;
		std::cin.ignore();

		switch (choice)
		{
		case 0:
			basestring->display();
			break;
		case 9:
			basestring->info();
			break;
		case 1:
			system("cls");
			std::cout << "       Print text:" << std::endl;
			std::cout << std::endl;
			gets_s(mass);
			basestring->add(mass);
			std::cout << std::endl;
			std::cout << "Done!" << std::endl;
			system("pause");
			break;
		case 2:
			basestring->new_string();
			std::cout << std::endl;
			std::cout << "Done!" << std::endl;
			system("pause");
			break;
		case 3:
			system("cls");
			basestring->delete_string();
			system("pause");
			break;
		case 4:
			basestring->clear();
			break;
		case 5:
			system("cls");
			basestring->display_current_string();
			system("pause");
			break;
		case 6:
			std::cout << "Exit..." << std::endl;
			return 0;
		}
	} while (choice >= 0 && choice < 10);

	return 0;
}
