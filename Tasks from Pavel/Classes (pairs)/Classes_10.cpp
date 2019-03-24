#include "pch.h"
#include <iostream>
#include <string>
#include "pairs.h"

template <class K, class D> class BASE
{
	K *key;
	D *data;
	BASE *next;
	int size;
public:
	BASE()
	{
		key = NULL;
		data = NULL;
		next = NULL;
		size = 0;
	}
	~BASE()
	{
		BASE *top, *temp;
		top = temp = this->next;
		if (temp)
			while (temp->next)
			{
				temp = temp->next;
				top->next = NULL;
				delete top->data;
				delete top->key;
				top = temp;
			}
		if (this->data)
		{
			delete this->data;
			delete this->key;
			this->data = NULL;
			this->next = NULL;
		}
	}
	BASE &operator[](int i)
	{
		int n = 0;
		BASE *temp = this;
		if (i < 0 || i > size - 1)
		{
			std::cout << "Out of DATA!\n" << std::endl;
			exit(1);
		}
		else
		{
			while (n != i)
			{
				temp = temp->next;
				n++;
			}

			return *temp;
		}
	}

	void add(K key, D data)
	{
		system("cls");
		BASE *temp = this;
		if (!this->key)
		{
			this->key = new K;
			this->data = new D;
			*this->key = key;
			*this->data = data;
			size++;
			return;
		}
		else
		{
			if (!temp->next)
			{
				if (*temp->data != data)
				{
					temp->next = new BASE;
					temp = temp->next;
					temp->key = new K;
					temp->data = new D;
					*temp->key = key;
					*temp->data = data;
					size++;
					return;
				}
				else
				{
					std::cout << "This key is not empty!\n";
					system("pause");
					return;
				}
			}
			else
			{
				while (temp->next)
				{
					if (*temp->data == data)
					{
						std::cout << "This key is not empty!\n";
						system("pause");
						return;
					}
					else
					{
						temp = temp->next;
					}
				}
				if (*temp->data == data)
				{
					std::cout << "This key is not empty!\n";
					system("pause");
					return;
				}
				else
				{
					temp->next = new BASE;
					temp = temp->next;
					temp->key = new K;
					temp->data = new D;
					*temp->key = key;
					*temp->data = data;
					size++;
					return;
				}
			}
		}
	}
	void display()
	{
		system("cls");
		for (int i = 0; i < size; ++i)
		{
			std::cout << *(*this)[i].key << std::endl;
			std::cout << *(*this)[i].data << "\n\n";
		}
		system("pause");
	}
	void deleting()
	{
		system("cls");
		K key;
		std::cout << "Enter deleting key: ";
		std::cin >> key;
		for (int i = 0; i < size; ++i)
		{
			if (*(*this)[i].key == key)
			{
				while (i < size - 1)
				{
					*(*this)[i].key = *(*this)[i + 1].key;
					i++;
				}
				BASE *temp = &(*this)[i - 1];

				delete temp->next->key;
				temp->next->key = NULL;
				delete temp->next->data;
				temp->next->data = NULL;
				delete temp->next;
				temp->next = NULL;
				size--;
				std::cout << "DONE!\n";
				system("pause");
				return;
			}
		}
		std::cout << "Invalid key...\n";
		system("pause");
	}
	void edit()
	{
		system("cls");
		K key;
		std::cout << "Enter editing key: ";
		std::cin >> key;
		for (int i = 0; i < size; ++i)
		{
			if (*(*this)[i].key == key)
			{
				std::cout << "Enter new key: ";
				std::cin >> *(*this)[i].key;
				std::cout << "Enter new DATA: ";
				std::cin >> *(*this)[i].data;
				std::cout << "DONE!\n";
				system("pause");
				return;
			}
		}
		std::cout << "Invalid key...\n";
		system("pause");
	}
};

int main()
{
	BASE<std::string, int> base;
	std::string key;
	int data;
	int choice;
	do
	{
		system("cls");
		std::cout << "1 - add DATA\n";
		std::cout << "2 - display DATA\n";
		std::cout << "3 - edit DATA\n";
		std::cout << "4 - delete DATA\n\n\n";
		std::cout << "5 - EXIT\n\n";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			std::cout << "Enter new key: ";
			std::cin >> key;
			std::cout << "Enter new DATA: ";
			std::cin >> data;
			base.add(key, data);
			break;
		case 2:
			base.display();
			break;
		case 3:
			base.edit();
			break;
		case 4:
			base.deleting();
			break;
		case 5:
			return 0;;
		}
	} while (choice > 0 && choice < 6);
}
