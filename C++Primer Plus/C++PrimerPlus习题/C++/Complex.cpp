#include <iostream>
#include "Complex.h"

using namespace std;
Complex::Complex(const double real, const double imagine) {
	this->real = real;
	this->imagine = imagine;
}
Complex operator+(const Complex& c1, const Complex& c2)
{
	return Complex(c1.real + c2.real, c1.imagine + c2.imagine);
}

Complex operator-(const Complex& c1, const Complex& c2)
{
	return Complex(c1.real - c2.real, c1.imagine - c2.imagine);
}
Complex operator*(const Complex& c1, const Complex& c2) {
	return Complex(c1.real * c2.real - c1.imagine * c2.imagine, c1.real * c2.imagine + c1.imagine * c2.real);
}

Complex operator~(const Complex& c)
{
	return Complex(c.real, -c.imagine);
}
istream& operator>>(istream& is, Complex& c) {
	cout << "real: ";
	is >> c.real;
	cout << "imagine:";
	is >> c.imagine;
	return is;
}
ostream& operator<<(ostream& os, const Complex& c) {
	os << "{" << c.real << "," << c.imagine << "}";
	return os;
}