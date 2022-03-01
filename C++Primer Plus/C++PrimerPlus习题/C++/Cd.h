//question13_1
#ifndef CD_H
#define CD_H
class Cd {
private:
	char performers[50];
	char label[20];
	int selections;
	double playtime;
	void initialize(const char* p, const char* l, const int s, const double pt);
public:
	Cd(const char* sl, const char* s2, const int n, const double x);
	Cd(const Cd& d);
	virtual ~Cd();
	virtual void Report()const;
	virtual Cd& operator=(const Cd& d);
};
#endif