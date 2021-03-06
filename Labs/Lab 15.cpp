#include "stdafx.h"
#include <iostream>
#include <ctime>

class list
{
private:

	class node
	{
	public:
		int data;
		node *nptr;
		node *pptr;


		node(int data = 0, node *ppptr = NULL)
		{
			this->data = data;
			if(!this->pptr)
				this->pptr = ppptr;
		}
	};

public:

	list()
	{
		size = 0;
		buf_size = 0;
		buf = 0;
		head = NULL;
		buf = NULL;
		last_head = NULL;
	}
	~list()
	{
		clear();
		clear_buf();
	}

	void push_back(int data)
	{

		if (head == NULL)
		{
			head = new node(data);
			last_head = head;
		}
		else
		{
			node *temp = last_head;
			temp->nptr = new node(data, temp);
			last_head = temp->nptr;
		}
			size++;
	}
	void push_buf(int data)
	{
		if (buf == NULL)
			buf = new node(data);
		else
		{
			node *temp = buf;
			while (temp->nptr)
				temp = temp->nptr;
			temp->nptr = new node(data, temp);
		}
		buf_size++;
	}
	void pop_front()
	{
		node *temp = head;
		head = head->nptr;
		delete temp;
		size--;
	}
	void pop_front_buf()
	{
		node *temp = buf;
		buf = buf->nptr;
		delete temp;
		buf_size--;
	}
	void clear()
	{
		while (size)
			pop_front();
	}
	void clear_buf()
	{
		while (buf_size)
			pop_front_buf();
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
				temp = temp->nptr;
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
	void display_rev()
	{
		if (last_head)
		{
			std::cout << std::endl;
			std::cout << size << " nodes:" << std::endl;
			node *temp = last_head;
			do
			{
				std::cout << temp->data << " ";
				temp = temp->pptr;
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
	node *mass(node *data, int n)
	{
		int k = 0;
		node *temp = data;
		while (k < n)
		{
			temp = temp->nptr;
			k++;
		}
		return temp;
	}
	void sort(int l, int r)
	{
		node *temp = head;
		if (l == r)
			return;
		if (r - l == 1)
			if (mass(temp, l)->data > mass(temp, r)->data)
				std::swap(mass(temp, l)->data, mass(temp, r)->data);
		int mid = (l + r) / 2;
		sort(l, mid);
		sort(mid + 1, r);

		int l2 = l;
		int r2 = mid + 1;
		buf_size = 0;

		while (r - l + 1 != buf_size)
		{
			if (l2 > mid)
				push_buf(mass(temp, r2++)->data);
			else if (r2 > r)
				push_buf(mass(temp, l2++)->data);
			else if (mass(temp, l2)->data > mass(temp, r2)->data)
				push_buf(mass(temp, r2++)->data);
			else
				push_buf(mass(temp, l2++)->data);	
		}
		for (int i = 0; i < buf_size; i++)
			mass(temp, i + l)->data = mass(buf, i)->data;
		clear_buf();
	}
	void min_el()
	{
		node *temp = head;
		int n = 0;
		int m_id = 0;
		int min = head->data;
		while (temp->nptr)
		{
			if (min > temp->data)
			{
				min = temp->data;
				m_id = n;
			}
			temp = temp->nptr;
			n++;
		}
		std::swap(mass(head, 0)->data, mass(head, m_id)->data);
	}
	void positive_negative()
	{
		node *temp = head;
		node *positive = NULL;
		node *negative = NULL;
		while (temp)
		{
			if (temp->data > 0)
			{
				if (positive == NULL)
					positive = new node(temp->data);
				else
				{
					node *temp2 = positive;
					while (temp2->nptr)
						temp2 = temp2->nptr;
					temp2->nptr = new node(temp->data, temp2);
				}
			}
			else if(temp->data < 0)
			{
				if (negative == NULL)
					negative = new node(temp->data);
				else
				{
					node *temp2 = negative;
					while (temp2->nptr)
						temp2 = temp2->nptr;
					temp2->nptr = new node(temp->data, temp2);
				}
			}
			temp = temp->nptr;
		}

		if (positive)
		{
			std::cout << std::endl;
			std::cout << "Positive values:" << std::endl;
			temp = positive;
			while (temp)
			{
				std::cout << temp->data << " ";
				temp = temp->nptr;
			}
			std::cout << std::endl;
			std::cout << std::endl;
		}
		else
		{
			std::cout << std::endl;
			std::cout << "There are no positive values..." << std::endl;
			std::cout << std::endl;
		}
		if (negative)
		{
			std::cout << "Negative values:" << std::endl;
			temp = negative;
			while (temp)
			{
				std::cout << temp->data << " ";
				temp = temp->nptr;
			}
			std::cout << std::endl;
			std::cout << std::endl;
		}
		else
		{
			std::cout << std::endl;
			std::cout << "There are no negative values..." << std::endl;
			std::cout << std::endl;
		}
	}
	void del_between_max_and_min()
	{
		int n = 0;
		int id_min = 0;
		int id_max = 0;
		int min = head->data;
		int max = head->data;
		node *temp = head;
		while (temp)
		{
			if (min < temp->data)
			{
				min = temp->data;
				id_min = n;
			}
			if (max > temp->data)
			{
				max = temp->data;
				id_max = n;
			}
			temp = temp->nptr;
			n++;
		}

		if (id_min < id_max)
		{
			temp = mass(head, id_min);
			while (temp->nptr->data != max)
			{
				node *del;
				del = temp->nptr;
				temp->nptr = temp->nptr->nptr;
				temp->nptr->pptr = temp;
				delete del;
				size--;
			}
		}
		else if (id_max < id_min)
		{
			temp = mass(head, id_max);
			while (temp->nptr->data != min)
			{
				node *del;
				del = temp->nptr;
				temp->nptr = temp->nptr->nptr;
				temp->nptr->pptr = temp;
				delete del;
				size--;
			}
		}
	}
	void move()
	{
		system("cls");
		int n = 0;
		int k = 0;
		std::cout << std::endl;
		std::cout << "Enter number of positions on which need move list: ";
		std::cin >> n;
		std::cin.ignore();

		while (k < n)
		{
			node *temp = head;
			int val = head->data;
			while (temp->nptr)
			{
				temp->data = temp->nptr->data;
				temp = temp->nptr;
			}
			last_head->data = val;
			k++;
		}
	}
	void delete_similar()
	{
		for (int k = 0; k < size; k++)
		{
			int n = 0;
			for (int i = 0; i < size; i++)
			{

				node *temp = mass(head, k);
				node *temp2 = mass(head, i);
				if (temp->data == temp2->data)
					n++;
				if (n == 2)
				{
					node *del = temp2;
					temp2->pptr->nptr = temp2->nptr;
					temp2->nptr->pptr = temp2->pptr;
					delete del;
					size--;
					n = 1;
				}
			}
		}
	}

	int size;
	int buf_size;
	node *head;
	node *last_head;
	node *buf;
};

int main()
{
	list base;
	srand(time(NULL));

	for (int i = 0; i < 20; i++)
		base.push_back(rand() % 20);

	int choice = 0;
	do
	{
		system("cls");
		std::cout << std::endl;
		std::cout << "Queue consists of all random values of 20 elements" << std::endl;
		std::cout << std::endl;
		std::cout << "0 - display main queue" << std::endl;
		std::cout << "9 - sort list" << std::endl;
		std::cout << "8 - display in reverse order" << std::endl;
		std::cout << std::endl;
		std::cout << "1 - find minimal element and put on first place" << std::endl;
		std::cout << "2 - create two lists with positive and negative values" << std::endl;
		std::cout << "3 - delete all elements which situated between maximal and minimal value" << std::endl;
		std::cout << "4 - move the list items to the specified number of positions" << std::endl;
		std::cout << "5 - delete all similar values" << std::endl;
		std::cout << "6 - EXIT" << std::endl;
		std::cout << std::endl;
		std::cin >> choice;
		std::cin.ignore();
		switch (choice)
		{
		case 8:
			base.display_rev();
			system("pause");
			break;
		case 9:
			base.sort(0, base.size - 1);
			std::cout << std::endl;
			std::cout << "Done!" << std::endl;
			std::cout << std::endl;
			system("pause");
			break;
		case 0:
			base.display();
			std::cout << std::endl;
			system("pause");
			break;
		case 1:
			base.min_el();
			std::cout << std::endl;
			std::cout << "Done!" << std::endl;
			std::cout << std::endl;
			system("pause");
			break;
		case 2:
			base.positive_negative();
			system("pause");
			break;
		case 3:
			base.del_between_max_and_min();
			std::cout << std::endl;
			std::cout << "Done!" << std::endl;
			std::cout << std::endl;
			system("pause");
			break;
		case 4:
			base.move();
			std::cout << std::endl;
			std::cout << "Done!" << std::endl;
			std::cout << std::endl;
			system("pause");
			break;
		case 5:
			base.delete_similar();
			std::cout << std::endl;
			std::cout << "Done!" << std::endl;
			std::cout << std::endl;
			system("pause");
			break;
		case 6:
			std::cout << std::endl;
			std::cout << "Exit..." << std::endl;
			std::cout << std::endl;
			return 0;
		}
	} while (choice >= 0 && choice < 10);

	return 0;
}