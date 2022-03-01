#include "string2.h"
#include <cstring>
#include <cctype>
using std::cin;
using std::cout;

int String::num_strings = 0;//将String类中的num_strings初始化

int String::HowMany()
{
	return num_strings;
}

String::String(const char* s) {
	len = std::strlen(s);
	str = new char[len + 1];
	strcpy_s(str,len + 1, s);
	num_strings++;
}

String::String() {
	len = 0;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}
//复制构造函数
String::String(const String& st) {
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str,len + 1, st.str);
}

String::~String()
{
	--num_strings;
	delete[]str;
}

String& String::operator=(const String& st) {
	if (this == &st) {
		return *this;
	}
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str,len + 1, st.str);
	return *this;
}

String& String::operator=(const char* s) {
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	strcpy_s(str,len + 1, s);
	return *this;
}


char& String::operator[](int i)
{
	return str[i];
}

const char& String::operator[](int i)const {
	return str[i];
}

bool operator<(const String& st1, const String& st2) {
	return (std::strcmp(st1.str, st2.str));
}

bool operator>(const String& st1, const String& st2) {
	return st2 < st1;
}

bool operator==(const String& st1, const String& st2) {
	return (std::strcmp(st1.str, st2.str) == 0);
}

ostream& operator<<(ostream& os, const String& st) {
	os << st.str;
	return os;
}

//读入80个字符，剩余的丢弃
istream& operator>>(istream& is, String& st) {
	char temp[String::CINLIM];
	is.get(temp,String::CINLIM);
	if (is) {
		st = temp;
	}
	while (is && is.get() != '\n')
	{
		continue;
	}
	return is;
}
void String::Stringlow() {
	for (int i = 0; i < len; i++) {
		str[i] = std::tolower(str[i]);
	}
}
void String::Stringup() {
	for (int i = 0; i < len; i++) {
		str[i] = std::toupper(str[i]);
	}
}

int String::countChar(const char ch)const {
	int res = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == ch) {
			res++;
		}
	}
	return res;
}

String operator+(const String& st1, const String& st2) {
	String res;
	res.len = st1.length()+ st2.length();
	res.str = new char[res.len + 1];
	res.str[0] = '\0';
	strcat_s(res.str,res.len + 1, st1.str);
	strcat_s(res.str, res.len + 1, st2.str);
	return res;
}