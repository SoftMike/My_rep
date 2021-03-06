#include "stdafx.h"
#include <iostream>

class list
{
private:

	class node
	{
	public:
		int data;
		node *ptr;

		node(int data = 0, node *ptr = NULL)
		{
			this->data = data;
			this->ptr = ptr;
		}
	} *head;

public:

	list()
	{
		size = 0;
		head = NULL;
	}
	~list()
	{
		clear();
	}

	void push_back(int data)
	{
		if (head == NULL)
			head = new node(data);
		else
		{
			node *temp = head;
			while (temp->ptr)
				temp = temp->ptr;

			temp->ptr = new node(data);
		}
		size++;
	}
	void pop_front()
	{
		node *temp = head;
		head = head->ptr;
		delete temp;
		size--;
	}
	void clear()
	{
		while (size)
			pop_front();
	}
	void display()
	{
		if (head)
		{
			std::cout << std::endl;
			std::cout << size << " nodes:" << std::endl;
			node *temp = head;
			do
			{
				std::cout << temp->data << " ";
				temp = temp->ptr;
			} while (temp);
			std::cout << std::endl;
		}
		else
		{
			std::cout << std::endl;
			std::cout << "The base is empty" << std::endl;
			std::cout << std::endl;
		}
	}
	void delete_even()
	{
		node *temp = head;

		while (temp->ptr)
		{
			if (!(temp->data % 2) && (temp->data != 0))
			{
				pop_front();
				temp = head;
			}
			else
			{
				if (!(temp->ptr->data % 2) && (temp->ptr->data != 0))
				{
					node *del = temp->ptr;
					temp->ptr = temp->ptr->ptr;
					delete del;
					size--;
				}
				else
					temp = temp->ptr;

			}
		}

		std::cout << std::endl;
		std::cout << "DONE!" << std::endl;
		std::cout << std::endl;
	}
	void swap_extreme()
	{
		node *temp = head;
		int first_data = 0;
		int second_data = 0;
		first_data = head->data;

		while (temp->ptr)
			temp = temp->ptr;

		second_data = temp->data;

		head->data = second_data;
		temp->data = first_data;

		std::cout << std::endl;
		std::cout << "DONE!" << std::endl;
		std::cout << std::endl;
	}
	void delete_every_second()
	{
		node *temp = head;
		if (size == 2)
		{
			node *del;
			del = temp->ptr;
			temp->ptr = NULL;
			delete del;
			std::cout << std::endl;
			std::cout << "DONE!" << std::endl;
			std::cout << std::endl;
			return;
		}
		while (temp->ptr)
		{
			node *del = temp->ptr;
			if (temp->ptr->ptr)
			{
				temp->ptr = temp->ptr->ptr;
				delete del;
				temp = temp->ptr;
				size--;
			}
			else
				break;
		}
		std::cout << std::endl;
		std::cout << "DONE!" << std::endl;
		std::cout << std::endl;
	}
	void delete_before_minimal()
	{
		node *temp = head;
		int minimal_value = head->data;
		while (temp)
		{
			if (temp->data < minimal_value)
				minimal_value = temp->data;
			temp = temp->ptr;
		}

		for(;;)
		{
			if (head->data == minimal_value)
				break;
			pop_front();
		}

		std::cout << std::endl;
		std::cout << "DONE!" << std::endl;
		std::cout << std::endl;
	}
	void delete_before_max_and_min()
	{
		if (size < 3)
		{
			std::cout << std::endl;
			std::cout << "There are only 2 or less positions in the queue..." << std::endl;
			std::cout << std::endl;
			return;
		}
		node *temp = head;
		int minimal_value = head->data;
		int maximal_value = head->data;
		while (temp)
		{
			if (temp->data < minimal_value)
				minimal_value = temp->data;
			if (temp->data > maximal_value)
				maximal_value = temp->data;
			temp = temp->ptr;
		}

		temp = head;

		while (temp)
		{
			if (temp->data == maximal_value || temp->data == minimal_value)
			{
				while (temp->ptr->data != maximal_value && temp->ptr->data != minimal_value)
				{
					node *del = temp->ptr;
					temp->ptr = temp->ptr->ptr;
					delete del;
					size--;
				}
				break;
			}
			else
				temp = temp->ptr;
		}

		std::cout << std::endl;
		std::cout << "DONE!" << std::endl;
		std::cout << std::endl;
	}

	int size;
};

int main()
{
	list base;
	list one;
	list two;

	for(int i = -50; i < 51; i++)
		base.push_back(i);

	int choice = 0;
	do
	{
		system("cls");
		std::cout << std::endl;
		std::cout << "Stack consists of all values between -50 and 50" << std::endl;
		std::cout << std::endl;
		std::cout << "0 - display main queue" << std::endl;
		std::cout << std::endl;
		std::cout << "1 - delete all even values from the queue" << std::endl;
		std::cout << "2 - swap extreme elements" << std::endl;
		std::cout << "3 - delete every second element" << std::endl;
		std::cout << "4 - delete all elements which situated before minimal element" << std::endl;
		std::cout << "5 - delete all elements which situated between maximal and minimal elements" << std::endl;
		std::cout << "6 - EXIT" << std::endl;
		std::cout << std::endl;
		std::cin >> choice;
		std::cin.ignore();
		switch (choice)
		{
		case 0:
			base.display();
			system("pause");
			break;
		case 1:
			base.delete_even();
			system("pause");
			break;
		case 2:
			base.swap_extreme();
			system("pause");
			break;
		case 3:
			base.delete_every_second();
			system("pause");
			break;
		case 4:
			base.delete_before_minimal();
			system("pause");
			break;
		case 5:
			base.delete_before_max_and_min();
			system("pause");
			break;
		}
	} while (choice >= 0 && choice < 6);

	return 0;
}