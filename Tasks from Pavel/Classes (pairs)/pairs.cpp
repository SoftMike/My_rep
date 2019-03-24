#include "pch.h"
#include <iostream>
#include <string>
#include "pairs.h"
/*



template<class K, class D> BASE<K, D>::BASE()
	{
		key = NULL;
		data = NULL;
		next = NULL;
		size = 0;
	}
template<class K, class D> BASE<K, D>::~BASE()
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
template<class K, class D> BASE<K, D> &BASE<K, D>::operator[](int i)
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

	template<class K, class D> void BASE<K, D>::add(K key, D data)
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
	template<class K, class D> void BASE<K, D>::display()
	{
		system("cls");
		for (int i = 0; i < size; ++i)
		{
			std::cout << *(*this)[i].key << std::endl;
			std::cout << *(*this)[i].data << "\n\n";
		}
		system("pause");
	}
	template<class K, class D> void BASE<K, D>::deleting()
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
	template<class K, class D> void BASE<K, D>::edit()
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
	*/