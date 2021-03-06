#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <queue>

class TREE
{
public:
	class NODE
	{
	public:
		NODE *left;
		NODE *right;
		int data;
		NODE(int data = 0)
		{
			left = NULL;
			right = NULL;
			this->data = data;
		}
	} *node;

	TREE()
	{
		node = NULL;
		r_size = 0;
		two_daughters_size = 0;
	}
	~TREE()
	{
		clear(&node);
	}
	void push(int data, NODE **node)
	{
		if (!(*node))
		{
			*node = new NODE(data);
			r_size++;
		}
		else if (data > (*node)->data)
			push(data, &(*node)->right);
		else
			push(data, &(*node)->left);
	}
	void display_dir(NODE *node)
	{
		if (!node)
			return;
		else
		{
			std::cout << node->data << " ";
			display_dir(node->left);
			display_dir(node->right);
		}
	}
	void display_rev(NODE *node)
	{
		if (!node)
			return;
		else
		{
			display_dir(node->left);
			display_dir(node->right);
		}
		std::cout << node->data << " ";
	}
	void display_asc()
	{
		if (!node)
			return;
		else
		{
			std::queue<NODE *> queue;
			queue.push(node);
			while (!queue.empty())
			{
				NODE *temp = queue.front();
				queue.pop();
				if (temp)
					std::cout << temp->data << " ";
				if (temp->left)
					queue.push(temp->left);
				if (temp->right)
					queue.push(temp->right);
			}
		}
	}
	void clear(NODE **next)
	{
		if (!(*next))
			return;
		else
		{
			clear(&(*next)->left);
			clear(&(*next)->right);
		}
		delete *next;
		*next = NULL;
		r_size--;
	}
	NODE *find(int data, NODE *roots)
	{
		if (!roots)
			return 0;
		else
		{
			if (data == roots->data)
			{
				std::cout << std::endl;
				std::cout << "Data found: ";
				std::cout << roots->data << std::endl;
				std::cout << std::endl;
				return roots;
			}
			else if (data > roots->data)
				find(data, roots->right);
			else if (data < roots->data)
				find(data, roots->left);
		}
	}
	NODE *find_root(int data, NODE *roots)
	{
		if (!roots)
			return 0;
		else
		{
			if (node->data == data)
				return node;

			if (roots->left)
			{
				if (data == roots->left->data)
					return roots;
			}
			if (roots->right)
			{
				if (data == roots->right->data)
					return roots;
			}
			if (data > roots->data)
				find_root(data, roots->right);
			else if (data < roots->data)
				find_root(data, roots->left);
		}
	}
	void de_lete(NODE *data, int val)
	{
		if (!data)
			return;
		else
		{
			if (data->data != val)
			{
				if (data->left && data->left->data == val)
				{
					if (!data->left->left && !data->left->right)
					{
						NODE *del = data->left;
						data->left = NULL;
						delete del;
						r_size--;
					}
					else if (data->left->left && !data->left->right)
					{
						NODE *del = data->left;
						data->left = data->left->left;
						delete del;
						r_size--;
					}
					else if (!data->left->left && data->left->right)
					{
						NODE *del = data->left;
						data->left = data->left->right;
						delete del;
						r_size--;
					}
					else if (data->left->left && data->left->right)
					{
						NODE *temp = data->left->right;
						if (temp->left)
						{
							while (temp->left)
								temp = temp->left;
							data->left->data = temp->data;

							NODE *del = data->left->right;
							while (del->left && del->left->data != temp->data)
								del = del->left;
							del->left = NULL;
							delete temp;
							r_size--;
						}
						else
						{
							NODE *del = data->left;
							temp->left = data->left->left;
							data->left = temp;
							delete del;
							r_size--;
						}
					}
				}////////////////////////////////////////////////////////
				else if (data->right && data->right->data == val)
				{
					if (!data->right->left && !data->right->right)
					{
						NODE *del = data->right;
						data->right = NULL;
						delete del;
						r_size--;
					}
					else if ((data->right->left && !data->right->right))
					{
						NODE *del = data->right;
						data->right = data->right->left;
						delete del;
						r_size--;
					}
					else if ((!data->right->left && data->right->right))
					{
						NODE *del = data->right;
						data->right = data->right->right;
						delete del;
						r_size--;
					}
					else if (data->right->left && data->right->right)
					{
						NODE *temp = data->right->right;
						if (temp->left)
						{
							while (temp->left)
								temp = temp->left;
							data->right->data = temp->data;

							NODE *del = data->right->right;
							while (del->left && del->left->data != temp->data)
								del = del->left;
							del->left = NULL;
							delete temp;
							r_size--;
						}
						else
						{
							NODE *del = data->right;
							temp->left = data->right->left;
							data->right = temp;
							delete del;
							r_size--;
						}
					}
				}
			}
			else
			{
				if (!data->left && !data->right)
				{
					delete node;
					node = NULL;
					r_size--;
				}
				else if (data->left && !data->right)
				{
					NODE *del = node;
					node = node->left;
					delete del;
					r_size--;
				}
				else if (!data->left && data->right)
				{
					NODE *del = node;
					node = node->right;
					delete del;
					r_size--;
				}
				else if (data->left && data->right)
				{
					NODE *temp = data->right;
					if (temp->left)
					{
						while (temp->left)
							temp = temp->left;
						data->data = temp->data;

						NODE *del = data->right;
						while (del->left && del->left->data != temp->data)
							del = del->left;
						del->left = NULL;
						delete temp;
						r_size--;
					}
					else
					{
						data->data = temp->data;
						data->right = NULL;
						delete temp;
						r_size--;
					}
				}
			}
			std::cout << std::endl;
			std::cout << "Deleting done!" << std::endl;
			std::cout << std::endl;
		}
	}
	void swap_maxmin()
	{
		NODE *max = node;
		NODE *min = node;
		while (min->left)
			min = min->left;
		while (max->right)
			max = max->right;
		std::swap(max->data, min->data);
		std::cout << std::endl;
		std::cout << "Done!" << std::endl;
		std::cout << std::endl;
	}
	int leaves(NODE *tree)
	{
		if (!tree)
			return 0;
		if (!tree->left && !tree->right)
			return 1;
		return leaves(tree->left) + leaves(tree->right);
	}
	void delete_branch(int value)
	{
		NODE *del = find_root(value, node);

		if (value != node->data)
		{
			if (del)
			{
				if (del->left->data == value)
				{
					clear(&del->left);
					del->left = NULL;
					std::cout << std::endl;
					std::cout << "Deleting was done successfully!" << std::endl;
					std::cout << std::endl;
					return;
				}
				if (del->right->data == value)
				{
					clear(&del->right);
					del->right = NULL;
					std::cout << std::endl;
					std::cout << "Deleting was done successfully!" << std::endl;
					std::cout << std::endl;
					return;
				}
			}
			else
			{
				std::cout << std::endl;
				std::cout << "There is no such value..." << std::endl;
				std::cout << std::endl;
			}
		}
		else
		{
			clear(&node);
			std::cout << std::endl;
			std::cout << "Deleting was done successfully!" << std::endl;
			std::cout << std::endl;
		}
	}
	int depth(NODE *tree, int n = 0)
	{
		if (!tree)
			return n;
		return depth(tree->left, n++), depth(tree->right, n++);
	}
	int two_daughters(NODE *tree)
	{
		if (!tree)
			return 0;

		if (tree->left && tree->right)
			two_daughters_size++;

		two_daughters(tree->left);
		two_daughters(tree->right);
	}

	int r_size;
	int two_daughters_size;
};

int main()
{
	TREE base;
	srand(time(NULL));
		/*
	for (int i = 1; i < 51; i++)
		base.push(i, &base.node);
		*/

	base.push(50, &base.node);
	base.push(30, &base.node);
	base.push(29, &base.node);
	base.push(31, &base.node);


	base.push(52, &base.node);
	base.push(51, &base.node);
	base.push(53, &base.node);


	int choice = 0;
	int data = 0;
	do
	{
		system("cls");
		std::cout << std::endl;
		std::cout << "Tree consists of all random values of 20 elements" << std::endl;
		std::cout << std::endl;
		std::cout << "0 -   display tree in ascending order" << std::endl;
		std::cout << "9 -   print tree direct bypass" << std::endl;
		std::cout << "8 -   map the tree backwards" << std::endl;
		std::cout << "7 -   add new DATA" << std::endl;
		std::cout << "77 -  find value" << std::endl;
		std::cout << "777 - find and delete value" << std::endl;
		std::cout << std::endl;
		std::cout << "1 - swap maximal and minimal values" << std::endl;
		std::cout << "2 - count the leaves on the tree" << std::endl;
		std::cout << "3 - delete branch which has entering value" << std::endl;
		std::cout << "4 - count the maximum depth of the tree" << std::endl;
		std::cout << "5 - count the number of nodes in the tree that have two daughters" << std::endl;
		std::cout << "6 - EXIT" << std::endl;
		std::cout << std::endl;
		std::cin >> choice;
		std::cin.ignore();
		switch (choice)
		{
		case 0:
			std::cout << std::endl;
			std::cout << "There are " << base.r_size << " roots in the tree:" << std::endl;
			base.display_asc();
			std::cout << std::endl;
			system("pause");
			break;
		case 9:
			std::cout << std::endl;
			std::cout << "There are " << base.r_size << " roots in the tree:" << std::endl;
			base.display_dir(base.node);
			std::cout << std::endl;
			system("pause");
			break;
		case 8:
			std::cout << std::endl;
			std::cout << "There are " << base.r_size << " roots in the tree:" << std::endl;
			base.display_rev(base.node);
			std::cout << std::endl;
			system("pause");
			break;
		case 7:
			std::cout << std::endl;
			std::cout << "Enter value: ";
			std::cin >> data;
			std::cin.ignore();
			base.push(data, &base.node);
			break;
		case 77:
			std::cout << std::endl;
			std::cout << "Enter finding value: ";
			std::cin >> data;
			std::cin.ignore();
			base.find(data, base.node);
			system("pause");
			break;
		case 777:
			std::cout << std::endl;
			std::cout << "Enter finding value: ";
			std::cin >> data;
			std::cin.ignore();
			base.de_lete(base.find_root(data, base.node), data);
			system("pause");
			break;
		case 1:
			base.swap_maxmin();
			system("pause");
			break;
		case 2:
			std::cout << std::endl;
			std::cout << "There are: " << base.leaves(base.node) << " leaves in the tree." << std::endl;
			std::cout << std::endl;
			system("pause");
			break;
		case 3:
			std::cout << std::endl;
			std::cout << "Enter value: ";
			std::cin >> data;
			std::cin.ignore();
			base.delete_branch(data);
			system("pause");
			break;
		case 4:
			std::cout << std::endl;
			std::cout << "Maximal depth is: " << base.depth(base.node) << " nodes" << std::endl;
			std::cout << std::endl;
			system("pause");
			break;
		case 5:
			std::cout << std::endl;
			base.two_daughters(base.node);
			std::cout << "Count of two daughters nodes is: " << base.two_daughters_size << std::endl;
			std::cout << std::endl;
			base.two_daughters_size = 0;
			system("pause");
			break;
		case 6:
			std::cout << std::endl;
			std::cout << "Exit..." << std::endl;
			std::cout << std::endl;
			return 0;
		}
	} while (choice >= 0 && choice < 778);

    return 0;
}


/*
#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <queue>

class TREE
{
public:
class NODE
{
public:
NODE *left;
NODE *right;
int data;
NODE(int data = 0)
{
left = NULL;
right = NULL;
this->data = data;
}
} *node;
class QUEUE
{
public:
int data;
QUEUE *nptr;
QUEUE *pptr;


QUEUE(int data = 0, QUEUE *ppptr = NULL)
{
this->data = data;
if (!this->pptr)
this->pptr = ppptr;
}
} *queue;

TREE()
{
node = NULL;
r_size = 0;
q_size = 0;
last_queue = NULL;
}
~TREE()
{
clear_q();
clear(&node);
}
void push(int data, NODE **node)
{
if (!(*node))
{
*node = new NODE(data);
r_size++;
}
else if (data > (*node)->data)
push(data, &(*node)->right);
else
push(data, &(*node)->left);
}
void display_dir(NODE *node)
{
if (!node)
return;
else
{
std::cout << node->data << " ";
display_dir(node->left);
display_dir(node->right);
}
}
void display_rev(NODE *node)
{
if (!node)
return;
else
{
display_dir(node->left);
display_dir(node->right);
}
std::cout << node->data << " ";
}
void display_asc()
{
if (!node)
return;
else
{
std::queue<NODE *> queue;
queue.push(node);
while (!queue.empty())
{
NODE *temp = queue.front();
queue.pop();
if (temp)
std::cout << temp->data << " ";
if (temp->left)
queue.push(temp->left);
if (temp->right)
queue.push(temp->right);
}
}
}
void clear(NODE **next)
{
if (!(*next))
return;
else
{
clear(&(*next)->left);
clear(&(*next)->right);
}
delete *next;
*next = NULL;
}
NODE *find(int data, NODE *roots)
{
if (!roots)
return 0;
else
{
if (data == roots->data)
{
std::cout << std::endl;
std::cout << "Data found: ";
std::cout << roots->data << std::endl;
std::cout << std::endl;
return roots;
}
else if (data > roots->data)
find(data, roots->right);
else if (data < roots->data)
find(data, roots->left);
}
}
NODE *find_root(int data, NODE *roots)
{
if (!roots)
return 0;
else
{
if (node->data == data)
return node;

if (roots->left)
{
if (data == roots->left->data)
return roots;
}
if (roots->right)
{
if (data == roots->right->data)
return roots;
}
if (data > roots->data)
find_root(data, roots->right);
else if (data < roots->data)
find_root(data, roots->left);
}

}
void de_lete(NODE *data, int val)
{
if (!data)
return;
else
{
if (data->data != val)
{
if (data->left && data->left->data == val)
{
if (!data->left->left && !data->left->right)
{
NODE *del = data->left;
data->left = NULL;
delete del;
r_size--;
}
else if (data->left->left && !data->left->right)
{
NODE *del = data->left;
data->left = data->left->left;
delete del;
r_size--;
}
else if (!data->left->left && data->left->right)
{
NODE *del = data->left;
data->left = data->left->right;
delete del;
r_size--;
}
else if (data->left->left && data->left->right)
{
NODE *temp = data->left->right;
if (temp->left)
{
while (temp->left)
temp = temp->left;
data->left->data = temp->data;

NODE *del = data->left->right;
while (del->left && del->left->data != temp->data)
del = del->left;
del->left = NULL;
delete temp;
r_size--;
}
else
{
NODE *del = data->left;
temp->left = data->left->left;
data->left = temp;
delete del;
r_size--;
}
}
}////////////////////////////////////////////////////////
else if (data->right && data->right->data == val)
{
if (!data->right->left && !data->right->right)
{
NODE *del = data->right;
data->right = NULL;
delete del;
r_size--;
}
else if ((data->right->left && !data->right->right))
{
NODE *del = data->right;
data->right = data->right->left;
delete del;
r_size--;
}
else if ((!data->right->left && data->right->right))
{
NODE *del = data->right;
data->right = data->right->right;
delete del;
r_size--;
}
else if (data->right->left && data->right->right)
{
NODE *temp = data->right->right;
if (temp->left)
{
while (temp->left)
temp = temp->left;
data->right->data = temp->data;

NODE *del = data->right->right;
while (del->left && del->left->data != temp->data)
del = del->left;
del->left = NULL;
delete temp;
r_size--;
}
else
{
NODE *del = data->right;
temp->left = data->right->left;
data->right = temp;
delete del;
r_size--;
}
}
}
}
else
{
if (!data->left && !data->right)
{
delete node;
node = NULL;
r_size--;
}
else if (data->left && !data->right)
{
NODE *del = node;
node = node->left;
delete del;
r_size--;
}
else if (!data->left && data->right)
{
NODE *del = node;
node = node->right;
delete del;
r_size--;
}
else if (data->left && data->right)
{
NODE *temp = data->right;
if (temp->left)
{
while (temp->left)
temp = temp->left;
data->data = temp->data;

NODE *del = data->right;
while (del->left && del->left->data != temp->data)
del = del->left;
del->left = NULL;
delete temp;
r_size--;
}
else
{
data->data = temp->data;
data->right = NULL;
delete temp;
r_size--;
}
}
}
std::cout << std::endl;
std::cout << "Deleting done!" << std::endl;
std::cout << std::endl;
}
}



void push_back_q(int data)
{

if (queue == NULL)
{
queue = new QUEUE(data);
last_queue = queue;
}
else
{
QUEUE *temp = last_queue;
temp->nptr = new QUEUE(data, temp);
last_queue = temp->nptr;
}
q_size++;
}
void pop_front_q()
{
QUEUE *temp = queue;
queue = queue->nptr;
delete temp;
q_size--;
}
void clear_q()
{
while (q_size)
pop_front_q();
}
void display_q()
{
if (queue)
{
std::cout << std::endl;
std::cout << q_size << " nodes in the queue:" << std::endl;
QUEUE *temp = queue;
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
std::cout << "The queue is empty" << std::endl;
std::cout << std::endl;
}
}


int r_size;
int q_size;
QUEUE *last_queue;
};

int main()
{
TREE base;
srand(time(NULL));

for (int i = 1; i < 51; i++)
base.push(i, &base.node);

int choice = 0;
int data = 0;
do
{
system("cls");
std::cout << std::endl;
std::cout << "Tree consists of all random values of 20 elements" << std::endl;
std::cout << std::endl;
std::cout << "0 -   display tree in ascending order" << std::endl;
std::cout << "9 -   print tree direct bypass" << std::endl;
std::cout << "8 -   map the tree backwards" << std::endl;
std::cout << "7 -   add new DATA" << std::endl;
std::cout << "77 -  find value" << std::endl;
std::cout << "777 - find and delete value" << std::endl;
std::cout << std::endl;
std::cout << "1 - swap maximal and minimal values" << std::endl;
std::cout << "2 - " << std::endl;
std::cout << "3 - " << std::endl;
std::cout << "4 - " << std::endl;
std::cout << "5 - " << std::endl;
std::cout << "6 - EXIT" << std::endl;
std::cout << std::endl;
std::cin >> choice;
std::cin.ignore();
switch (choice)
{
case 0:
std::cout << std::endl;
std::cout << "There are " << base.r_size << " roots in the tree:" << std::endl;
base.display_asc();
std::cout << std::endl;
system("pause");
break;
case 9:
std::cout << std::endl;
std::cout << "There are " << base.r_size << " roots in the tree:" << std::endl;
base.display_dir(base.node);
std::cout << std::endl;
system("pause");
break;
case 8:
std::cout << std::endl;
std::cout << "There are " << base.r_size << " roots in the tree:" << std::endl;
base.display_rev(base.node);
std::cout << std::endl;
system("pause");
break;
case 7:
std::cout << std::endl;
std::cout << "Enter value: ";
std::cin >> data;
std::cin.ignore();
base.push(data, &base.node);
break;
case 77:
std::cout << std::endl;
std::cout << "Enter finding value: ";
std::cin >> data;
std::cin.ignore();
base.find(data, base.node);
system("pause");
break;
case 777:
std::cout << std::endl;
std::cout << "Enter finding value: ";
std::cin >> data;
std::cin.ignore();
base.de_lete(base.find_root(data, base.node), data);
system("pause");
break;
case 1:

system("pause");
break;
case 2:

system("pause");
break;
case 3:

system("pause");
break;
case 4:

system("pause");
break;
case 5:

system("pause");
break;
case 6:
std::cout << std::endl;
std::cout << "Exit..." << std::endl;
std::cout << std::endl;
return 0;
}
} while (choice >= 0 && choice < 778);

return 0;
}
*/
