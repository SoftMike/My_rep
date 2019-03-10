#pragma once
#include <string>

class list
{
	std::string *data;
	list *next;
public:
	list();
	~list();
	std::string &operator[](int i);
	void clear_data();
	void add();
	void display();
	void search();
	void delete_data();
	void insert();
protected:
	void clear();
};