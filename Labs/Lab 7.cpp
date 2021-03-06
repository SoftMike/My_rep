#include "stdafx.h"
#include <iostream>
#include "myfunc.h"
#include <string>
#include <algorithm>

void clean(char *mans);
void display();
void enter();
void delete_fakes();
bool setup();
void empty();

const int cosrumers = 100;

struct ADRESS
{
	std::string street = { "Street:   " };
	char street_name[20];
	std::string house = { "House:    " };
	char house_name[20];
	std::string index = { "Index:    " };
	char index_name[20];
} adres;

struct DATE 
{
	int D;
	int M;
	int Y;
} date[cosrumers];

struct worker
{
	std::string name = { "Name:     " };
	char name_n[20];
	ADRESS adres;
	int sale;
	DATE date;

} man[cosrumers];

void alphabet(worker *ptr)
{
	for(int i = 1; i < cosrumers; i++)
		for(int n = 1; n < cosrumers; n++)
			if (ptr[n - 1].name_n[0] > ptr[n].name_n[0])
			{
				std::swap(ptr[n - 1].name_n, ptr[n].name_n);
				std::swap(ptr[n - 1].adres, ptr[n].adres);
				std::swap(ptr[n - 1].date, ptr[n].date);
				std::swap(ptr[n - 1].sale, ptr[n].sale);
			}
}

void by_date_and_sale()
{
	int M, Y;
	int sale;
	int n = 0;
	std::cout << "" << std::endl;
	std::cout << "Please enter month year and minimal discont:" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "M: ";
	std::cin >> M;
	std::cin.ignore();
	std::cout << std::endl;
	std::cout << "Y: ";
	std::cin >> Y;
	std::cin.ignore();
	std::cout << "Discont: ";
	std::cin >> sale;
	std::cin.ignore();
	std::cout << std::endl;

	for(int i = 0; i < cosrumers; i++)
		if(man[i].date.M == M)
			if (man[i].date.Y == Y)
				if (man[i].sale >= sale)
				{
					std::cout << std::endl;
					std::cout << man[i].name;
					std::cout << man[i].name_n << std::endl;
					std::cout << man[i].adres.street;
					std::cout << man[i].adres.street_name << std::endl;
					std::cout << man[i].adres.house;
					std::cout << man[i].adres.house_name << std::endl;
					std::cout << man[i].adres.index;
					std::cout << man[i].adres.index_name << std::endl;
					std::cout << "Sale:     " << man[i].sale << std::endl;
					std::cout << "Date:     ";
					std::cout << man[i].date.D << "." << man[i].date.M << "." << man[i].date.Y << std::endl;
					std::cout << std::endl;
					n++;
				}
	if (!n)
	{
		std::cout << "" << std::endl;
		std::cout << " _______________________" << std::endl;
		std::cout << "|                       |" << std::endl;
		std::cout << "|There are no results...|" << std::endl;
		std::cout << "|_______________________|" << std::endl;
		std::cout << "" << std::endl;
	}
}

void clean(char *mans)
{
	int n = strlen(mans);
	for (int i = 0; i < n; i++)
		mans[i] = '\0';
}

void display()
{
	for (int i = 0; i < cosrumers; i++)
	{
		if (man[i].name_n[0])
		{
			std::cout << std::endl;
			std::cout << man[i].name;
			std::cout << man[i].name_n << std::endl;
			std::cout << man[i].adres.street;
			std::cout << man[i].adres.street_name << std::endl;
			std::cout << man[i].adres.house;
			std::cout << man[i].adres.house_name << std::endl;
			std::cout << man[i].adres.index;
			std::cout << man[i].adres.index_name << std::endl;
			std::cout << "Sale:     " << man[i].sale << std::endl;
			std::cout << "Date:     ";
			std::cout << man[i].date.D << "." << man[i].date.M << "." << man[i].date.Y << std::endl;
			std::cout << std::endl;
		}
	}
}

void enter()
{
	int n = 0;
	std::cout << std::endl;
	std::cout << "How many costumers need enter?" << std::endl;
	std::cout << std::endl;
	std::cin >> n;
	std::cin.ignore();
	for (int i = 0; i < cosrumers; i++)
	{
		if (n == 0)
			break;
		if (!man[i].name_n[0])
		{
			std::cout << std::endl;
			std::cout << man[i].name;
			gets_s(man[i].name_n);
			std::cout << man[i].adres.street;
			gets_s(man[i].adres.street_name);
			std::cout << man[i].adres.house;
			gets_s(man[i].adres.house_name);
			std::cout << man[i].adres.index;
			gets_s(man[i].adres.index_name);
			std::cout << "Sale:     ";
			std::cin >> man[i].sale;
			std::cin.ignore();
			std::cout << "Date:     " << std::endl;
			std::cout << "D:        ";
			std::cin >> man[i].date.D;
			std::cin.ignore();
			std::cout << "M:        ";
			std::cin >> man[i].date.M;
			std::cin.ignore();
			std::cout << "Y:        ";
			std::cin >> man[i].date.Y;
			std::cin.ignore();
			std::cout << std::endl;
			n--;
		}
		else
			i++;
	}
}

void delete_fakes()
{
	int mutch = 0;
	int found = 0;

	for (int k = 0; k < cosrumers; k++)
	{
		for (int i = 0; i < cosrumers; i++)
			if (man[i].name_n[0] == '\0')
				i++;
			else
			{
				for (int n = 0; n < cosrumers; n++)
					if (i != n)
					{
						if (!strcmp(man[i].name_n, man[n].name_n))
							if (!strcmp(man[i].adres.street_name, man[n].adres.street_name))
								if (!strcmp(man[i].adres.house_name, man[n].adres.house_name))
								{
									mutch = n;
									found++;
									break;
								}
						if (found)
						{
							clean(man[mutch].name_n);
							clean(man[mutch].adres.house_name);
							clean(man[mutch].adres.street_name);
							clean(man[mutch].adres.index_name);
							man[mutch].sale = 0;
							man[mutch].date.D = 0;
							man[mutch].date.M = 0;
							man[mutch].date.Y = 0;
						}
					}
			}
	}
	if (found)
	{
		std::cout << std::endl;
		std::cout << " _________________________________________" << std::endl;
		std::cout << "|" << std::endl;
		std::cout << "|There are " << found << " fakes was deleted!" << std::endl;
		std::cout << "|_________________________________________" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << " __________________________" << std::endl;
		std::cout << "|                          |" << std::endl;
		std::cout << "|No one similar detected...|" << std::endl;
		std::cout << "|__________________________|" << std::endl;
	}

}

bool setup()
{
	std::cout << std::endl;
	std::cout << "1 - enter information" << std::endl;
	std::cout << "2 - display information" << std::endl;
	std::cout << "3 - delete similar" << std::endl;
	std::cout << "4 - display by date and minimum discount" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "5 - EXIT" << std::endl;
	std::cout << "" << std::endl;
	int choise = 0;
	worker *ptr = man;

	std::cin >> choise;
	std::cin.ignore();


	if (choise < 1 || choise > 5)
	{
		do
		{
			std::cout << "Please make your choise correctly:" << std::endl;
			std::cin >> choise;
		} while (choise < 1 || choise > 5);
	}

	switch (choise)
	{
	case 1:
		enter();
		alphabet(ptr);
		break;
	case 2:
		display();
		break;
	case 3:
		delete_fakes();
		break;
	case 4:
		by_date_and_sale();
		break;
	case 5:
		return false;
	}

	setup();
}

void empty()
{
	for (int i = 0; i < cosrumers; i++)
		man[i].name_n[0] = '\0';
}

int main()
{
	void empty();
	setup();

	return 0;
}