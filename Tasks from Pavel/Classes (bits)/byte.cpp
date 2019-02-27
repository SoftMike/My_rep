#include "stdafx.h"
#include <iostream>
#include "byte.h"

	byte::byte (int &x)
	{
		int_data.x = &x;
	}
	void byte::display()
	{
		system("cls");
		info.ch = *int_data.x_byte;

		for (int i = 0; i < 4; i++)
		{
			std::cout << i + 1 << " byte: ";

			if (info.status->one)
				std::cout << "1";
			else
				std::cout << "0";
			if (info.status->two)
				std::cout << "1";
			else
				std::cout << "0";
			if (info.status->three)
				std::cout << "1";
			else
				std::cout << "0";
			if (info.status->four)
				std::cout << "1";
			else
				std::cout << "0";
			if (info.status->five)
				std::cout << "1";
			else
				std::cout << "0";
			if (info.status->six)
				std::cout << "1";
			else
				std::cout << "0";
			if (info.status->seven)
				std::cout << "1";
			else
				std::cout << "0";
			if (info.status->eight)
				std::cout << "1";
			else
				std::cout << "0";
			std::cout << "\n";
			info.ch++;
		}
	}
	void byte::set_bits(int n)
	{
		system("cls");
		if (n < 1 || n > 4)
		{
			std::cout << "Integers has only 4 bytes! Try again.\n";
			system("pause");
			return;
		}
		info.ch = *int_data.x_byte;
		int i = 1;
		while (i != n)
		{
			i++;
			info.ch++;
		}

		system("cls");
		int choice = 0;
		std::cout << "\n";
		do
		{
			std::cout << "Set 1 bit (1/0): ";
			std::cin >> choice;
			if (choice != 1 && choice != 0)
				std::cout << "Wrong! Only 1 or 0.\n";
		} while (choice != 1 && choice != 0);
		if (choice == 1)
			info.status->eight = 1;
		else
			info.status->eight = 0;
		do
		{
			std::cout << "Set 2 bit (1/0): ";
			std::cin >> choice;
			if (choice != 1 && choice != 0)
				std::cout << "Wrong! Only 1 or 0.\n";
		} while (choice != 1 && choice != 0);
		if (choice == 1)
			info.status->seven = 1;
		else
			info.status->seven = 0;
		do
		{
			std::cout << "Set 3 bit (1/0): ";
			std::cin >> choice;
			if (choice != 1 && choice != 0)
				std::cout << "Wrong! Only 1 or 0.\n";
		} while (choice != 1 && choice != 0);
		if (choice == 1)
			info.status->six = 1;
		else
			info.status->six = 0;
		do
		{
			std::cout << "Set 4 bit (1/0): ";
			std::cin >> choice;
			if (choice != 1 && choice != 0)
				std::cout << "Wrong! Only 1 or 0.\n";
		} while (choice != 1 && choice != 0);
		if (choice == 1)
			info.status->five = 1;
		else
			info.status->five = 0;
		do
		{
			std::cout << "Set 5 bit (1/0): ";
			std::cin >> choice;
			if (choice != 1 && choice != 0)
				std::cout << "Wrong! Only 1 or 0.\n";
		} while (choice != 1 && choice != 0);
		if (choice == 1)
			info.status->four = 1;
		else
			info.status->four = 0;
		do
		{
			std::cout << "Set 6 bit (1/0): ";
			std::cin >> choice;
			if (choice != 1 && choice != 0)
				std::cout << "Wrong! Only 1 or 0.\n";
		} while (choice != 1 && choice != 0);
		if (choice == 1)
			info.status->three = 1;
		else
			info.status->three = 0;
		do
		{
			std::cout << "Set 7 bit (1/0): ";
			std::cin >> choice;
			if (choice != 1 && choice != 0)
				std::cout << "Wrong! Only 1 or 0.\n";
		} while (choice != 1 && choice != 0);
		if (choice == 1)
			info.status->two = 1;
		else
			info.status->two = 0;
		do
		{
			std::cout << "Set 8 bit (1/0): ";
			std::cin >> choice;
			if (choice != 1 && choice != 0)
				std::cout << "Wrong! Only 1 or 0.\n";
		} while (choice != 1 && choice != 0);
		if (choice == 1)
			info.status->one = 1;
		else
			info.status->one = 0;
		std::cout << "Done!\n";
		system("pause");
	}