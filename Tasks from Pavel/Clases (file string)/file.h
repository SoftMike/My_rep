#pragma once
#include <string>
#define filename "my_file.txt"

class string
{
	std::string s;
protected:
	void set_s();
	std::string get_s();
};
class file : private string
{
protected:
	void write();
	void read();
};
class console : private string
{
protected:
	void write();
};
class print : public file, console
{
public:
	void fileprint();
	void fileread();
	void consoleprint();
	void deletefile();
};