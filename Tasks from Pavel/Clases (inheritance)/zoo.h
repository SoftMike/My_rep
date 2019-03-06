#pragma once
#include <string>

class base
{
	std::string name;
	std::string voice;
protected:
	bool included;
	void set_name_voise(std::string name, std::string voice);
	void get_voice();
	void return_name();
};

class cow : public base
{
protected:
	cow();
};
class dog : public base
{
protected:
	dog();
};
class cock : public base
{
protected:
	cock();
};
class horse : public base
{
protected:
	horse();
};

class zoo : public cow, dog, cock, horse
{
public:
	void voice();
	void add();
	void remove();
	void display_zoo();
	void setup();
};