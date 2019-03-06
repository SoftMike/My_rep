#include "stdafx.h"
#include <iostream>
#include "val.h"

value::value(int a, int b)
	{
		this->a = a;
		this->b = b;
		this->i = 'i';
		fraction = false;
		c = d = e = f = 0;
	}
void value::display()
	{
		if (!fraction)
		{
			std::cout << a;
			if (b < 0)
				std::cout << b << i;
			if (b > 0)
				std::cout << "+" << b << i;
		}
		else
		{
			std::cout << c;
			if (d < 0)
				std::cout << d << i;
			if (d > 0)
				std::cout << "+" << d << i;
			std::cout << " / ";
			std::cout << e;
			if (f < 0)
				std::cout << f << i;
			if (f > 0)
				std::cout << "+" << f << i;
		}
	}
value value::operator=(value val)
	{
		if (!val.fraction)
		{
			this->a = val.a;
			this->b = val.b;
		}
		else
		{
			this->a = val.a;
			this->b = val.b;
			this->c = val.c;
			this->d = val.d;
			this->e = val.e;
			this->f = val.f;
			this->fraction = true;
		}
		return *this;
	}
value value::operator+(value b)
	{
		value temp;
		temp.a = this->a + b.a;
		temp.b = this->b + b.b;
		return temp;
	}
value value::operator-(value b)
	{
		value temp;
		temp.a = this->a - b.a;
		temp.b = this->b - b.b;
		return temp;
	}
value value::operator*(value b)
	{
		value temp;
		temp.a = this->a * b.a + this->b * b.b * (-1);
		temp.b = this->b * b.a + this->a * b.b;
		return temp;
	}
value value::operator/(value val)
	{
		value a, b;
		value factor(val.a, (val.b * (-1)));
		a = *this * factor;
		b = val * factor;
		this->fraction = true;
		this->c = a.a;
		this->d = a.b;
		this->e = b.a;
		this->f = b.b;
		return *this;
	}
