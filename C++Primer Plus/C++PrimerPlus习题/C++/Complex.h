#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
class Complex {
private:
	double real;
	double imagine;
public:
	//复数 的运算法则可以推广，只要构造double -> Complex的构造函数，用友元实现Complex为参数的+ - *运算符重载
	//就相当完成了 double operator Complex 和Complex operator double
	//此处的operator指 + - *运算
	Complex() { real = 0; imagine = 0; }
	Complex(const double real, const double imagine = 0);
	friend Complex operator+(const Complex& c1, const Complex& c2);
	friend Complex operator-(const Complex& c1, const Complex& c2);
	friend Complex operator*(const Complex& c1, const Complex& c2);
	friend Complex operator~(const Complex& c);
	friend std::ostream& operator<<(std::ostream& os, const Complex& c);
	friend std::istream& operator>>(std::istream& is, Complex& c);
};

#endif //
