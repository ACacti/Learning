#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include "golf.h"//��question9_1��ʹ��
#include "q_9_4.h" // ��question9_4��ʹ��
using namespace std;

void chapter9_1() {
	golf ann;
	setgolf(ann, "Ann Birdfree", 24);
	showgolf(ann);
	setgolf(ann);
	handicap(ann, 20);
	showgolf(ann);
}
void question_9_3() {
	struct chaff {
		char dross[20];
		int slag;
	};
	chaff* buff1 = new chaff[2];
	chaff* chaff1 = new(buff1) chaff;
	strcpy_s(chaff1->dross, "chaff1");
	chaff1->slag = 1;
	chaff* chaff2 = new (buff1 + sizeof(chaff)) chaff;
	strcpy_s(chaff2->dross, "chaff2");
	chaff2->slag = 2;

	cout << "Chaff1: " << endl;
	cout << "dross:" << chaff1->dross << "  " << "slag:" << chaff1->slag << endl;
	cout << "Chaff2:" << endl;
	cout << "dross:" << chaff2->dross << " " << "slag: " << chaff2->slag << endl;
	delete[]buff1;
}
void question9_4() {
	SALES::Sales s;
	double ar[] = { 1.0, 2.0, 5.0, 3.0 };
	SALES::setSales(s, ar, SALES::QUARTERS);
	SALES::showSales(s);
}