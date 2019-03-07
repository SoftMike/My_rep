#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include "file.h"

void string::set_s()
	{
		std::cout << "Enter text:\n\n";
		std::getline(std::cin, s);
	}
std::string string::get_s()
	{
		return s;
	}
void file::write()
	{
		set_s();
		std::ofstream file;
		file.open(filename, std::ofstream::app);
		if (!file.is_open())
			std::cout << "\nFile error!\n\n";
		else
		{
			file << get_s();
		}
		file.close();

	}
void file::read()
	{
		std::ifstream file;
		file.open(filename);
		if (!file.is_open())
			std::cout << "\nFile error!\n\n";
		else
		{
			char ch;
			while (file.get(ch))
				std::cout << ch;
		}
		file.close();
	}
void console::write()
	{
		set_s();
		std::cout << get_s();
	}
void print::fileprint()
	{
		file::write();
	}
void print::fileread()
	{
		file::read();
	}
void print::consoleprint()
	{
		console::write();
	}
void print::deletefile()
	{
		std::string clear_comand = "DEL | ERASE  my_file.txt clear.bat";
		std::ofstream clear;
		clear.open("clear.bat");
		if (!clear.is_open())
			std::cout << "Ошибка удаления!" << std::endl;
		else
		{
			clear << clear_comand;
		}
		clear.close();
		system("clear.bat");
	}