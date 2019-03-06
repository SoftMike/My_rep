#include "pch.h"
#include <iostream>
#include "frac.h"

fraction::fraction(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
void fraction::display()
	{
		std::cout << a << "/" << b << std::endl;
	}
fraction fraction::operator*(fraction val)
	{
		this->a = val.a * this->a;
		this->b = val.b * this->b;
		return *this;
	}
fraction fraction::operator/(fraction val)
	{
		this->a = this->a * val.b;
		this->b = this->b * val.a;
		return *this;
	}
fraction fraction::operator+(fraction val)
	{
		fraction c;
		c.a = this->a * val.b;
		c.b = this->b * val.b;
		val.a = val.a * this->b;
		val.b = val.b * this->b;
		this->a = c.a + val.a;
		this->b = c.b;
		return *this;
	}
fraction fraction::operator-(fraction val)
	{
		fraction c;
		c.a = this->a * val.b;
		c.b = this->b * val.b;
		val.a = val.a * this->b;
		val.b = val.b * this->b;
		this->a = c.a - val.a;
		this->b = c.b;
		return *this;
	}
fraction fraction::operator=(fraction val)
	{
		this->a = val.a;
		this->b = val.b;
		return *this;
	}
double fraction::doub()
	{
		double a = this->a;
		double b = this->b;
		double c = a / b;
		return c;
	}
