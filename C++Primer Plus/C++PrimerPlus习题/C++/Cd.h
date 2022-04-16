/*
* @Author: ACacti
* @Date:   2022-04-16 13:57:06
* @Last Modified by:   shang
* @Last Modified time: 2022-04-16 15:43:02
*/
#ifndef CD_H
#define CD_H
class Cd{
private:
    char *performers;
    char *label;
    int selections;
    double playtime;
    void init(const char *pf, const char *lb, const int st, const double pt);
public:
    Cd(const char *s1, const char *s2, const int n, const double pt);
    Cd(const Cd &d);
    Cd();
    virtual ~Cd();
    virtual void Report()const;
    virtual Cd &operator=(const Cd& d);
};

#endif