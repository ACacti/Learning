#ifndef PORT_H
#define PROT_H
#include <iostream>
using namespace std;
class Port
{
private:
	char* brand;
	char style[20];
	int bottles;
	void initialize(const char* br, const char* st, const int bt);
public:
	Port(const char* br = "none", const char* st = "none", int b = 0);
	Port(const Port& p);
	virtual ~Port() { delete[]brand; }
	Port& operator=(const Port& p);
	Port& operator+=(int b);
	Port& operator-=(int b);
	int BottleCount() const { return bottles;}
	virtual void Show()const;
	friend ostream& operator <<(ostream& os, const Port& p);
};
#endif
