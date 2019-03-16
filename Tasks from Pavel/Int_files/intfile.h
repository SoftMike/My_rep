#pragma once
#include <fstream>
class files
{
	int number;
	int n;
	std::ofstream file;
public:
	files();

	void enter();
	void setup();
	void display();
};