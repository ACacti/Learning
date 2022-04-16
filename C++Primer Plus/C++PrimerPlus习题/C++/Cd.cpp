/*
* @Author: ACacti
* @Date:   2022-04-16 14:08:17
* @Last Modified by:   shang
* @Last Modified time: 2022-04-16 15:48:18
*/

#include "Cd.h"
#include <cstring>
#include <iostream>
//调用此函数请确认成员指针已经初始化
void Cd::init(const char *pf, const char *lb, const int st, const double pt){
    if(performers != NULL) delete[] performers;
    if(label != NULL) delete[] label;

    performers = new char[strlen(pf) + 1];
    label = new char[strlen(lb) + 1];
    strcpy(performers, pf);
    strcpy(label, lb);
    selections = st;
    playtime = pt;
}

Cd::Cd(const char *s1, const char *s2, const int n, const double pt){
    performers = label = NULL;
    init(s1, s2, n, pt);
}

Cd::Cd(const Cd &cd){
    performers = label = NULL;
    init(cd.performers, cd.label, cd.selections, cd.playtime);
}


 void Cd::Report()const{
    using std::cout;
    using std::endl;
    cout << "performers: " << performers << endl;
    cout << "label: " << label << endl;
    cout << "selections: " << selections << endl;
    cout << "playtime: " << playtime << endl;
}
Cd& Cd::operator=(const Cd& cd){
    if(this == &cd){
        return *this;
    }
    init(cd.performers, cd.label, cd.selections, cd.playtime);
    return *this;
}
Cd::~Cd(){
    std::cout << "Cd: " << this << " Destructed!" << std::endl;
}