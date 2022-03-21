//question13_1
#ifndef CLASSIC_H
#define CLASSIC_H
#include "Cd.h"
#include <cstring>
class Classic : public Cd {
private:
	char* primaryName;
public:
	Classic(const char* pn, const char* pf, const char* l, const int s, const double p) :
		Cd(pf, l, s, p)
	{
		primaryName = new char[strlen(pn) + 1];
		strcpy_s(primaryName, strlen(pn) + 1, pn);
	}
	Classic(const Classic& c) : Cd(c) {
		primaryName = new char[strlen(c.primaryName) + 1];
		strcpy_s(primaryName, strlen(c.primaryName) + 1, c.primaryName);
	}
	Classic& operator=(const Classic& c);
	virtual void Report() const;
	~Classic() { delete[]primaryName; }

};
#endif

