#include "stdafx.h"
#include <iostream>
#include <iomanip>


int main()
{
	int some[10];
	int a = 0, b = 0, c = 0, min_value = 0, max_value = 0;
	for (a = 0; a < 10; a++)
		some[a] = rand();

	std::cout << "Have some s e q u e n c e" << std::endl;
onemore:
	std::cout << "" << std::endl;
	std::cout << "What will we do?" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "1 - displaying s e q u e n c e" << std::endl;
	std::cout << "2 - NEW random s e q u e n c e" << std::endl;
	std::cout << "3 - displaying minimal value" << std::endl;
	std::cout << "4 - displaying maximal value" << std::endl;
	std::cout << "5 - displaying all values from MINIMAL to maximal" << std::endl;
	std::cout << "6 - displaying all values from MAXIMAL to minimal" << std::endl;
	std::cout << "7 - EXIT..." << std::endl;
	std::cout << "" << std::endl;
	int choice;
	do
	{
		std::cin >> choice;
		if (choice > 7 || choice < 1)
		{
			std::cout << "" << std::endl;
			std::cout << "Please cin right menu NUMBER..." << std::endl;
			std::cout << "" << std::endl;
		}
		switch (choice)
		{
		case 1:
			std::cout << std::setw(50) << "All Numbers are:" << std::endl;
			std::cout << "" << std::endl;
			for (a = 0; a < 10; a++)
				std::cout << std::setw(50) << some[a] << std::endl;
			std::cout << "" << std::endl;
			goto onemore;
		case 2:
			std::cout << "" << std::endl;
			std::cout << "" << std::endl;
			std::cout << std::setw(50) << "/////  Creating new random s e q u e n c e...  /////" << std::endl;
			std::cout << "" << std::endl;
			std::cout << "" << std::endl;
			for (a = 0; a < 10; a++)
				some[a] = rand();
			goto onemore;
		case 3:
			std::cout << std::setw(50) << "Minimal value:" << std::endl;
			std::cout << "" << std::endl;
			min_value = some[0];
			for (a = 1; a < 10; a++)
				if (min_value > some[a])
					min_value = some[a];
			std::cout << std::setw(55) << min_value << std::endl;
			std::cout << "" << std::endl;
			goto onemore;
		case 4:
			std::cout << std::setw(50) << "Maximal value:" << std::endl;
			std::cout << "" << std::endl;
			max_value = some[0];
			for (a = 1; a < 10; a++)
				if (max_value < some[a])
					max_value = some[a];
			std::cout << std::setw(55) << max_value << std::endl;
			goto onemore;
		case 5:
			std::cout << "" << std::endl;
			std::cout << std::setw(50) << "All values from minimal to maximal:" << std::endl;
			std::cout << "" << std::endl;
			for (a = 1; a < 10; a++)
				for (b = 1; b < 10; b++)
					if (some[b - 1] > some[b])
					{
						c = some[b - 1];
						some[b - 1] = some[b];
						some[b] = c;
					}
			for (a = 0; a < 10; a++)
				std::cout << std::setw(50) << some[a] << std::endl;
			std::cout << "" << std::endl;
			goto onemore;
		case 6:
			std::cout << "" << std::endl;
			std::cout << std::setw(50) << "All values from maximal to minimal:" << std::endl;
			std::cout << "" << std::endl;
			for (a = 1; a < 10; a++)
				for (b = 1; b < 10; b++)
					if (some[b - 1] < some[b])
					{
						c = some[b - 1];
						some[b - 1] = some[b];
						some[b] = c;
					}
			for (a = 0; a < 10; a++)
				std::cout << std::setw(50) << some[a] << std::endl;
			std::cout << "" << std::endl;
			goto onemore;
		case 7:
			return 0;
		}
	} while (choice > 7 || choice < 1);

	return 0;
}
