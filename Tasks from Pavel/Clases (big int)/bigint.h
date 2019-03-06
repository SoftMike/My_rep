#pragma once
class bigint
{
	char *s;

public:

	bigint(int n = 0);
	~bigint();
	bigint(const bigint &obj);
	bigint operator=(bigint obj);
	bigint operator=(const char *mass);
	bigint operator+(bigint val);
	bigint operator+(int valint);
	friend bigint operator+(int valint, bigint val);
	void set();
	void display();
	void reverse();
};