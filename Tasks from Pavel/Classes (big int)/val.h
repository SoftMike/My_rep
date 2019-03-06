class value
{
	int a;
	int b;
	char i;
	bool fraction;
	int c, d, e, f;
public:
	value(int a = 0, int b = 0);
	void display();
	value operator=(value val);
	value operator+(value b);
	value operator-(value b);
	value operator*(value b);
	value operator/(value val);
};