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
	std::cout << "What will we do?" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "1 - display s e q u e n c e" << std::endl;
	std::cout << "2 - NEW random s e q u e n c e" << std::endl;
	std::cout << "3 - display minimal value" << std::endl;
	std::cout << "4 - display maximal value" << std::endl;
	std::cout << "5 - EXIT..." << std::endl;
	std::cout << "" << std::endl;
	int choice;
	do
	{
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			std::cout << "All Numbers are:" << std::endl;
			std::cout << "" << std::endl;
			for (a = 0; a < 10; a++)
				std::cout << some[a] << std::endl;
			std::cout << "" << std::endl;
			goto onemore;
		case 2:
			std::cout << "Create new random s e q u e n c e..." << std::endl;
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
			std::cout << "Maximal value:" << std::endl;
			std::cout << "" << std::endl;
			max_value = some[0];
			for (a = 1; a < 10; a++)
				if (max_value < some[a])
					max_value = some[a];
			std::cout << max_value << std::endl;
			goto onemore;
		case 5:
			return 0;
		}
	} while (choice >5 || choice <1);

	return 0;
}
