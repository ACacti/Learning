#include <iostream>
#include <climits>


int demo()
{
    using namespace std;
    cout << "int is " << sizeof(int) << "bytes." << endl;
    cout << "short is " << sizeof(short) << "bytes." << endl;
    cout << "long is " << sizeof(long) << "bytes." << endl;
    cout << endl;

    cout << "Maxium values:" << endl;
    cout << "int: " << INT_MAX << endl;
    cout << "short: " << SHRT_MAX << endl;
    cout << "long: " << LONG_MAX << endl << endl;

    cout << "Minimum int value = " << INT_MIN << endl;
    cout << "Bits per byte = " << CHAR_BIT << endl;

    return 0;
}
