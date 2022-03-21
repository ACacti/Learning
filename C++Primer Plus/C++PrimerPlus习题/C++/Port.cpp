#include "Port.h"

void Port::initialize(const char* br, const char* st,const int bt)
{
	brand = new char[strlen(br) + 1];
	strcpy_s(brand, strlen(br) + 1, br);
	strcpy_s(style, st);
	bottles = bt;
}

Port::Port(const char* br, const char* st, int b)
{
	initialize(br, st, b);
}

Port::Port(const Port& p)
{
	initialize(p.brand, p.style, p.bottles);
}

Port& Port::operator=(const Port& p)
{
	if (this == &p) {
		return *this;
	}
	delete[] brand;
	initialize(p.brand, p.style, p.bottles);
}
		
Port& Port::operator+=(int b)
{
	bottles += b;
	return *this;
}

Port& Port::operator-=(int b)
{
	bottles -= b;
	bottles = (bottles > 0 ? bottles : 0);
	return *this;
}

void Port::Show() const
{
	using std::cout;
	using std::endl;
	cout << "Brand: " << brand << endl;
	cout << "Kind: " << style << endl;
	cout << "Bottles: " << bottles << endl;
	cout << endl;
}

ostream& operator<<(ostream& os, const Port& p)
{
	os << p.brand << ", " << p.style << ", " << p.bottles << endl;
	return os;
}
