/*
* @Author: ACacti
* @Date:   2022-04-16 14:50:43
* @Last Modified by:   shang
* @Last Modified time: 2022-04-16 15:51:59
*/
#include "Classic.h"
#include <iostream>
#include <cstring>
//调用该函数前请确认成员指针已被初始化
void Classic::init(const char *pn){
    if(primaryName != NULL){
        delete[] primaryName;
    }
    primaryName = new char[strlen(pn) + 1];
    strcpy(primaryName, pn);
}

Classic::Classic(const char *pn, const char *pf,
    const char * lb, const int st, const double pt): Cd(pf, lb, st, pt){
    primaryName = NULL;
    init(pn);
}

Classic::Classic(const Classic &c): Cd(c){
    primaryName = NULL;
    init(c.primaryName);
}

Classic::~Classic(){
    std::cout << "Classic: " << this << " Destructed!" << std::endl;
    if(primaryName != NULL){
        delete[] primaryName;
    }
}


Classic& Classic:: operator=(const Classic& c){
    if(this == &c){
        return *this;
    }

    Cd::operator=(c);
    init(c.primaryName);
    return *this;
}

void Classic::Report()const{
    std::cout << "primaryName: " << primaryName << std::endl;
    Cd::Report();
}