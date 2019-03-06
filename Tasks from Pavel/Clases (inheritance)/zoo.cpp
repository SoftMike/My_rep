#include "pch.h"
#include <iostream>
#include <string>
#include "zoo.h"

void base::set_name_voise(std::string name, std::string voice)
	{
		this->name = name;
		this->voice = voice;
	}
void base::get_voice()
	{
		std::cout << voice << std::endl;
	}
void base::return_name()
	{
		std::cout << name << std::endl;
	}
cow::cow()
	{
		set_name_voise(static_cast<std::string>("Cow"), static_cast<std::string>("MUUU!"));
		included = false;
	}
dog::dog()
	{
		set_name_voise(static_cast<std::string>("Dog"), static_cast<std::string>("WOF!"));
		included = false;
	}
cock::cock()
	{
		set_name_voise(static_cast<std::string>("Cock"), static_cast<std::string>("COOCUREK!"));
		included = false;
	}
horse::horse()
	{
		set_name_voise(static_cast<std::string>("Horse"), static_cast<std::string>("IGOGO!"));
		included = false;
	}
void zoo::voice()
	{
		system("cls");
		cow::get_voice();
		dog::get_voice();
		cock::get_voice();
		horse::get_voice();
		std::cout << std::endl;
		system("pause");
	}
void zoo::add()
	{
		system("cls");
		int choise = 0;
		std::cout << "Which animal need add?\n";
		std::cout << std::endl;
		std::cout << "1 - Cow\n";
		std::cout << "2 - Dog\n";
		std::cout << "3 - Cock\n";
		std::cout << "4 - Horse\n\n";
		std::cin >> choise;
		switch (choise)
		{
		case 1:
			cow::included = true;
			break;
		case 2:
			dog::included = true;
			break;
		case 3:
			cock::included = true;
			break;
		case 4:
			horse::included = true;
			break;
		}
	}
void zoo::remove()
	{
		system("cls");
		int choise = 0;
		std::cout << "Which animal need remove?\n";
		std::cout << std::endl;
		std::cout << "1 - Cow\n";
		std::cout << "2 - Dog\n";
		std::cout << "3 - Cock\n";
		std::cout << "4 - Horse\n\n";
		std::cin >> choise;
		switch (choise)
		{
		case 1:
			cow::included = false;
			break;
		case 2:
			dog::included = false;
			break;
		case 3:
			cock::included = false;
			break;
		case 4:
			horse::included = false;
			break;
		}
	}
void zoo::display_zoo()
	{
		system("cls");
		std::cout << "Animals in the zoo:\n\n";
		if (cow::included)
			cow::return_name();
		if (dog::included)
			dog::return_name();
		if (cock::included)
			cock::return_name();
		if (horse::included)
			horse::return_name();
		std::cout << std::endl;
		system("pause");
	}
void zoo::setup()
	{
		int choise = 0;
		do
		{
			system("cls");
			std::cout << "\n    Menu:\n\n";
			std::cout << "1 - add animal\n";
			std::cout << "2 - display animals in the zoo\n";
			std::cout << "3 - voices of all animals\n";
			std::cout << "4 - remove animal from the zoo\n\n";
			std::cout << "5 - EXIT\n\n";
			std::cin >> choise;
			switch (choise)
			{
			case 1:
				add();
				break;
			case 2:
				display_zoo();
				break;
			case 3:
				voice();
				break;
			case 4:
				remove();
				break;
			case 5:
				return;
			}
		} while (choise > 0 && choise < 5);
	}