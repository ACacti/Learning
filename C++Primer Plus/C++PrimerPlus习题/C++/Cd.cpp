#include "Cd.h"
#include <cstring>
#include <iostream>
void Cd::initialize(const char* p, const char* l, const int s, const double pt) {
	strcpy_s(performers, p);
	strcpy_s(label, l);
	selections = s;
	playtime = pt;
}
Cd::Cd(const char* s1, const char* s2, const int n, const double x) {
	initialize(s1, s2, n, x);
}
Cd::Cd(const Cd& d) {
	initialize(d.performers, d.label, d.selections, d.playtime);
}

Cd::~Cd() {
}

Cd& Cd::operator=(const Cd& d) {
	if (&d == this) {
		return *this;
	}
	initialize(d.performers, d.label, d.selections, d.playtime);
	return *this;
}

void Cd::Report()const {
	using std::cout;
	using std::endl;
	cout << "Performers:" << performers << endl;
	cout << "Label:" << label << endl;
	cout << "Selections:" << selections << endl;
	cout << "Playtime:" << playtime << endl << endl;
}