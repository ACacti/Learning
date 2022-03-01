#include <iostream>

using namespace std;
void question1(string name, string address)
{
    cout << "我名字叫:" << name << endl;
    cout << "我住在" << address << endl;
    return;
}

void question2()
{
    double input;
    cin >> input;
    cout << input / 220 << endl;
}
void question4()
{
    cout << "Enter your age:";
    int age;
    cin >> age;
    cout << "Your age contain the number of monthes:" << age * 12 << endl;
}
