#include <iostream>

using namespace std;

void question3_3()
{
    double degrees, minutes, seconds;
    cout << "Enter the degrees:";
    cin >> degrees;
    cout << "Enter the minutes of arc:";
    cin >> minutes;
    cout << "Enter the seconds of arc:";
    cin >> seconds;
    cout << degrees << "degrees, " << minutes << "minutes, " << seconds << "seconds = " << degrees + minutes / 60 + seconds / 3600;

}
void question3_4()
{
    long long seconds;
    int t = 60 * 60 * 24;
    cout << "Enter the number of seconds:";
    cin >> seconds;
    long long days, hours, minutes;
    days = seconds / t;
    seconds %= t;
    hours = seconds / 3600;
    seconds %= 3600;
    minutes = seconds / 60;
    seconds %= 60;
    cout << seconds << " seconds = " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds" << endl;
}
