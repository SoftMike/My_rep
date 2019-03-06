#pragma once

class fraction
{
	int a;
	int b;
public:
	fraction(int a = 1, int b = 1);
	void display();
	fraction operator*(fraction val);
	fraction operator/(fraction val);
	fraction operator+(fraction val);
	fraction operator-(fraction val);
	fraction operator=(fraction val);
	double doub();
};