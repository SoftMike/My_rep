#include "stdafx.h"
#include <iostream>
#include "val.h"

int main()
{
	value z(5, 2), k(2, -5), c;
	
	c = z + k;
	std::cout << "z + k:  ";
	c.display();
	std::cout << "\n";
	c = z - k;
	std::cout << "z - k:  ";
	c.display();
	std::cout << "\n";
	c = z * k;
	std::cout << "z * k:  ";
	c.display();
	std::cout << "\n";
	c = z / k;
	std::cout << "z / k:  ";
	c.display();
	std::cout << "\n";

    return 0;
}

