class string
{
	char *s;
public:
	string();
	~string();
	string(const string &obj);

	string operator=(string obj);
	string operator=(const char *mass);
	string operator+(string obj);
	string operator+=(string obj);
	string operator+=(const char *mass);
	string operator-=(const char *mass);
	char &operator[](int i);

	void add(const char *mass);
	void display();
	void new_string();
	void clean();
	void delete_string();
	void current_string();
};