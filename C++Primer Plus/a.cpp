/*
* @Author: ACacti
* @Date:   2022-04-15 20:54:43
* @Last Modified by:   shang
* @Last Modified time: 2022-04-15 22:43:51
*/
#include <iostream>
using namespace std;
class Base{
public:
    int a = 1;
    static int count;
    Base(){count++;};
    Base(int a){
        this-> a = a;
        count++;
    }
    ~Base(){cout << this << ": Destructed" << endl;}
};

class Derived: public Base{
};

int main()
{
    Base b1;
    cout << "b1: " << &b1 << endl;
    b1 = 10;
    cout << b1.a << endl;
    // cout << Base::count <<endl;
    return 0;
}
int Base::count = 0;