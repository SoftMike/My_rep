#pragma once
class byte
{
	struct data
	{
		unsigned eight : 1;
		unsigned seven : 1;
		unsigned six : 1;
		unsigned five : 1;
		unsigned four : 1;
		unsigned three : 1;
		unsigned two : 1;
		unsigned one : 1;
	};
	union bits
	{
		char *ch;
		data *status;
	} info;
	union int_data
	{
		int *x;
		char *x_byte[4];
	} int_data;
public:
	byte(int &x);
	void display();
	void set_bits(int n);
};