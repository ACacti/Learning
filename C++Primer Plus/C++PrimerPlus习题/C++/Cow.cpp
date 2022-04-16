/*
* @Author: ACacti
* @Date:   2022-04-14 21:33:23
* @Last Modified by:   shang
* @Last Modified time: 2022-04-14 23:16:21
*/
#include "Cow.h"

using std::cout;
using std::endl;

//这个函数仅在类构造函数初始化场景下使用，所以不会判断成员指针是否需要
//释放、成员指针是否为空
void Cow::init(const char  *nm, const char* ho, double wt)
{
    strcpy(name, nm);
    hobby = new char[strlen(ho) + 1];
    strcpy(hobby, ho);
    weight = wt;
}

Cow::Cow():weight(0){
    hobby = new char[1];
    hobby[0] = '\0';
    name[0] = '\0';
}
Cow::Cow(const char *nm, const char *ho, double wt){
    init(nm, ho, wt);
}
Cow::Cow(const Cow& c)
{
    if(this == &c){
        return;
    }
    init(c.name, c.hobby, c.weight);
}

Cow& Cow::operator=(const Cow &c){
    cout << "operator=" << endl;
    if(this == &c){
        return *this;
    }

    if(hobby != NULL){
        delete[] hobby;
    }
    init(c.name, c.hobby, c.weight);
    return *this;
}

Cow::~Cow(){
    if(hobby != NULL)
        delete[] hobby;
    cout << "CowClass: " << this << " deleted!" << endl;
}

void Cow::ShowCow()const{

    cout << "CowClass: " << this << endl;
    cout << "name: " << name << endl;
    cout << "hobby: " << hobby<< endl;
    cout << "weight: " << weight << endl;
}
