/*
* @Author: ACacti
* @Date:   2022-04-15 20:54:43
* @Last Modified by:   shang
* @Last Modified time: 2022-04-17 16:51:22
*/
#include <iostream>
using namespace std;
class Base{
    public:
    void foo(){cout << "Foo in base" << endl;}

};

class Derived : public Base{
public:
    void foo(){cout << "Foo in Derived" << endl;}

};

int main()
{
    enum Color{BLUE, RED, BLACK};
    enum Human{YELLOW};
    int flag = BLUE;
    cout << (flag == YELLOW) << endl;

    return 0;
}