/*
* @Author: ACacti
* @Date:   2022-04-14 22:11:42
* @Last Modified by:   shang
* @Last Modified time: 2022-04-15 15:22:55
*/
#include <iostream>
#include "Cow.h"
#include "Stack.h"
using namespace std;
void chapter12_1() {
    Cow c1;
    c1.ShowCow();
    Cow c2 = Cow("Cow2", "PlayingGame", 100);
    c2.ShowCow();
    c1 = c2;
    c1.ShowCow();
    Cow c3 = c1;
    c3.ShowCow();
    return;
}

void chapter12_4()
{
    Stack s1;

    int t = 0;
    while(!s1.isfull()){
        s1.push(t++);
    }

    Stack s2 = s1;
    Item t2 = 9999;
    while(!s2.isempty()){
        if(s2.pop(t2)){
            cout << t2 << endl;
        }
    }

    Stack s3;
    s3 = s2;

    cout << "s3 isfull():" << s3.isfull() << endl;
    cout << "s3 is isempty(): " << s3.isempty() << endl;

}


int main()
{
    chapter12_4();
    return 0;
}