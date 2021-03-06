#include "stdafx.h"
#include "mystring.h"
#include <iostream>

int main()
{
	string basestring;
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
			basestring.display();
			break;
		case 1:
			system("cls");
			std::cout << "       Print text:" << std::endl;
			std::cout << std::endl;
			gets_s(mass);
			basestring.add(mass);
			std::cout << std::endl;
			std::cout << "Done!" << std::endl;
			system("pause");
			break;
		case 2:
			basestring.new_string();
			std::cout << std::endl;
			std::cout << "Done!" << std::endl;
			system("pause");
			break;
		case 3:
			system("cls");
			basestring.delete_string();
			system("pause");
			break;
		case 4:
			basestring.clean();
			break;
		case 5:
			system("cls");
			basestring.current_string();
			system("pause");
			break;
		case 6:
			std::cout << "Exit..." << std::endl;
			return 0;
		}
	} while (choice >= 0 && choice < 10);

	return 0;
}