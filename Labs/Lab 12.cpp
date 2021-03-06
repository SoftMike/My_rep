#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

std::string base_file = "base.txt";

class DATA
{
public:
	std::string name;
	int cost;

	DATA()
	{
		cost = 0;
		name = "";
	}

	void display()
	{
		std::cout << std::endl;
		std::cout << " _________________________" << std::endl;
		std::cout << "|Item name: " << name << std::endl;
		std::cout << "|Item cost: " << cost << std::endl;
		std::cout << "|==========================" << std::endl;
	}
} item;

void qsort(DATA *mass, int left, int right)
{
	int l = left;
	int r = right - 1;
	int pivot = mass[(l + r) / 2].cost;
	do
	{
		while (mass[l].cost < pivot) l++;
		while (mass[r].cost > pivot) r--;
		std::swap(mass[l++], mass[r--]);
	} while (l < r);
	if (left < r)
		qsort(mass, left, r);
	if (l < right)
		qsort(mass, l, right);
}

void lsearch(DATA *mass, int cost)
{
	int n = 0;
	while (mass[n].cost)
		n++;
	for(int i = 0; i < n; i++)
		if (mass[i].cost == cost)
		{
			system("cls");
			std::cout << "   Search results: " << std::endl;
			mass[i].display();
			std::cout << std::endl;
			system("pause");
			return;
		}
	system("cls");
	std::cout << std::endl;
	std::cout << "No results..." << std::endl;
	std::cout << std::endl;
	system("pause");
	return;
}

void bsearch(DATA *mass, int cost)
{
	int r = 0;
	while (mass[r].cost)
		r++;
	r--;

	int l = 0;
	do
	{
		int c = (l + r) / 2;
		if (mass[c].cost > cost) r = --c;
		if (mass[c].cost < cost) l = ++c;
		if (mass[c].cost == cost)
		{
			system("cls");
			std::cout << std::endl;
			std::cout << "   Search results: " << std::endl;
			mass[c].display();
			std::cout << std::endl;
			system("pause");
			return;
		}
	} while (l <= r);
	system("cls");
	std::cout << std::endl;
	std::cout << "No results..." << std::endl;
	std::cout << std::endl;
	system("pause");
}

void isearch(DATA *mass, int cost)
{
	int r = 0;
	while (mass[r].cost)
		r++;
	--r;
	int l = 0;
	do
	{
		int c = l + (cost - mass[l].cost) * (r - l) / (mass[r].cost - mass[l].cost);
		if (mass[c].cost == cost)
		{
			system("cls");
			std::cout << std::endl;
			std::cout << "   Search results: " << std::endl;
			mass[c].display();
			std::cout << std::endl;
			system("pause");
			return;
		}
		if (cost > mass[c].cost) l = c+1;
		if (cost < mass[c].cost) r = c-1;
	} while (l <= r);
	system("cls");
	std::cout << std::endl;
	std::cout << "No results..." << std::endl;
	std::cout << std::endl;
	system("pause");
}

void search()
{
	system("cls");
	DATA items[20];
	int n = 0;
	std::ifstream read;
	read.open(base_file);
	if (!read.is_open())
		std::cout << "Error opening file..." << std::endl;
	else
	{
		while (read.read((char*)&item, sizeof(DATA)))
		{
			items[n] = item;
			n++;
		}
	}
	read.close();

	int choice = 0;

	do
	{
		int cost = 0;
		std::cout << std::endl;
		std::cout << "Enter cost: " << std::endl;
		std::cout << std::endl;
		std::cin >> cost;
		std::cin.ignore();

		system("cls");
		std::cout << std::endl;
		std::cout << "1 - linear search" << std::endl;
		std::cout << "2 - binary search" << std::endl;
		std::cout << "3 - interpolation search" << std::endl;
		std::cout << std::endl;
		std::cout << "4 - EXIT" << std::endl;
		std::cout << std::endl;
		std::cin >> choice;
		std::cin.ignore();
		switch (choice)
		{
		case 1:
			qsort(items, 0, n);
			lsearch(items, cost);
			return;
		case 2:
			qsort(items, 0, n);
			bsearch(items, cost);
			return;
		case 3:
			qsort(items, 0, n);
			isearch(items, cost);
			return;
		}

	} while (choice > 0 && choice < 4);
}
	
void add()
{
	std::ofstream enter;
	enter.open(base_file, std::ofstream::app);
	if (!enter.is_open())
		std::cout << "Error opening file..." << std::endl;
	else
	{
		std::cout << "Enter item name: ";
		std::getline(std::cin, item.name);
		std::cout << "Enter item cost: ";
		std::cin >> item.cost;
		std::cin.ignore();
		enter.write((char*)&item, sizeof(DATA));
	}
	enter.close();
}

void display()
{
	std::ifstream read;
	read.open(base_file);
	if (!read.is_open())
		std::cout << "Error opening file..." << std::endl;
	else
	{
		while (read.read((char*)&item, sizeof(DATA)))
		{
			item.display();
		}
	}
	read.close();
	system("pause");
}

void clear()
{
	std::string clear_comand = "DEL | ERASE  base.txt clear.bat";
	std::ofstream clear;
	clear.open("clear.bat");
	if (!clear.is_open())
		std::cout << "Ошибка удаления!" << std::endl;
	else
		clear << clear_comand;

	clear.close();
	system("clear.bat");
}

int main()
{
	int choice = 0;
	do
	{
		system("cls");
		std::cout << std::endl;
		std::cout << "1 - add item" << std::endl;
		std::cout << "2 - display items" << std::endl;
		std::cout << "3 - search item by cost" << std::endl;
		std::cout << "4 - delete base.txt" << std::endl;
		std::cout << std::endl;
		std::cout << "5 - EXIT" << std::endl;
		std::cout << std::endl;
		std::cin >> choice;
		std::cin.ignore();
		switch (choice)
		{
		case 1:
			add();
			break;
		case 2:
			display();
			break;
		case 3:
			search();
			break;
		case 4:
			clear();
			break;
		}

	} while (choice > 0 && choice < 5);

	return 0;
}
