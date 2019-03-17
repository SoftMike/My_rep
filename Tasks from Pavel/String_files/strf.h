#pragma once
#include "fstream"

class stringfile
{
	std::ofstream file;
public:
	stringfile();
	void display_string();
	void display_all();
	void setup();
};