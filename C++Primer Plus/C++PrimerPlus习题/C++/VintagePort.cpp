#include "VintagePort.h"

VintagePort::VintagePort():Port()
{
	nickname = new char[5];
	strcpy_s(nickname, 5, "none");
	year = -1;
}

VintagePort::VintagePort(const char* br, int b, const char* nn, int y):
	Port(br, R"(vintage)", b)
{

	nickname = new char[strlen(nn) + 1];
	strcpy_s(nickname, strlen(nn) + 1, nn);
	year = y;
}

VintagePort::VintagePort(const VintagePort& vp):
	Port(vp)
{

	nickname = new char[strlen(vp.nickname) + 1];
	strcpy_s(nickname, strlen(vp.nickname) + 1, vp.nickname);
	year = vp.year;
}

VintagePort& VintagePort::operator=(const VintagePort& vp)
{
	if (this == &vp) {
		return *this;
	}
	Port::operator=(vp);
	nickname = new char[strlen(vp.nickname) + 1];
	strcpy_s(nickname, strlen(vp.nickname) + 1, vp.nickname);
	year = vp.year;
	return *this;
}

void VintagePort::Show() const
{
	using std::cout;
	using std::endl;
	cout << "Nickname: " << nickname << endl;
	cout << "year: " << year << endl;
	Port::Show();
}

ostream& operator<<(ostream& os, const VintagePort& vp)
{
	os << vp.nickname << "(" << vp.year << "): ";
	os << Port(vp);//调用基类的 << 运算符函数
	return os;
}
