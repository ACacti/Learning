/*
* @Author: ACacti
* @Date:   2022-04-14 21:29:49
* @Last Modified by:   shang
* @Last Modified time: 2022-04-14 22:46:55
*/
#ifndef COW_H
#define COW_H
#include <iostream>
#include <cstring>
class Cow{
    char name[20];
    char *hobby;
    double weight;
    void init(const char *nm, const char *ho, double wt);
public:
    Cow();
    Cow(const char *nm, const char *ho, double wt);
    Cow(const Cow &c);
    ~Cow();
    Cow & operator=(const Cow &c);
    void ShowCow() const;
};

#endif