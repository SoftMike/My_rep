#include "pch.h"
#include <iostream>
#include <string>

template <class T> class list
{
	T *data;
	list<T> *next;
public:
	list();
	~list();
	T &operator[](int i);
	void clear_data();
	void add();
	void display();
	void search();
	void delete_data();
	void insert();
protected:
	void clear();
};

template <class T> list<T>::list()
{
	data = NULL;
	next = NULL;
}
template <class T> list<T>::~list()
{
	clear();
}
template <class T> T &list<T>::operator[](int i)
{
	int n = 0;
	list<T> *temp = this->next;
	while (n != i && temp->next->next)
	{
		temp = temp->next;
		n++;
	}
	if (n == i)
		return *temp->data;
	else
		std::cout << "Invalid data id!\n";
}
template <class T> void list<T>::clear_data()
{
	if (this->next->data)
	{
		list<T> *top, *temp;
		top = this->next;
		temp = this->next;
		while (temp->next)
		{
			temp = temp->next;
			top->next = NULL;
			delete top->data;
			top = temp;
		}
		if (this->data)
		{
			delete this->data;
			this->data = NULL;
			this->next = NULL;
		}
	}
}
template <class T> void list<T>::add()
{
	std::cout << "Enter DATA:\n\n";
	T text;
	std::cin >> text;
	if (!this->data)
	{
		this->data = new T;
		this->next = new list<T>;
		this->next->data = new T;
		*this->next->data = text;
		this->next->next = new list<T>;
	}
	else
	{
		list<T> *temp = this;
		while (temp->next)
			temp = temp->next;
		temp->data = new T;
		*temp->data = text;
		temp->next = new list<T>;
	}
}
template <class T> void list<T>::display()
{
	if (this->data)
	{
		list<T> *temp = this->next;
		while (temp && temp->data)
		{
			std::cout << *temp->data << std::endl;
			if (temp->next)
				temp = temp->next;
			else
				break;
		}
	}
	else
		std::cout << "Data is empty\n";
}
template <class T> void list<T>::search()
{
	T text;
	list<T> *temp = this;
	std::cout << "Enter searching DATA:\n\n";
	std::cin >> text;
	while (*temp->data != text)
	{
		if (!temp->next->next)
			break;
		temp = temp->next;
	}
	if (*temp->data == text)
	{
		std::cout << "Founded DATA:\n\n";
		std::cout << *temp->data << std::endl;
	}
	else
		std::cout << "DATA didn't find...\n";
}
template <class T> void list<T>::delete_data()
{
	T text;
	list<T> *temp = this;
	std::cout << "Enter searching DATA:\n\n";
	std::cin >> text;
	if (*temp->data == text)
	{
		while (temp->next->next)
		{
			temp->data = temp->next->data;
			temp = temp->next;
		}
		delete temp->next->data;
		temp->next->data = NULL;
		temp->next->next = NULL;
	}
	else
	{
		while (*temp->next->data != text)
		{
			if (!temp->next->next->next)
				break;
			temp = temp->next;
		}
		if (*temp->next->data == text)
		{
			std::cout << "Deleted data:\n\n";
			std::cout << *temp->next->data << std::endl;
			list<T> *del = temp->next;
			temp->next = temp->next->next;
			delete del->data;
			del->next = NULL;
			del->data = NULL;
		}
		else
			std::cout << "Data didn't find...\n";
	}
}
template <class T> void list<T>::insert()
{
	T text;
	std::cout << "Enter inserting DATA:\n\n";
	std::cin >> text;
	list<T> *temp = this;
	int n = 0;
	int k = 0;
	if (temp->next)
	{
		while (temp->next->next)
		{
			temp = temp->next;
			n++;
		}
	}
	else
	{
		std::cout << "Data is empty...\n";
		return;
	}
	temp->next->next = new list<T>;
	temp->next->data = new T;
	k = n / 2;
	T swap = (*this)[k];
	T swap2;
	(*this)[k++] = text;
	if (n == 1)
	{
		(*this)[k] = swap;
	}
	else if (n == 2)
	{
		swap2 = (*this)[k];
		(*this)[k++] = swap;
	}
	else
	{
		do
		{
			swap2 = (*this)[k];
			(*this)[k++] = swap;
			swap = swap2;
		} while (k != n);
		(*this)[k] = swap;
	}

}
template <class T> void list<T>::clear()
{
	if (this->data)
	{
		list<T> *top, *temp;
		top = this->next;
		temp = this->next;
		while (temp->next)
		{
			temp = temp->next;
			top->next = NULL;
			delete top->data;
			top = temp;
		}
		if (this->data)
		{
			delete this->data;
			this->data = NULL;
			this->next = NULL;
		}
	}
}

int main()
{
	int choise = 0;
	// DATA choise:
	list<int> base;
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
