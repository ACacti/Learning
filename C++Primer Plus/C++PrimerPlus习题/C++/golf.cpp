#include "golf.h"
#include <string.h>
#include <iostream>
void setgolf(golf& g, const char* name, int hc)
{
	strcpy_s(g.fullname, name);
	g.handicap = hc;
}

int setgolf(golf& g) {
	std::cout << "ÊäÈë£º" << std::endl;
	std::cin >> g.fullname;
	std::cin >> g.handicap;
	if (strlen(g.fullname) == 0) {
		return 0;
	}
	return 1;
}
void handicap(golf& g, int hc) {
	g.handicap = hc;
}
void showgolf(const golf& g) {
	std::cout << "FullName:" << g.fullname << std::endl;
	std::cout << "Handicap:" << g.handicap << std::endl;
}
