#include "Classic.h"
#include <iostream>
Classic& Classic::operator=(const Classic& c) {
	if (&c == this) {
		return *this;
	}
	Cd::operator=(c);
	delete[] primaryName;
	primaryName = new char[strlen(c.primaryName) + 1];
	strcpy_s(primaryName, strlen(c.primaryName) + 1, c.primaryName);

}

void Classic::Report()const {
	using std::cout;
	using std::endl;
	cout << "PrimaryName:" << primaryName << endl;
	Cd::Report();
}