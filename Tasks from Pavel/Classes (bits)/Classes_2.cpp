#include "stdafx.h"
#include <iostream>
#include "byte.h"

int main()
{
	int choice = 0;
	int value = 0;
	int n = 0;
	byte bit(value);
	std::cout << "Enter integer value:\n";
	std::cout << "\n";
	std::cin >> value;
	do
	{
		system("cls");
		std::cout << "\n";
		std::cout << "1 - display bits\n";
		std::cout << "2 - set bits\n";
		std::cout << "3 - display value\n";
		std::cout << "4 - set new value\n";
		std::cout << "\n";
		std::cout << "5 - EXIT\n";
		std::cout << "\n";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			bit.display();
			system("pause");
			break;
		case 2:
			bit.display();
			std::cout << "\nSet byte number:\n";
			std::cin >> n;
			bit.set_bits(n);
			break;
		case 3:
			system("cls");
			std::cout << "\nVALUE: " << value << "\n\n";
			system("pause");
			break;
		case 4:
			system("cls");
			std::cout << "\nEnter new value: ";
			std::cin >> value;
			break;
		case 5:
			return 0;
		}
	} while (choice > 0 && choice < 6);
	return 0;
}