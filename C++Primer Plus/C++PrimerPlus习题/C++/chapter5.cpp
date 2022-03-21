#include <iostream>
#include <string>
#include <cstring>
#include <array>
#include <fstream>

using namespace std;
void question5_1()
{
    int a, b;
    cin >> a >> b;
    int sum = 0;
    for (int i = a; i <= b; i++) {
        sum += i;
    }
    cout << "res: " << sum << endl;
    return;
}
void question5_2()
{
    const int Arsize = 16;
    array<long long, Arsize> arr;
    arr.at(0) = arr.at(1) = 1LL;
    for (int i = 2; i < Arsize; i++) {
        arr.at(i) = arr.at(i - 1) * i;
    }
    for (int i = 0; i < Arsize; i++) {
        cout << i << "! = " << arr[i] << endl;
    }
    return;
}
void question5_3()
{
    long long sum = 0;
    int t;
    while (cin >> t) {
        if (t == 0) {
            break;
        }
        sum += t;
        cout << "sum: " << sum << endl;
    }
    return;
}
void question5_4()
{
    double daphne = 100.0, cleo = 100.0;
    int i = 0;
    double t = daphne;
    double a = cleo - daphne;
    while ((cleo - daphne) < 0.001)
    {
        daphne += t * 0.1;
        cleo += cleo * 0.05;
        i++;
    }
    cout << i << "年后，Daphne 资产：" << daphne << " , " << "Cleo资产：" << cleo << endl;
    return;
}
void question5_8()
{
    cout << "Enter words (to stop, type the word done): ";
    char words[100][10];
    int i = 0;
    do {
        cin >> words[i];
        i++;
    } while (strcmp(words[i - 1], "done") != 0);
    cout << "You entered a total of " << i << " words." << endl;
    return;
}