#include "stdafx.h"
#include "mystring.h"
#include <iostream>

	string::string()
	{
		s = new char;
		s[0] = '\0';
	}
	string::~string()
	{
		if (s)
			delete[] s;
	}
	string::string(const string &obj)
	{
		s = new char[(strlen(obj.s)) + 1];
		int i = 0;
		while (obj.s[i])
		{
			s[i] = obj.s[i];
			i++;
		}
		s[i] = '\0';
	}

	string string::operator=(string obj)
	{
		if (strlen(s) < strlen(obj.s))
		{
			delete[] s;
			s = new char[strlen(obj.s) + 1];
		}

		int i = 0;
		while (obj.s[i])
		{
			s[i] = obj.s[i];
			i++;
		}

		s[i] = '\0';

		return *this;
	}
	string string::operator=(const char *mass)
	{
		string temp;
		delete[] s;
		s = new char[strlen(mass) + 1];
		s[0] = '\0';

		this->add(mass);

		return *this;
	}
	string string::operator+(string obj)
	{
		string temp;
		temp.add(this->s);
		temp.add(obj.s);
		return temp;
	}
	string string::operator+=(string obj)
	{
		string temp;
		temp.add(s);
		delete[] s;
		s = new char[strlen(obj.s) + strlen(temp.s) + 1];
		s[0] = '\0';
		this->add(temp.s);
		this->add(obj.s);
		return *this;
	}
	string string::operator+=(const char *mass)
	{
		string temp;
		temp.add(s);
		delete[] s;
		s = new char[strlen(mass) + strlen(temp.s) + 1];
		s[0] = '\0';
		this->add(temp.s);
		this->add(mass);
		return *this;
	}
	string string::operator-=(const char *mass)
	{
		int i = 0;
		int current = 0;
		int mass_n = strlen(mass);
		int start = 0;
		int end = 0;
		int reg = 0;
		char *temp = new char[mass_n + 1];
		while ((*this)[current])
		{
			current = reg++;
			i = 0;
			while (i < mass_n)
			{
				if ((*this)[current])
				{
					temp[i] = s[current];
					i++; current++;
				}
				else
					break;
				temp[i] = '\0';
			}
			if (!strcmp(temp, mass))
			{
				//delete
				start = current - mass_n;
				end = current - 1;
				int new_len = strlen(s) - mass_n;
				char *new_char = new char[new_len + 1];
				int c = 0;
				for (int i = 0; c < new_len; i++, c++)
				{
					if (i == start)
						i = current;
					new_char[c] = s[i];
				}
				new_char[c] = '\0';
				delete[] s;
				s = new_char;
			}

		}
		delete[] temp;

		return *this;
	}
	char &string::operator[](int i)
	{
		if ((i < 0) || (i >= strlen(s)))
		{
			char null = '\0';
			return null;
		}
		else
			return s[i];
	}

	void string::add(const char *mass)
	{
		int n = strlen(s) + strlen(mass) + 1;

		char *temp = new char[n];
		if (s[0])
		{
			int i = 0;
			int k = 0;
			while (s[i])
			{
				temp[i] = s[i];
				i++;
			}
			while (mass[k])
			{
				temp[i] = mass[k];
				i++; k++;
			}
			temp[i] = '\0';
		}
		else
		{
			int i = 0;
			while (mass[i])
			{
				temp[i] = mass[i];
				i++;
			}
			temp[i] = '\0';
		}
		delete[] s;
		s = temp;
	}
	void string::display()
	{
		system("cls");
		int i = 0;
		if ((*this)[i])
		{
			while ((*this)[i])
			{
				std::cout << (*this)[i];
				i++;
			}
			std::cout << std::endl;
		}
		else
			std::cout << "The string is empty..." << std::endl;
		system("pause");
	}
	void string::new_string()
	{
		*this += "\n";
	}
	void string::clean()
	{
		if (!(*this)[0])
		{
			std::cout << "The string is empty..." << std::endl;
			return;
		}
		delete[] s;
		s = new char;
		s[0] = '\0';
	}
	void string::delete_string()
	{
		if (!(*this)[0])
		{
			std::cout << "The string is empty..." << std::endl;
			return;
		}
		char  *temp = NULL;
		int n = 1;
		int i = 0;
		int choise = 0;
		std::cout << "Which string vave to delete:" << std::endl;
		std::cout << std::endl;
		for (i; s[i]; i++)
		{
			if (s[i] == '\n')
				n++;
			if (i == 0)
				std::cout << n << ": ";
			if (s[i] == '\n')
			{
				std::cout << std::endl;
				std::cout << n << ": ";
				i++;
			}
			std::cout << s[i];
		}
		std::cout << std::endl;
		std::cout << std::endl;
		do
		{
			std::cin >> choise;
			if (choise < 1 || choise > n)
			{
				std::cout << std::endl;
				std::cout << "Incorrect string number..." << std::endl;
				std::cout << std::endl;
			}
		} while (choise < 1 || choise > n);
		int k = 0;
		if (choise == 1)
		{
			char  *temp = NULL;
			while (this->s[k] != '\n')
				k++;
			temp = new char[k + 1];
			temp[k + 1] = '\0';
			while (k >= 0)
			{
				temp[k] = s[k];
				k--;
			}
			*this -= temp;
		}
		else
		{
			char  *temp = NULL;
			int l = 1;

			while ((*this)[k])
			{
				if (l == choise)
				{

					k--;
					int y = 0;
					int k_temp = k;
					do
					{
						k_temp++; y++;
					} while (s[k_temp] != '\n' && s[k_temp] != '\0');

					temp = new char[y + 1];
					y = 0;
					do
					{
						temp[y] = s[k];
						y++; k++;
					} while (s[k] != '\n' && s[k] != '\0');
					temp[y] = '\0';
					std::cout << temp << std::endl;
					*this -= temp;
					break;
				}
				if (s[k] == '\n')
					l++;
				k++;
			}
		}
		if (temp)
			delete[] temp;
	}
	void string::current_string()
	{
		if (!(*this)[0])
		{
			std::cout << "The string is empty..." << std::endl;
			return;
		}
		int n = 1;
		int k = 1;
		for (int i = 0; (*this)[i]; i++)
			if (s[i] == '\n')
				n++;
		if (n == 1)
			std::cout << "Current string:\n\n" << s << std::endl;
		else
			for (int i = 0; (*this)[i]; i++)
			{
				if (s[i] == '\n')
					k++;
				if (k == n)
				{
					std::cout << "Current string:\n\n";
					while ((*this)[i++])
						std::cout << s[i];
					std::cout << std::endl;
					break;
				}
			}
	}
