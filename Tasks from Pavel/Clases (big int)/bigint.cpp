#include "pch.h"
#include "bigint.h"
#include <iostream>

bigint::bigint(int n)
	{
		if (!n)
		{
			s = new char;
			s[0] = '\0';
		}
		else
			s = new char[n];
	}
bigint::~bigint()
	{
		if (s)
			delete[] s;
	}
bigint::bigint(const bigint &obj)
	{
		s = new char[(strlen(obj.s)) + 1];
		int i = 0;
		while (obj.s[i])
		{
			s[i] = obj.s[i];
			i++;
		}
		s[i] = '\0';
	}


bigint bigint::operator=(bigint obj)
	{
		if (strlen(s) < strlen(obj.s))
		{
			delete[] s;
			s = new char[strlen(obj.s) + 1];
		}

		int i = 0;
		while (obj.s[i])
		{
			s[i] = obj.s[i];
			i++;
		}

		s[i] = '\0';

		return *this;
	}
bigint bigint::operator=(const char *mass)
	{
		if (strlen(s) < strlen(mass))
		{
			delete[] s;
			s = new char[strlen(mass) + 1];
		}

		int i = 0;
		while (mass[i])
		{
			s[i] = mass[i];
			i++;
		}

		s[i] = '\0';

		return *this;
	}

bigint bigint::operator+(bigint val)
	{
		int start = (strlen(s) + strlen(val.s)) * 2;
		bigint up(start), down(start);
		int size = 0;
		if (strlen(s) > strlen(val.s))
		{
			size = strlen(s);
			up = s;
			down = val.s;
		}
		else
		{
			size = strlen(val.s);
			up = val.s;
			down = s;
		}
		bigint temp(size * 2);
		int a = 0;
		int b = 0;
		int c = 0;
		int t = 0;
		up.reverse();
		down.reverse();
		int n = 0;
		while (down.s[n])
		{
			a = (int)up.s[n] - 48;
			b = (int)down.s[n] - 48;
			c = a + b;

			if (c < 10)
				temp.s[n] = c + 48;
			else
			{
				temp.s[n] = c % 10 + 48;
				if (up.s[n + 1] != '9')
					up.s[n + 1]++;
				else
				{
					t = n + 1;
					while (up.s[t] == '9' && up.s[t])
					{
						up.s[t] = '0';
						t++;
					}
					up.s[t++] = '1';
					up.s[t] = '\0';
				}
			}
			n++;
		}
		while (up.s[n])
		{
			temp.s[n] = up.s[n];
			n++;
		}
		temp.s[n] = '\0';
		temp.reverse();
		return temp;
	}
bigint bigint::operator+(int valint)
	{
		bigint val(999999999);
		snprintf(val.s, 999999999, "%d", valint);
		int start = (strlen(s) + strlen(val.s)) * 2;
		bigint up(start), down(start);
		int size = 0;
		if (strlen(s) > strlen(val.s))
		{
			size = strlen(s);
			up = s;
			down = val.s;
		}
		else
		{
			size = strlen(val.s);
			up = val.s;
			down = s;
		}
		bigint temp(size * 2);
		int a = 0;
		int b = 0;
		int c = 0;
		int t = 0;
		up.reverse();
		down.reverse();
		int n = 0;
		while (down.s[n])
		{
			a = (int)up.s[n] - 48;
			b = (int)down.s[n] - 48;
			c = a + b;

			if (c < 10)
				temp.s[n] = c + 48;
			else
			{
				temp.s[n] = c % 10 + 48;
				if (up.s[n + 1] != '9')
					up.s[n + 1]++;
				else
				{
					t = n + 1;
					while (up.s[t] == '9' && up.s[t])
					{
						up.s[t] = '0';
						t++;
					}
					up.s[t++] = '1';
					up.s[t] = '\0';
				}
			}
			n++;
		}
		while (up.s[n])
		{
			temp.s[n] = up.s[n];
			n++;
		}
		temp.s[n] = '\0';
		temp.reverse();
		return temp;
	}
bigint operator+(int valint, bigint val)
	{
		bigint thiss(999999999);
		snprintf(thiss.s, 999999999, "%d", valint);
		int start = (strlen(thiss.s) + strlen(val.s)) * 2;
		bigint up(start), down(start);
		int size = 0;
		if (strlen(thiss.s) > strlen(val.s))
		{
			size = strlen(thiss.s);
			up = thiss.s;
			down = val.s;
		}
		else
		{
			size = strlen(val.s);
			up = val.s;
			down = thiss.s;
		}
		bigint temp(size * 2);
		int a = 0;
		int b = 0;
		int c = 0;
		int t = 0;
		up.reverse();
		down.reverse();
		int n = 0;
		while (down.s[n])
		{
			a = (int)up.s[n] - 48;
			b = (int)down.s[n] - 48;
			c = a + b;

			if (c < 10)
				temp.s[n] = c + 48;
			else
			{
				temp.s[n] = c % 10 + 48;
				if (up.s[n + 1] != '9')
					up.s[n + 1]++;
				else
				{
					t = n + 1;
					while (up.s[t] == '9' && up.s[t])
					{
						up.s[t] = '0';
						t++;
					}
					up.s[t++] = '1';
					up.s[t] = '\0';
				}
			}
			n++;
		}
		while (up.s[n])
		{
			temp.s[n] = up.s[n];
			n++;
		}
		temp.s[n] = '\0';
		temp.reverse();
		return temp;
	}

void bigint::set()
	{
		int n = strlen(s);
		char value[100];
		gets_s(value);

		n = 0;
		while (value[n])
		{
			s[n] = value[n];
			n++;
		}
		s[strlen(value)] = '\0';
	}
void bigint::display()
	{
		std::cout << s << std::endl;
	}
void bigint::reverse()
	{
		int n = strlen(s);
		while (n)
		{
			for (int k = 1; k < n; k++)
				std::swap(s[k], s[k - 1]);
			n--;
		}
	}
