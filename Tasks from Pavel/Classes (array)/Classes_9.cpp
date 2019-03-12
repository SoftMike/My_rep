#include "pch.h"
#include <iostream>

template <class T, int size = 10> class array
{
	T *data[size];
public:
	array<T, size>()
	{
		for (int i = 0; i < size; i++)
			this->data[i] = NULL;
	}
	~array<T, size>()
	{
		clear();
	}
	T &operator[](int n)
	{
		if (n >= 0 && n < size)
			return *this->data[n];
		else
		{
			std::cout << "Out of array!\n";
			exit(1);
		}
	}
	void add();
	void display();
	void clear();
	void search();
	void deleting();
};

template <class T, int size> void array<T, size>::add()
{
	std::cout << "Enter DATA:\n\n";
	T data;
	std::cin >> data;
	int n = 0;
	while (n < size)
	{
		if (!this->data[n])
		{
			this->data[n] = new T;
			*this->data[n] = data;
			return;
		}
		else
			n++;
	}
	std::cout << "Array is full!\n";
}
template <class T, int size> void array<T, size>::display()
{
	int n = 0;
	while (n < size)
		if (this->data[n])
			std::cout << *this->data[n++] << std::endl;
		else
			n++;
}
template <class T, int size> void array<T, size>::clear()
{
	for (int i = 0; i < size; i++)
		if (this->data[i])
		{
			delete this->data[i];
			this->data[i] = NULL;
		}
}
template <class T, int size> void array<T, size>::search()
{
	std::cout << "Enter searching DATA:\n\n";
	T data;
	std::cin >> data;
	int n = 0;
	while (n < size)
	{
		if (*this->data[n] == data)
		{
			std::cout << "DATA founded:\n" << *this->data[n] << std::endl;
			return;
		}
		else
			n++;
	}
	std::cout << "Data didn't found...\n";
}
template <class T, int size> void array<T, size>::deleting()
{
	std::cout << "Enter deleting DATA:\n\n";
	T data;
	std::cin >> data;
	int n = 0;
	while (n < size)
	{
		if (*this->data[n] == data)
		{
			std::cout << "Deleting DATA founded:\n" << *this->data[n] << std::endl;
			delete this->data[n];
			this->data[n] = NULL;
			return;
		}
		else
			n++;
	}
	std::cout << "Deleting data didn't found...\n";
}

int main()
{
	array<int, 5> mass;
	mass.add();
	mass.add();
	mass.add();
	mass.add();
	mass.add();
	for (int i = 0; i < 7; i++)
		std::cout << mass[i] << std::endl;
}
