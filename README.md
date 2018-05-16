#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;

int setup();

void magik()
{
	int magik1, number, x, y;
	cout << "Начнём! Задайте число, ограничивающее диапазон угадываемых чисел:" << endl;
	cout << " " << endl;
	cin >> x;
	cout << " " << endl;
	do
	{
		if (x == 0)
		{
			cout << "Вы в своём уме? Отсутствие попыток исключено" << endl;
			cout << "Пожалуйста, попробуйте ещё раз..." << endl;
			cin >> x;
		}
	} 
	while (x == 0);
	magik1 = rand() % x + 1;
	cout << "" << endl;
	cout << "Угадайте рандомное число из Вашего диапазона (" << x << ") за семь попыток" << endl;
	cout << " " << endl;
	cout << " " << endl;
	for (y = 1; y <= 7; y++)
	{
		cin >> number;
		cout << " " << endl;
		if (magik1 == number)
		{
			cout << "Поздравляем! Вы угадали. Вам определённо сегодня повезёт." << endl;
			cout << "Но только если диапазон был велик..." << endl;
			cout << " " << endl;
			cout << "1 - сыграть ещё раз" << endl;
			cout << "2 - вернуться в главное меню" << endl;
			cout << "3 - Выход" << endl;
			cout << " " << endl;
			int choise1;
			do
			{
				cin >> choise1;
				switch (choise1)
				{
				case 1:
					magik();
					return;
				case 2:
					setup();
					return;
				case 3:
					goto stop;
					break;
				default:
					cout << "Пожалуйста, внимательно выберите один из вариантов..." << endl;
					break;
				}
			}
			while (choise1 != 3);
		}
		else
		{
			cout << "Ксожалению, вы не угадали..." << endl;
			cout << " " << endl;
			if (magik1 < number)
			{
				cout << "Ваше число больше!" << endl;
				cout << " " << endl;
			}
			else
			{
				cout << "Ваше число меньше!" << endl;
				cout << " " << endl;
			}
		}
	}
			cout << "Вы использовали все попытки :(" << endl;
			cout << " " << endl;
			cout << "1 - сыграть ещё раз" << endl;
			cout << "2 - вернуться в главное меню" << endl;
			cout << "3 - Выход" << endl;
			cout << " " << endl;
			int choise;
			do
			{
				cin >> choise;
				switch (choise)
				{
				case 1:
					magik();
					return;
				case 2:
					setup();
					return;
				case 3:
					goto stop;
					break;
				default:
					cout << "Пожалуйста, внимательно выберите один из вариантов..." << endl;
					break;
				}
			} 
			while (choise != 3);
		stop:
			cout << " " << endl;
			cout << "Выход..." << endl;
			cout << " " << endl;
}

void number()
{
		int x, ch, m;
		cout << "Итак, начнём!" << endl;
		cout << "" << endl;
		cout << "1. Для начала умножте число вашего рождения на 2" << endl;
		cout << "2. Теперь прибавьте к получившемуся числу 5" << endl;
		cout << "3. Умножте получившееся число на 50" << endl;
		cout << "4. А теперь прибавьте к получившемуся числу номер месяца вашего рождения" << endl;
		cout << "" << endl;
		cout << "Введите получившееся число:" << endl;
		cin >> x;
		cout << "" << endl;
		ch = (x - 250) / 100;
		m = (x - 250) - (ch * 100);
		if (ch >= 1 || ch <= 31)
		{
			if (m == 1)
			{
				cout << "Итак, если вы всё сделали верно, вы родились " << ch << " января!" << endl;
				cout << "" << endl;
				cout << "" << endl;
			}
			if (m == 2)
			{
				cout << "Итак, если вы всё сделали верно, вы родились " << ch << " февраля!" << endl;
				cout << "" << endl;
				cout << "" << endl;
			}
			if (m == 3)
			{
				cout << "Итак, если вы всё сделали верно, вы родились " << ch << " марта!" << endl;
				cout << "" << endl;
				cout << "" << endl;
			}
			if (m == 4)
			{
				cout << "Итак, если вы всё сделали верно, вы родились " << ch << " апреля!" << endl;
				cout << "" << endl;
				cout << "" << endl;
			}
			if (m == 5)
			{
				cout << "Итак, если вы всё сделали верно, вы родились " << ch << " мая!" << endl;
				cout << "" << endl;
				cout << "" << endl;
			}
			if (m == 6)
			{
				cout << "Итак, если вы всё сделали верно, вы родились " << ch << " июня!" << endl;
				cout << "" << endl;
				cout << "" << endl;
			}
			if (m == 7)
			{
				cout << "Итак, если вы всё сделали верно, вы родились " << ch << " июля!" << endl;
				cout << "" << endl;
				cout << "" << endl;
			}
			if (m == 8)
			{
				cout << "Итак, если вы всё сделали верно, вы родились " << ch << " августа!" << endl;
				cout << "" << endl;
				cout << "" << endl;
			}
			if (m == 9)
			{
				cout << "Итак, если вы всё сделали верно, вы родились " << ch << " сентября!" << endl;
				cout << "" << endl;
				cout << "" << endl;
			}
			if (m == 10)
			{
				cout << "Итак, если вы всё сделали верно, вы родились " << ch << " октября!" << endl;
				cout << "" << endl;
				cout << "" << endl;
			}
			if (m == 11)
			{
				cout << "Итак, если вы всё сделали верно, вы родились " << ch << " ноября!" << endl;
				cout << "" << endl;
				cout << "" << endl;
			}
			if (m == 12)
			{
				cout << "Итак, если вы всё сделали верно, вы родились " << ch << " декабря!" << endl;
				cout << "" << endl;
				cout << "" << endl;
			}
			if (m < 1 || m >12)
			{
				cout << "Упс... Что-то пошло не так." << endl;
				cout << "Как насчёт провести вычисления на калькуляторе...? :)" << endl;
				cout << "" << endl;
				cout << "" << endl;
			}
		}
		if (ch < 1 || ch > 31)
		{
			cout << "Упс... Что-то пошло не так." << endl;
			cout << "Как насчёт провести вычисления на калькуляторе...? :)" << endl;
			cout << "" << endl;
			cout << "" << endl;
		}
		cout << "1 - сыграть ещё раз" << endl;
		cout << "2 - вернуться к выбору игр" << endl;
		cout << "3 - ВЫХОД" << endl;
		cout << "" << endl;
		int choise2;
		do
		{
			cin >> choise2;
			if (choise2 >= 1 && choise2 <= 3)
			{
				switch (choise2)
				{
				case 1:
					number();
					return;
				case 2:
					setup();
					return;
				case 3:
					goto exit;
					break;
				}
			}
			else
			{
			cout << "Есть всего три варианта. Пожалуйста, выберите один из них..." << endl;
			}
		} while (choise2 != 3);
	exit:
		cout << " " << endl;
		cout << "Выход..." << endl;
}

void opt()
{
	cout << " " << endl;
	cout << "<Угадай магическое число>" << endl;
	cout << "- сначала вам будет предложено ввести диапазон чисел из которого компьютер сгенерирует случайное." << endl;
	cout << "После нужно будет угадать это число, имея всего 7 попыток." << endl;
	cout << "" << endl;
	cout << "<Очешуей от гениальности компьютера>" << endl;
	cout << "- в этой игре компьютер попытается угадать Вашу дату рождения. Конечно, если Вы обучены математике начальной школы..." << endl;
	cout << " " << endl;
	cout << "Введите 0 для возврата к списку игр" << endl;
	int opt1;
	do
	{
		cin >> opt1;
		switch (opt1)
		{
		case 0:
			setup();
			break;
		default:
			cout << "Что, так тяжело ввести 0?" << endl;
			cout << "" << endl;
			break;
		}
	}
	while (opt1 < 0 || opt1>0);

}

int setup()
{
	int option;
	cout << "Выберите игру:" << endl;
	cout << " " << endl;
	cout << "1 - <Угадай магическое число>" << endl;
	cout << "2 - <Очешуей от гениальности компьютера>" << endl;
	cout << "3 - посмотреть описание игр" << endl;
	cout << "4 - выйти из программы" << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << "Итак, Ваш выбор:" << endl;
	vibor:
		cin >> option;
		if (option >= 1 && option <= 4)
		{
			switch (option)
			{
			case 1:
				magik();
				break;
			case 2:
				number();
				break;
			case 3:
				opt();
				break;
			case 4:
				cout << "Выход..." << endl;
				break;
			}
		}
		else
		{
			cout << "" << endl;
			cout << "Пожалуйста, внимательно выберите один из вариантов..." << endl;
			cout << "" << endl;
			goto vibor;
		}
return 0;
} 



int main()
{
	setlocale(LC_ALL, "Russian");
	setup();
    return 0;
}
