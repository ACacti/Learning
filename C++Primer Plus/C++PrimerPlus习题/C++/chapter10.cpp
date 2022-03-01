#include <iostream>
#include <cstring>
#include <cctype>
#include <string>

using namespace std;
// Question 10_2
class Person {
private:
	static const int LIMIT = 25;
	string lname;
	char fname[LIMIT];
public:
	Person() { lname = "", fname[0] = '\0'; }
	Person(const string& ln, const char* fn = "Heyyou");
	void show() const;
	void FormalShow() const;

};
Person::Person(const string& ln, const char* fn) {
	this->lname = ln;
	strcpy_s(this->fname, fn);
}
void Person::show() const {
	cout << "Name is: " << this->fname << " " << this->lname;
}

void Person::FormalShow() const
{
	cout << "Name is: " << this->lname << " " << this->fname;
}
void question10_2()
{
	Person one;
	Person two("Smythecraft");
	Person three("Dimwiddy", "Sam");
	one.show();
	cout << endl;
	one.FormalShow();
	cout << endl;
	three.show();
	cout << endl;
	three.FormalShow();
	cout << endl;
}

//Question10_5
struct customer {
	char fullname[35];
	double payment;
};
typedef customer Item;
class Stack {
private:
	enum { LIMIT = 40 };
	int top;
	int bottom;
	Item s_arr[LIMIT];
	double sum;
public:
	Stack() { top = 0; bottom = 0; sum = 0; }
	Stack(Item arr[], int n);
	bool push(const Item it);
	bool pop(Item&);
	bool isEmpty() const;
	bool isFull() const;
};

Stack::Stack(Item arr[], int n) {
	top = 0; bottom = 0; sum = 0;
	for (int i = 0; i < n && !isFull(); i++) {
		push(arr[i]);
	}
}
bool Stack::push(const Item it) {
	if (!isFull()) {
		s_arr[top++] = it;
		return true;
	}
	return false;
}
bool Stack::pop(Item& it) {
	if (isEmpty()) {
		return false;
	}
	it = s_arr[--top];
	sum += it.payment;
	cout << "Remove " << it.fullname << ", sum + " << it.payment << " = " << sum << endl;
	return true;
}
bool Stack::isFull() const {
	if (top >= LIMIT) {
		return true;
	}
	return false;
}
bool Stack::isEmpty()const {
	if (top == 0) {
		return true;
	}
	return false;
}
void question10_5() {
	Item itemArr[] = {
		{"Name1", 12},
		{"Name2", 34},
		{"Name3", 34},
		{"Name4", 23}
	};
	Stack s(itemArr, 4);
	s.push({ "Name5", 45 });
	Item t;
	while (!s.isEmpty()) {
		s.pop(t);
	}

}

//question10_7
class Plorg {
private:
	string name;
	int ci;
public:
	Plorg() { name = "Plorga", ci = 0; }
	Plorg(string name, int ci);
	void setCi(const int);
	void report() const;
};
Plorg::Plorg(string name, int ci) {
	this->name = name;
	this->ci = ci;
}
void Plorg::setCi(const int ci) {
	this->ci = ci;
}
void Plorg::report()const {
	cout << "Plorg Name is " << this->name + ", CI is " << this->ci;
}
void question10_7() {
	Plorg p1;
	Plorg p2("Name1", 250);
	p1.report(); cout << endl;
	p2.report(); cout << endl;
	p2.setCi(100);
	p2.report(); cout << endl;
}