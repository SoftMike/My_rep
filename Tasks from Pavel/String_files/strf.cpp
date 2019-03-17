#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include "strf.h"

stringfile::stringfile()
	{
		file.open("myfile.txt");
		if (!file.is_open())
		{
			std::cout << "File error!\n";
			exit(1);
		}

		file << "Hello World! My name is Mike and I decided become a programer.\n";
		file << "Long time in my life I've worked on different specialties.\n";
		file << "There were banking spheres and different shops such as clothes shops and other.\n";
		file << "After all that experience I understood that I don't like to sell something to another people!\n";
		file << "Also I everytime knew that my passion is programming, but I couldn't decide and start learning this.\n";
		file << "So once the point got critical level and I said to myself: That's enough!\n";
		file << "I've quit my job in clothes shop and started learn the English language and programming.\n";
		file << "At this time when I'm writing this program I'm already studying for 10 month.\n";
		file << "I gave a promise to myself that I won't stop before realizing of my dream!\n";
		file << "Nobody will read this text. I just want to wish good luck to myself. Never give up Mike!\n";

		file.close();
	}
void stringfile::display_string()
	{
		system("cls");
		std::ifstream open;
		std::string str;
		char ch = '\0';
		int n = 0;
		int temp = 1;
		int set = 0;
		open.open("myfile.txt");
		if (!open.is_open())
		{
			std::cout << "File error!\n";
			exit(1);
		}
		while (!open.eof())
		{
			open.get(ch);
			if (ch == '\n')
				n++;
		}

		std::cout << "Set string which need display: ";
		std::cin >> set;
		if (set < 1 || set > n - 1)
		{
			do
			{
				std::cout << "Incorrect string number! Try again: ";
				std::cin >> set;
			} while (set < 1 || set > n - 1);
		}

		open.close();
		std::cout << std::endl;

		std::ifstream open2;
		open2.open("myfile.txt", std::ios::binary);
		if (!open2.is_open())
		{
			std::cout << "File error!\n";
			exit(1);
		}

		if (set == 1)
		{
			while (!open2.eof())
			{
				open2.get(ch);
				if (ch != '\n')
					std::cout << ch;
				else
					break;
			}
			std::cout << std::endl;
		}
		else
		{
			while (!open2.eof())
			{
				if (temp == set)
				{
					do
					{
						open2.get(ch);
						std::cout << ch;
					} while (ch != '\n' && !open2.eof());
					break;
				}
				open2.get(ch);
				if (ch == '\n')
					temp++;
			}
		}

		open.close();
		system("pause");
	}
void stringfile::display_all()
	{
		system("cls");
		std::ifstream open;
		char ch;
		open.open("myfile.txt", std::ios::binary);
		if (!open.is_open())
		{
			std::cout << "File error!\n";
			exit(1);
		}

		while (!open.eof())
		{
			open.get(ch);
			std::cout << ch;
		}
		std::cout << std::endl;
		open.close();
		system("pause");
	}
void stringfile::setup()
	{
		int choise = 0;
		do
		{
			system("cls");
			std::cout << "     MENU\n\n";
			std::cout << "1 - display all text;\n";
			std::cout << "2 - display string by the number;\n\n";
			std::cout << "3 - EXIT\n\n";
			std::cin >> choise;
			switch (choise)
			{
			case 1:
				display_all();
				break;
			case 2:
				display_string();
				break;
			case 3:
				return;
			}
		} while (choise < 1 || choise < 4);
	}