#include "stdafx.h"
#include <iostream>

class list
{
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

	void push(int data)
	{
		head = new node(data, head);
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
	void separate(list *plus, list *minus)
	{
		node *temp = head;
		do
		{
			if (temp->data > 0)
				plus->push(temp->data);
			if (temp->data < 0)
				minus->push(temp->data);
			temp = temp->ptr;
		} while (temp);
	}
	void even_values(list *one)
	{
		node *temp = head;
		do
		{
			if (!(temp->data % 2) && temp->data != 0)
				one->push(temp->data);
			temp = temp->ptr;
		} while (temp);
	}
	void bigger_than_average(list *one)
	{
		node *temp = head;
		int average = 0;
		do
		{
			average += temp->data;
			temp = temp->ptr;
		} while (temp);
		temp = head;
		do
		{
			if (temp->data > average)
				one->push(temp->data);
			temp = temp->ptr;
		} while (temp);
	}
	void max_and_min()
	{
		node *temp = head;
		int max = 0;
		int min = 0;
		do
		{
			if (temp->data > max)
				max = temp->data;
			if (temp->data < min)
				min = temp->data;
			temp = temp->ptr;
		} while (temp);
		std::cout << std::endl;
		std::cout << "Maximum value: " << max << std::endl;
		std::cout << "Minimum value: " << min << std::endl;
		std::cout << std::endl;
	}
	void between_max_and_min()
	{
		node *temp = head;
		int max = 0;
		int min = 0;
		int n = 0;

		do
		{
			if (temp->data > max)
				max = temp->data;
			if (temp->data < min)
				min = temp->data;
			temp = temp->ptr;
		} while (temp);

		temp = head;

		do
		{
			if (temp->data == max || temp->data == min)
				break;
			temp = temp->ptr;
		} while (temp);

		for (;;)
		{
			temp = temp->ptr;
			n++;
			if (temp->data == max || temp->data == min)
				break;
		}
		n--;

		std::cout << std::endl;
		std::cout << "There are " << n << " elements between maximum and minimum values." << std::endl;
		std::cout << std::endl;
	}

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

	int size;
};


int main()
{
	list base;
	list one;
	list two;
	for (int i = -50; i < 51; i++)
		base.push(i);
	int choice = 0;
	do
	{
		system("cls");
		std::cout << std::endl;
		std::cout << "Stack consists of all values between -50 and 50" << std::endl;
		std::cout << std::endl;
		std::cout << "0 - display main stack" << std::endl;
		std::cout << std::endl;
		std::cout << "1 - separate the stack on positive and negative values by another stacks" << std::endl;
		std::cout << "2 - create new stack which contains even values from main stack" << std::endl;
		std::cout << "3 - create new stack which contains values that bigger than average value of all values from main stack" << std::endl;
		std::cout << "4 - find maximum and minimum values from the stack" << std::endl;
		std::cout << "5 - count how much elements of the stack situated between maximum and minimum values of stack" << std::endl;
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
			base.separate(&one, &two);
			one.display();
			std::cout << std::endl;
			std::cout << std::endl;
			two.display();
			one.clear();
			two.clear();
			system("pause");
			break;
		case 2:
			base.even_values(&one);
			one.display();
			one.clear();
			system("pause");
			break;
		case 3:
			base.bigger_than_average(&one);
			one.display();
			one.clear();
			system("pause");
			break;
		case 4:
			base.max_and_min();
			system("pause");
			break;
		case 5:
			base.between_max_and_min();
			system("pause");
			break;
		}
	} while (choice >= 0 && choice < 6);
	
    return 0;
}

