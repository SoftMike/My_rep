#include "pch.h"
#include <iostream>
#include <string>
#include "list.h"

int main()
{
	int choise = 0;
	list base;
	do
	{
		system("cls");
		std::cout << "    Menu:\n\n";
		std::cout << "0 - display data\n";
		std::cout << "1 - add data\n";
		std::cout << "2 - search data\n";
		std::cout << "3 - delete data\n";
		std::cout << "4 - insert in the middle\n";
		std::cout << "5 - clear data\n\n";
		std::cout << "any key - EXIT\n\n";
		std::cin >> choise;
		std::cin.ignore();
		switch (choise)
		{
		case 0:
			system("cls");
			base.display();
			system("pause");
			break;
		case 1:
			base.add();
			break;
		case 2:
			system("cls");
			base.search();
			system("pause");
			break;
		case 3:
			base.delete_data();
			system("pause");
			break;
		case 4:
			base.insert();
			system("pause");
			break;
		case 5:
			base.clear_data();
			break;
		}

	} while (choise >= 0 && choise < 6);

	return 0;
}