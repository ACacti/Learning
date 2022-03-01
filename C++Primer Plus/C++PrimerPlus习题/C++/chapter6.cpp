#include <iostream>
#include <fstream>
#include <cctype>
#include <array>

using namespace std;
void  question6_1()
{
    char ch;
    char arr[100];
    int cnt = 0;
    while ((ch = cin.get()) != '@')
    {
        arr[cnt++] = ch;
    }
    for (int i = 0; i < cnt; i++)
    {
        if (isupper(arr[i])) {
            arr[i] = tolower(arr[i]);
        }
        if (islower(arr[i])) {
            arr[i] = toupper(arr[i]);
        }
        cout << arr[i];
    }
    cout << endl;
}

void question6_2() {
    array<double, 10> arr;
    int cnt = 0;
    double sum = 0;
    while (cin >> arr[cnt++]) {
        sum += arr[cnt - 1];
    }
    cnt--;
    if (cin.eof()) {
        cout << "EOF" << endl;
    }
    else if (cin.fail())
    {
        cout << "类型不匹配，结束输入" << endl;
    }
    cin.clear();
    int num = 0;
    if (cnt != 0)
    {
        sum /= cnt;
    }
    for (int i = 0; i < cnt; i++) {
        if (arr.at(i) > sum)
        {
            num++;
        }
    }
    cout << "AVE: " << sum << endl;
    cout << "NUM: " << num << endl;
    cout << "CNT: " << cnt << endl;
    return;
}
void question6_8()
{
    ofstream file;
    file.open("a.txt");
    cout << "Enter the content of file.\n";
    char buff[100];
    while (cin.getline(buff, 100))
    {
        file << buff << endl;
    }
    file.close();
    ifstream input;
    input.open("a.txt");
    int cnt = 0;
    while (input.get(buff[0]))
    {
        if (buff[0] == 'q')
        {
            break;
        }
        cnt++;
    }
    cout << cnt << endl;
}