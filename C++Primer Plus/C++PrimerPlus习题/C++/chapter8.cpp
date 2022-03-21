#include <iostream>
#include <cstring>
#include <cctype>
#include <string>

using namespace std;

void question8_1(const char* str, int num = 1)
{
	if (num == 0) return;
	cout << str << endl;
	question8_1(str, num - 1);
}

struct CandyBar {
	string name;
	double weight;
	int calory;
};
void question8_2(CandyBar& candy, const string name, const double weight, const int calory)
{
	candy.calory = calory;
	candy.name = name;
	candy.weight = weight;
}

void question8_3(string& str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ') {
			continue;
		}
		str[i] = toupper(str[i]);
	}
}


struct stringy {
	char* str;
	int ct;
};
void question8_4_show(const char* p, int num = 1)
{
	while (num--)
	{
		cout << p << endl;
	}
}
void question8_4_show(const stringy stry, int num = 1)
{
	while (num--)
	{
		cout << stry.str << endl;
	}
}
void question8_4_set(stringy& stry, const char* arr)
{
	stry.ct = strlen(arr);
	stry.str = new char[sizeof(arr) + 1];
	strcpy_s(stry.str, stry.ct + 1, arr);

}
void question8_4_test()
{
	stringy beany;
	char testing[] = "Reality isn't what is used to be.";
	question8_4_set(beany, testing);
	question8_4_show(beany);
	question8_4_show(beany, 4);
	testing[0] = 'p';
	testing[1] = 'u';
	question8_4_show(testing, 3);
	question8_4_show(testing);
	question8_4_show("Done!");
	return;
}

// question 8-5
template <typename T>
T question8_5(const T a[])
{
	T max = a[0];
	for (int i = 1; i < 5; i++)
	{
		if (a[i] > max) max = a[i];
	}
	return max;
}

//question 8-6
template <typename T>
T question8_6(T t[], int num) {
	T max = t[0];
	for (int i = 0; i < num; i++)
	{
		if (max < t[i]) {
			max = t[i];
		}
	}
	return max;
}

template<> char* question8_6(char** p, int num) {
	int max_len = strlen(p[0]);
	char* q = p[0];
	for (int i = 1; i < num; i++) {
		if (max_len < strlen(p[i])) {
			max_len = strlen(p[i]);
			q = p[i];
		}
	}
	return q;
}
void question8_6_test() {
	char** p = (char**) new char* [5];
	for (int i = 0; i < 5; i++) {
		p[i] = new char[10];
		cin >> p[i];
	}
	cout << question8_6(p, 5) << endl;
}