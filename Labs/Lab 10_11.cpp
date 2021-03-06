#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <Shellapi.h>
#include <cstdlib>

/*
Ideas:
- Entering protect
*/

std::string filename_total = "total.txt";
std::string filename_old = "old.txt";
std::string filename_new = "new.txt";
std::string filename_coefficient = "coefficient.txt";
std::string filename_print = "print.txt";
std::string filename_search = "search.txt";

double gaz_k = 0;
double water_k = 0;
double elec_k_bef100 = 0;
double elec_k_aft100 = 0;

class SHABLON
{
public:
	int month;
	int year;
	double water_cubs;
	double water_cost;
	double gaz_cubs;
	double gaz_cost;
	double electro_cubs;
	double electro_cost;
	double TOTAL;

	SHABLON(int mon = 0, int yea = 2019, double water = 0, double gaz = 0, double electro = 0)
	{
		water_cubs = water;
		water_cost = water_cubs * water_k;
		gaz_cubs = gaz;
		gaz_cost = gaz_cubs * gaz_k;
		electro_cubs = electro;
		if (electro_cubs <= 100)
			electro_cost = electro_cubs * elec_k_bef100;
		else
			electro_cost = (100 * elec_k_bef100) + ((electro_cubs - 100) * elec_k_aft100);
		TOTAL = water_cost + gaz_cost + electro_cost;
		month = mon;
		year = yea;
	}

	void display()
	{
		std::cout << " ___________________________________________________________________" << std::endl;
		std::cout << "|        " << month << "." << year << std::endl;
		std::cout << "|___________________________" << std::endl;
		std::cout << "|        Водоканал" << std::endl;
		std::cout << "|Кубы:             " << water_cubs << " кубов" << std::endl;
		std::cout << "|Стоимость:        " << water_cost << " грн." << std::endl;
		std::cout << "|---------------------------" << std::endl;
		std::cout << "|      Газоснабжение" << std::endl;
		std::cout << "|Кубы:             " << gaz_cubs << " кубов" << std::endl;
		std::cout << "|Стоимость:        " << gaz_cost << " грн." << std::endl;
		std::cout << "|---------------------------" << std::endl;
		std::cout << "|      Электричество" << std::endl;
		std::cout << "|Киловаты:         " << electro_cubs << " кВт" << std::endl;
		std::cout << "|Стоимость:        " << electro_cost << " грн." << std::endl;
		std::cout << "|---------------------------" << std::endl;
		std::cout << "|   ВСЕГО:   " << TOTAL << " грн." << std::endl;
		std::cout << "|____________________________________________________________________" << std::endl;
		std::cout << std::endl;
	}
};

class coefficient
{
public:
	double gaz;
	double water;
	double elec_bef100;
	double elec_aft100;
}coef;

class SEARCH
{
public:
	int month;
	int year;
	double water_cubs;
	double water_cost;
	double gaz_cubs;
	double gaz_cost;
	double electro_cubs;
	double electro_cost;
	double TOTAL;

	void display()
	{
		std::cout << " ___________________________________________________________________" << std::endl;
		std::cout << "|        " << month << "." << year << std::endl;
		std::cout << "|___________________________" << std::endl;
		std::cout << "|        Водоканал" << std::endl;
		std::cout << "|Кубы:             " << water_cubs << " кубов" << std::endl;
		std::cout << "|Стоимость:        " << water_cost << " грн." << std::endl;
		std::cout << "|---------------------------" << std::endl;
		std::cout << "|      Газоснабжение" << std::endl;
		std::cout << "|Кубы:             " << gaz_cubs << " кубов" << std::endl;
		std::cout << "|Стоимость:        " << gaz_cost << " грн." << std::endl;
		std::cout << "|---------------------------" << std::endl;
		std::cout << "|      Электричество" << std::endl;
		std::cout << "|Киловаты:         " << electro_cubs << " кВт" << std::endl;
		std::cout << "|Стоимость:        " << electro_cost << " грн." << std::endl;
		std::cout << "|---------------------------" << std::endl;
		std::cout << "|   ВСЕГО:   " << TOTAL << " грн." << std::endl;
		std::cout << "|____________________________________________________________________" << std::endl;
		std::cout << std::endl;
	}
	SEARCH()
	{
		TOTAL = 0;
	}
};

std::string mon(int month)
{
	std::string name;

	if (month == 1)
	{
		name = "январь";
		return name;
	}

	if (month == 2)
	{
		name = "февраль";
		return name;
	}

	if (month == 3)
	{
		name = "март";
		return name;
	}

	if (month == 4)
	{
		name = "апрель";
		return name;
	}

	if (month == 5)
	{
		name = "май";
		return name;
	}

	if (month == 6)
	{
		name = "июнь";
		return name;
	}

	if (month == 7)
	{
		name = "июль";
		return name;
	}

	if (month == 8)
	{
		name = "август";
		return name;
	}

	if (month == 9)
	{
		name = "сентябрь";
		return name;
	}

	if (month == 10)
	{
		name = "октябрь";
		return name;
	}

	if (month == 11)
	{
		name = "ноябрь";
		return name;
	}

	if (month == 12)
	{
		name = "декабрь";
		return name;
	}
}

void enter()
{
	system("cls");
	int month = 0;
	int year = 2019;
	double water = 0;
	double gaz = 0;
	double electro = 0;

	SHABLON temp;

	std::ifstream copy;
	copy.open(filename_new);
	if (!copy.is_open())
		std::cout << "Ошибка открытия файла..." << std::endl;
	else
		copy.read((char*)&temp, sizeof(SHABLON));
	copy.close();

	std::ofstream copy2;
	copy2.open(filename_old);
	if (!copy2.is_open())
		std::cout << "Ошибка открытия файла..." << std::endl;
	else
		copy2.write((char*)&temp, sizeof(SHABLON));
	copy2.close();

	std::cout << "Введите номер текущего месяца: " << std::endl;
	std::cin >> month;
	std::cin.ignore();
	system("cls");
	std::cout << "Введите текущее показание воды:" << std::endl;
	std::cin >> water;
	std::cin.ignore();
	system("cls");
	std::cout << "Введите текущее показание газа:" << std::endl;
	std::cin >> gaz;
	std::cin.ignore();
	system("cls");
	std::cout << "Введите текущее показание электроэнергии:" << std::endl;
	std::cin >> electro;
	std::cin.ignore();
	system("cls");

	SHABLON item(month, year, water, gaz, electro);

	std::ofstream fin;
	fin.open(filename_new);
	if (!fin.is_open())
		std::cout << "Ошибка открытия файла..." << std::endl;
	else
		fin.write((char*)&item, sizeof(SHABLON));
	fin.close();

	water = item.water_cubs - temp.water_cubs;
	gaz = item.gaz_cubs - temp.gaz_cubs;
	electro = item.electro_cubs - temp.electro_cubs;

	SHABLON total(month, year, water, gaz, electro);

	std::ofstream result;
	result.open(filename_total, std::ofstream::app);
	if (!result.is_open())
		std::cout << "Ошибка открытия файла..." << std::endl;
	else
	{
		result << " _____________________________________________\n";
		result << "|                " << mon(month) << " " << year << "\n";
		result << "|_____________________________________________|\n";
		result << "|          КП ДНЕПРОВОДОКАНАЛ                 |\n";
		result << "|                                             |\n";
		result << "| Расчётный счёт:         26009300030539      |\n";
		result << "| Лицевой счёт:           770159005001        |\n";
		result << "|                                             |\n";
		result << "| Предыдущее показание:   " << temp.water_cubs << " кубов\n";
		result << "| Текущее показание:      " << item.water_cubs << " кубов\n";
		result << "|                                             |\n";
		result << "| Сумма:                  " << total.water_cost << " грн.\n";
		result << "|---------------------------------------------|\n";
		result << "|         Днiпропетровськгаз збут             |\n";
		result << "|                                             |\n";
		result << "| Расчётный счёт:         26031312483915      |\n";
		result << "| Лицевой счёт:           0310167452          |\n";
		result << "|                                             |\n";
		result << "| Предыдущее показание:   " << temp.gaz_cubs << " кубов\n";
		result << "| Текущее показание:      " << item.gaz_cubs << " кубов\n";
		result << "|                                             |\n";
		result << "| Сумма:                  " << total.gaz_cost << " грн.\n";
		result << "|---------------------------------------------|\n";
		result << "|     ДТЕК ДНIПРОПЕТРОВСЬКI ЕЛЕКТРОМЕРЕЖI     |\n";
		result << "|                                             |\n";
		result << "| Расчётный счёт:         26034304790066\n";
		result << "| Лицевой счёт:           6501097\n";
		result << "|                                             |\n";
		result << "| Предыдущее показание:   " << temp.electro_cubs << " кВт\n";
		result << "| Текущее показание:      " << item.electro_cubs << " кВт\n";
		result << "|                                             |\n";
		result << "| Сумма:                  " << total.electro_cost << " грн.\n";
		result << "|_____________________________________________|\n";
		result << "|                                             |\n";
		result << "|                 ВСЕГО: " << total.TOTAL << " ГРН.\n";
		result << "|_____________________________________________|\n";
		result << "******************************************************************************\n";
	}
	result.close();

	std::ofstream print;
	print.open(filename_print);
	if (!print.is_open())
		std::cout << "Ошибка открытия файла..." << std::endl;
	else
	{
		print << " _____________________________________________\n";
		print << "|                " << mon(month) << " " << year << "\n";
		print << "|_____________________________________________|\n";
		print << "|          КП ДНЕПРОВОДОКАНАЛ                 |\n";
		print << "|                                             |\n";
		print << "| Расчётный счёт:         26009300030539      |\n";
		print << "| Лицевой счёт:           770159005001        |\n";
		print << "|                                             |\n";
		print << "| Предыдущее показание:   " << temp.water_cubs << " кубов\n";
		print << "| Текущее показание:      " << item.water_cubs << " кубов\n";
		print << "|                                             |\n";
		print << "| Сумма:                  " << total.water_cost << " грн.\n";
		print << "|---------------------------------------------|\n";
		print << "|         Днiпропетровськгаз збут             |\n";
		print << "|                                             |\n";
		print << "| Расчётный счёт:         26031312483915      |\n";
		print << "| Лицевой счёт:           0310167452          |\n";
		print << "|                                             |\n";
		print << "| Предыдущее показание:   " << temp.gaz_cubs << " кубов\n";
		print << "| Текущее показание:      " << item.gaz_cubs << " кубов\n";
		print << "|                                             |\n";
		print << "| Сумма:                  " << total.gaz_cost << " грн.\n";
		print << "|---------------------------------------------|\n";
		print << "|    ДТЕК ДНIПРОПЕТРОВСЬКI ЕЛЕКТРОМЕРЕЖI      |\n";
		print << "|                                             |\n";
		print << "| Расчётный счёт:         26034304790066      |\n";
		print << "| Лицевой счёт:           6501097             |\n";
		print << "|                                             |\n";
		print << "| Предыдущее показание:   " << temp.electro_cubs << " кВт\n";
		print << "| Текущее показание:      " << item.electro_cubs << " кВт\n";
		print << "|                                             |\n";
		print << "| Сумма:                  " << total.electro_cost << " грн.\n";
		print << "|_____________________________________________|\n";
		print << "|                                             |\n";
		print << "|                 ВСЕГО: " << total.TOTAL << " ГРН.\n";
		print << "|_____________________________________________|\n";
	}
	print.close();

	std::ofstream search;
	search.open(filename_search, std::ofstream::app);
	if (!search.is_open())
		std::cout << "Ошибка открытия файла..." << std::endl;
	else
	{
		SEARCH s_in;
		s_in.electro_cost = total.electro_cost;
		s_in.electro_cubs = item.electro_cubs - temp.electro_cubs;
		s_in.gaz_cost = total.gaz_cost;
		s_in.gaz_cubs = item.gaz_cubs - temp.gaz_cubs;
		s_in.water_cost = total.water_cost;
		s_in.water_cubs = item.water_cubs - temp.water_cubs;
		s_in.TOTAL = total.TOTAL;
		s_in.year = total.year;
		s_in.month = total.month;

		search.write((char*)&s_in, sizeof(SEARCH));
	}
	search.close();
	
	// system("print.bat");
}

void display()
{
	system("cls");
	std::ifstream fout;
	fout.open(filename_total);
	if (!fout.is_open())
		std::cout << "Ошибка открытия файла..." << std::endl;
	else
	{
		std::string string;
		while (!fout.eof())
		{
			string = "";
			std::getline(fout, string);
			std::cout << string << std::endl;
		}
	}
	fout.close();
	system("pause");
}

void edit_coefficient()
{
	system("cls");
	int choice = 0;
	std::ifstream display;
	display.open(filename_coefficient);
	if (!display.is_open())
		std::cout << "Ошибка открытия файла..." << std::endl;
	else
		display.read((char*)&coef, sizeof(coefficient));
	display.close();
	std::cout << std::endl;
	std::cout << "Коэфициент на воду:                           " << coef.water << std::endl;
	std::cout << "Коэфициент на газ:                            " << coef.gaz << std::endl;
	std::cout << "Коэфициент на электроэнергию ДО 100 кВт:      " << coef.elec_bef100 << std::endl;
	std::cout << "Коэфициент на электроэнергию СВЫШЕ 100 кВт:   " << coef.elec_aft100 << std::endl;
	std::cout << std::endl;
	std::cout << "1 - ИЗМЕНИТЬ коэфициенты" << std::endl;
	std::cout << "2 - вернуться в ГЛАВНОЕ МЕНЮ" << std::endl;
	std::cout << std::endl;
	do
	{
		std::cout << "Ваш выбор: ";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			std::cout << std::endl;
			std::cout << "Введите коэфициент на ВОДУ:                           ";
			std::cin >> coef.water;
			std::cin.ignore();

			std::cout << "Введите коэфициент на ГАЗ:                            ";
			std::cin >> coef.gaz;
			std::cin.ignore();

			std::cout << "Введите коэфициент на ЭЛЕКТРОЭНЕРГИЮ ДО 100 кВт:      ";
			std::cin >> coef.elec_bef100;
			std::cin.ignore();

			std::cout << "Введите коэфициент на ЭЛЕКТРОЭНЕРГИЮ СВЫШЕ 100 кВт:   ";
			std::cin >> coef.elec_bef100;
			std::cin.ignore();

			gaz_k = coef.gaz;
			water_k = coef.water;
			elec_k_bef100 = coef.elec_bef100;
			elec_k_aft100 = coef.elec_aft100;

			std::ofstream cof;
			cof.open(filename_coefficient);
			if (!cof.is_open())
				std::cout << "Ошибка открытия файла..." << std::endl;
			else
				cof.write((char*)&coef, sizeof(coefficient));
			cof.close();
			system("cls");
			return;
		}
	} while (choice > 0 && choice < 2);
	system("cls");
}

void print_()
{
	std::string print_comand = "NOTEPAD /P print.txt";
	std::ofstream print;
	print.open("print.bat");
	if (!print.is_open())
		std::cout << "Ошибка печати!" << std::endl;
	else
	{
		print << print_comand;
	}
	print.close();
	system("print.bat");
}

void clear()
{
	std::string clear_comand = "DEL | ERASE  coefficient.txt new.txt old.txt print.txt total.txt print.bat search.txt clear.bat";
	std::ofstream clear;
	clear.open("clear.bat");
	if (!clear.is_open())
		std::cout << "Ошибка удаления!" << std::endl;
	else
	{
		clear << clear_comand;
	}
	clear.close();
	system("clear.bat");
}

void qsort(SEARCH *mass, int left, int right)
{
	int l = left;
	int r = right;
	int pivot = mass[(l + r) / 2].TOTAL;
	do
	{
		while (mass[l].TOTAL < pivot) l++;
		while (mass[r].TOTAL > pivot) r--;
		if (l <= r)
			std::swap(mass[l++], mass[r--]);
	} while (l <= r);
	if (left < r)
		qsort(mass, left, r);
	if (l < right)
		qsort(mass, l, right);
}

void isort(SEARCH *mass)
{
	int n = 0;
	do
		n++;
	while (mass[n].TOTAL);
	n--;

	for (int i = 0; i < n; i++)
	{
		int k = i + 1;
		if (mass[k].TOTAL < mass[i].TOTAL)
		{
			SEARCH temp = mass[k];
			do
			{
				mass[k] = mass[k - 1];
				k--;
			}
			while (k >= 0 && mass[k-1].TOTAL > temp.TOTAL);
			mass[k] = temp;
		}
	}
}

void ssort(SEARCH *mass)
{
	int n = 0;
	do
		n++;
	while (mass[n].TOTAL);

	for (int i = 0; i < n-1; i++)
	{
		int min = i;
		for (int k = i + 1; k < n; k++)
			if (mass[k].TOTAL < mass[min].TOTAL)
				min = k;
		if (i != min)
			std::swap(mass[i], mass[min]);
	}
}

void bsort(SEARCH *mass)
{
	int n = 0;
	do
		n++;
	while (mass[n].TOTAL);

	for(int i = 0; i < n; i++)
		for (int k = 1; k < n; k++)
		{
			if (mass[k].TOTAL < mass[k - 1].TOTAL)
				std::swap(mass[k], mass[k - 1]);
		}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int month = 0;
	int year = 2019;
	double water = 0;
	double gaz = 0;
	double electro = 0;

	std::ifstream first_open;
	first_open.open(filename_old);
	if (!first_open.is_open())
	{
		// old.txt is not exist //


		//PREVIOS:
		system("cls");

		std::cout << "                   Программа открыта впервые!" << std::endl;
		std::cout << std::endl;
		std::cout << "Для начала необходимо заполнить ПРЕДЫДУЩУЮ информацию и ввести коэфициенты..." << std::endl;
		std::cout << std::endl;
		system("pause");
		system("cls");

		std::cout << "Введите коэфициент на ВОДУ:             ";
		std::cin >> coef.water;
		std::cin.ignore();
		system("cls");
		std::cout << "Введите коэфициент на ГАЗ:              ";
		std::cin >> coef.gaz;
		std::cin.ignore();
		system("cls");
		std::cout << "Введите коэфициент на ЭЛЕКТРОЭНЕРГИЮ до 100 кВт:   ";
		std::cin >> coef.elec_bef100;
		std::cin.ignore();
		system("cls");
		std::cout << "Введите коэфициент на ЭЛЕКТРОЭНЕРГИЮ СВЫШЕ 100 кВт:   ";
		std::cin >> coef.elec_aft100;
		std::cin.ignore();

		gaz_k = coef.gaz;
		water_k = coef.water;
		elec_k_bef100 = coef.elec_bef100;
		elec_k_aft100 = coef.elec_aft100;

		std::ofstream cof;
		cof.open(filename_coefficient);
		if (!cof.is_open())
			std::cout << "Ошибка открытия файла..." << std::endl;
		else
			cof.write((char*)&coef, sizeof(coefficient));
		cof.close();

		system("cls");
		std::cout << "Введите номер предыдущего месяца: " << std::endl;
		std::cin >> month;
		std::cin.ignore();
		system("cls");
		std::cout << "Введите предыдущее показание воды:" << std::endl;
		std::cin >> water;
		std::cin.ignore();
		system("cls");
		std::cout << "Введите предыдущее показание газа:" << std::endl;
		std::cin >> gaz;
		std::cin.ignore();
		system("cls");
		std::cout << "Введите предыдущее показание электроэнергии:" << std::endl;
		std::cin >> electro;
		std::cin.ignore();
		system("cls");

		SHABLON item(month, year, water, gaz, electro);

		std::ofstream fin;
		fin.open(filename_old);
		if (!fin.is_open())
			std::cout << "Ошибка открытия файла..." << std::endl;
		else
			fin.write((char*)&item, sizeof(SHABLON));
		fin.close();

		//CURRENT:
		std::cout << "Введите номер текущего месяца: " << std::endl;
		std::cin >> month;
		std::cin.ignore();
		system("cls");
		std::cout << "Введите текущее показание воды:" << std::endl;
		std::cin >> water;
		std::cin.ignore();
		system("cls");
		std::cout << "Введите текущее показание газа:" << std::endl;
		std::cin >> gaz;
		std::cin.ignore();
		system("cls");
		std::cout << "Введите текущее показание электроэнергии:" << std::endl;
		std::cin >> electro;
		std::cin.ignore();
		system("cls");

		SHABLON item2(month, year, water, gaz, electro);

		std::ofstream fin2;
		fin2.open(filename_new);
		if (!fin2.is_open())
			std::cout << "Ошибка открытия файла..." << std::endl;
		else
			fin2.write((char*)&item2, sizeof(SHABLON));
		fin2.close();

		water = item2.water_cubs - item.water_cubs;
		gaz = item2.gaz_cubs - item.gaz_cubs;
		electro = item2.electro_cubs - item.electro_cubs;

		SHABLON total(month, year, water, gaz, electro);

		std::ofstream result;
		result.open(filename_total, std::ofstream::app);
		if (!result.is_open())
			std::cout << "Ошибка открытия файла..." << std::endl;
		else
		{
			result << " _____________________________________________\n";
			result << "|                " << mon(month) << " " << year << "\n";
			result << "|_____________________________________________|\n";
			result << "|          КП ДНЕПРОВОДОКАНАЛ                 |\n";
			result << "|                                             |\n";
			result << "| Расчётный счёт:         26009300030539      |\n";
			result << "| Лицевой счёт:           770159005001        |\n";
			result << "|                                             |\n";
			result << "| Предыдущее показание:   " << item.water_cubs << " кубов\n";
			result << "| Текущее показание:      " << item2.water_cubs << " кубов\n";
			result << "|                                             |\n";
			result << "| Сумма:                  " << total.water_cost << " грн.\n";
			result << "|---------------------------------------------|\n";
			result << "|         Днiпропетровськгаз збут             |\n";
			result << "|                                             |\n";
			result << "| Расчётный счёт:         26031312483915      |\n";
			result << "| Лицевой счёт:           0310167452          |\n";
			result << "|                                             |\n";
			result << "| Предыдущее показание:   " << item.gaz_cubs << " кубов\n";
			result << "| Текущее показание:      " << item2.gaz_cubs << " кубов\n";
			result << "|                                             |\n";
			result << "| Сумма:                  " << total.gaz_cost << " грн.\n";
			result << "|---------------------------------------------|\n";
			result << "|     ДТЕК ДНIПРОПЕТРОВСЬКI ЕЛЕКТРОМЕРЕЖI     |\n";
			result << "|                                             |\n";
			result << "| Расчётный счёт:         26034304790066\n";
			result << "| Лицевой счёт:           6501097\n";
			result << "|                                             |\n";
			result << "| Предыдущее показание:   " << item.electro_cubs << " кВт\n";
			result << "| Текущее показание:      " << item2.electro_cubs << " кВт\n";
			result << "|                                             |\n";
			result << "| Сумма:                  " << total.electro_cost << " грн.\n";
			result << "|_____________________________________________|\n";
			result << "|                                             |\n";
			result << "|                 ВСЕГО: " << total.TOTAL << " ГРН.\n";
			result << "|_____________________________________________|\n";
			result << "******************************************************************************\n";
		}
		result.close();

		std::ofstream search;
		search.open(filename_search, std::ofstream::app);
		if (!search.is_open())
			std::cout << "Ошибка открытия файла..." << std::endl;
		else
		{
			SEARCH s_in;
			s_in.electro_cost = total.electro_cost;
			s_in.electro_cubs = item2.electro_cubs - item.electro_cubs;
			s_in.gaz_cost = total.gaz_cost;
			s_in.gaz_cubs = item2.gaz_cubs - item.gaz_cubs;
			s_in.water_cost = total.water_cost;
			s_in.water_cubs = item2.water_cubs - item.water_cubs;
			s_in.TOTAL = total.TOTAL;
			s_in.year = total.year;
			s_in.month = total.month;

			search.write((char*)&s_in, sizeof(SEARCH));
		}
		search.close();


		std::ofstream print;
		print.open(filename_print);
		if (!print.is_open())
			std::cout << "Ошибка открытия файла..." << std::endl;
		else
		{
			print << " _____________________________________________\n";
			print << "|                " << mon(month) << " " << year << "\n";
			print << "|_____________________________________________|\n";
			print << "|          КП ДНЕПРОВОДОКАНАЛ                 |\n";
			print << "|                                             |\n";
			print << "| Расчётный счёт:         26009300030539      |\n";
			print << "| Лицевой счёт:           770159005001        |\n";
			print << "|                                             |\n";
			print << "| Предыдущее показание:   " << item.water_cubs << " кубов\n";
			print << "| Текущее показание:      " << item2.water_cubs << " кубов\n";
			print << "|                                             |\n";
			print << "| Сумма:                  " << total.water_cost << " грн.\n";
			print << "|---------------------------------------------|\n";
			print << "|         Днiпропетровськгаз збут             |\n";
			print << "|                                             |\n";
			print << "| Расчётный счёт:         26031312483915      |\n";
			print << "| Лицевой счёт:           0310167452          |\n";
			print << "|                                             |\n";
			print << "| Предыдущее показание:   " << item.gaz_cubs << " кубов\n";
			print << "| Текущее показание:      " << item2.gaz_cubs << " кубов\n";
			print << "|                                             |\n";
			print << "| Сумма:                  " << total.gaz_cost << " грн.\n";
			print << "|---------------------------------------------|\n";
			print << "|     ДТЕК ДНIПРОПЕТРОВСЬКI ЕЛЕКТРОМЕРЕЖI     |\n";
			print << "|                                             |\n";
			print << "| Расчётный счёт:         26034304790066\n";
			print << "| Лицевой счёт:           6501097\n";
			print << "|                                             |\n";
			print << "| Предыдущее показание:   " << item.electro_cubs << " кВт\n";
			print << "| Текущее показание:      " << item2.electro_cubs << " кВт\n";
			print << "|                                             |\n";
			print << "| Сумма:                  " << total.electro_cost << " грн.\n";
			print << "|_____________________________________________|\n";
			print << "|                                             |\n";
			print << "|                 ВСЕГО: " << total.TOTAL << " ГРН.\n";
			print << "|_____________________________________________|\n";
		}
		print.close();
		//print_();
	}

	first_open.close();

	int choice = 0;

	std::ifstream cof_load;
	cof_load.open(filename_coefficient);
	if (!cof_load.is_open())
		std::cout << "Ошибка открытия файла..." << std::endl;
	else
		cof_load.read((char*)&coef, sizeof(coefficient));
	cof_load.close();

	gaz_k = coef.gaz;
	water_k = coef.water;
	elec_k_bef100 = coef.elec_bef100;
	elec_k_aft100 = coef.elec_aft100;

	do
	{
		system("cls");
		std::cout << std::endl;
		std::cout << "1 - Добавить информацию" << std::endl;
		std::cout << "2 - Посмотреть предыдущие платежи" << std::endl;
		std::cout << "3 - Посмотреть, или изменить коэфициенты" << std::endl;
		std::cout << "4 - Распечатать последний платёж" << std::endl;
		std::cout << "5 - Обнулить все показатели" << std::endl;
		std::cout << "6 - Отобразить прошлые платежи по убыванию" << std::endl;
		std::cout << std::endl;
		std::cout << "7 - ВЫХОД" << std::endl;
		std::cout << std::endl;
		std::cout << "Ваш выбор: ";

		std::cin >> choice;

		switch (choice)
		{
		case 1:
			enter();
			break;
		case 2:
			display();
			break;
		case 3:
			edit_coefficient();
			break;
		case 4:
			print_();
			break;
		case 5:
			system("cls");
			clear();
			system("cls");
			std::cout << "Все данные удалены..." << std::endl;
			system("pause");
			return 0;
		case 6:
			SEARCH mass[20];
			int i = 0;
			int k = 0;
			int n = 0;

			std::ifstream fout;
			fout.open(filename_search);
			if (!fout.is_open())
				std::cout << "Ошибка поиска..." << std::endl;
			else
			{
				do
				{
					fout.read((char*)&mass[i], sizeof(SEARCH));
					i++;
				} while (!fout.eof());
			}
			fout.close();

			do
				n++;
			while (mass[n].TOTAL);
			n -= 1;

			int choice2 = 0;
			std::cout << std::endl;
			std::cout << "1 = quick sort" << std::endl;
			std::cout << "2 - sort by selection" << std::endl;
			std::cout << "3 - insertion sort" << std::endl;
			std::cout << "4 - bubble sort" << std::endl;
			std::cout << std::endl;
			std::cout << "5 - main menu" << std::endl;

			std::cin >> choice;

			switch (choice)
			{
			case 1:
				qsort(mass, 0, n);
				break;
			case 2:
				ssort(mass);
				break;
			case 3:
				isort(mass);
				break;
			case 4:
				bsort(mass);
				break;
			}

			do
			{
				mass[k].display();
				k++;
			} while (mass[k].TOTAL);

			system("pause");
			break;
		}
	} while (choice > 0 && choice < 7);

	return 0;
}
