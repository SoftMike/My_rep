#include "pch.h"
#include <iostream>
#include <string>
#include "list.h"

list::list()
	{
		data = NULL;
		next = NULL;
	}
list::~list()
	{
		clear();
	}
std::string &list::operator[](int i)
	{
		int n = 0;
		list *temp = this->next;
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
void list::clear_data()
	{
		if (this->next->data)
		{
			list *top, *temp;
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
void list::add()
	{
		std::cout << "Enter text:\n\n";
		std::string text;
		std::getline(std::cin, text);
		if (!this->data)
		{
			this->data = new std::string;
			*this->data = "\0";
			this->next = new list;
			this->next->data = new std::string;
			*this->next->data = text;
			this->next->next = new list;
		}
		else
		{
			list *temp = this;
			while (temp->next)
				temp = temp->next;
			temp->data = new std::string;
			*temp->data = text;
			temp->next = new list;
		}
	}
void list::display()
	{
		if (this->data)
		{
			list *temp = this;
			while (temp && temp->data)
			{
				if (*temp->data != "\0")
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
void list::search()
	{
		std::string text;
		list *temp = this;
		std::cout << "Enter searching data:\n\n";
		std::getline(std::cin, text);
		while (*temp->data != text)
		{
			if (!temp->next->next)
				break;
			temp = temp->next;
		}
		if (*temp->data == text)
		{
			std::cout << "Founded data:\n\n";
			std::cout << *temp->data << std::endl;
		}
		else
			std::cout << "Data didn't find...\n";
	}
void list::delete_data()
	{
		std::string text;
		list *temp = this;
		std::cout << "Enter searching data:\n\n";
		std::getline(std::cin, text);
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
				list *del = temp->next;
				temp->next = temp->next->next;
				delete del->data;
				del->next = NULL;
				del->data = NULL;
			}
			else
				std::cout << "Data didn't find...\n";
		}
	}
void list::insert()
	{
		std::string text;
		std::cout << "Enter inserting data:\n\n";
		std::getline(std::cin, text);
		list *temp = this;
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
		temp->next->next = new list;
		temp->next->data = new std::string;
		k = n / 2;
		std::string swap = (*this)[k];
		std::string swap2;
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
void list::clear()
	{
		if (this->data)
		{
			list *top, *temp;
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
