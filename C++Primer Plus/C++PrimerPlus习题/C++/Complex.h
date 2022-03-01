#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
class Complex {
private:
	double real;
	double imagine;
public:
	//���� �����㷨������ƹ㣬ֻҪ����double -> Complex�Ĺ��캯��������Ԫʵ��ComplexΪ������+ - *���������
	//���൱����� double operator Complex ��Complex operator double
	//�˴���operatorָ + - *����
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
