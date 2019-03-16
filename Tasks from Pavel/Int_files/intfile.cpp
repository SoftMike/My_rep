#include "pch.h"
#include <iostream>
#include <fstream>
#include "intfile.h"

files::files()
	{
		n = 0;
		file.open("myfile.txt");
		if (!file.is_open())
		{
			std::cout << "File error!\n";
			exit(1);
		}

		file.write((char *)&n, sizeof n);

		file.close();
	}
void files::enter()
	{
		int temp_n = 0;
		std::ifstream file_o("myfile.txt");
		if (!file_o.is_open())
		{
			std::cout << "File error!\n";
			exit(1);
		}
		file_o.read((char *)&temp_n, sizeof temp_n);

		if (!temp_n)
		{
			file_o.close();
			file.open("myfile.txt");
			if (!file.is_open())
			{
				std::cout << "File error!\n";
				exit(1);
			}

			std::cout << "Enter integer: ";
			std::cin >> number;
			n++;

			file.write((char *)&n, sizeof n);
			file.write((char *)&number, sizeof number);

			file.close();
		}
		else
		{
			int i = 0;
			int *mass = new int[temp_n];
			for (; i < temp_n; i++)
				file_o.read((char *)&mass[i], sizeof mass[i]);
			file_o.close();


			file.open("myfile.txt");
			if (!file.is_open())
			{
				std::cout << "File error!\n";
				exit(1);
			}

			std::cout << "Enter integer: ";
			std::cin >> number;
			n++;

			file.write((char *)&n, sizeof n);

			for (i = 0; i < temp_n; i++)
				file.write((char *)&mass[i], sizeof mass[i]);

			file.write((char *)&number, sizeof number);

			file.close();

			delete[] mass;
		}
	}
void files::setup()
	{
		int choise = 0;
		do
		{
			system("cls");
			std::cout << "     MENU\n\n";
			std::cout << "1 - ADD integer;\n";
			std::cout << "2 - display base info\n\n";
			std::cout << "3 - EXIT\n\n";
			std::cin >> choise;
			switch (choise)
			{
			case 1:
				enter();
				break;
			case 2:
				display();
				break;
			case 3:
				return;
			}
		} while (choise > 0 && choise < 4);
	}
void files::display()
	{
		system("cls");
		int n = 0;
		int temp = 0;
		std::ifstream file_o("myfile.txt");
		if (!file_o.is_open())
		{
			std::cout << "File error!\n";
			exit(1);
		}
		file_o.read((char *)&n, sizeof n);
		std::cout << "There are " << n << " numbers in the base:\n\n";
		for (int i = 0; i < n; i++)
		{
			file_o.read((char *)&temp, sizeof temp);
			std::cout << temp << std::endl;
		}
		std::cout << std::endl;
		file_o.close();
		system("pause");
	}