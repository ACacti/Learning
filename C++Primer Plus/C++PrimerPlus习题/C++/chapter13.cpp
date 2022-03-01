#include <iostream>
#include "Classic.h"
#include "VintagePort.h"
//question13_1
void Bravo(const Cd& disk) {
	disk.Report();
}
void question13_1() {
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
		"Alfred Brendel", "Philips", 2, 57.17);
	Cd* pcd = &c1;
	cout << "Using object directly:\n";
	c1.Report();
	c2.Report();

	cout << "Using type cd * pointer to objects:\n";
	pcd->Report();
	pcd = &c2;
	pcd->Report();

	cout << "Calling a functiion with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);
	cout << "Testing assigment: ";
	Classic copy = c2;//����дĬ�Ϲ��캯��....
	copy.Report();
}



void question13_4() {
	Port port("MaoTai", "ruby", 10);
	VintagePort vp = VintagePort("�����Ͻ�", 20, "����", 8);
	port += 10;
	cout << "Port, MaoTai show: \n";
	port.Show();
	vp -= 5;
	cout << "�����Ͻѣ� show:\n";
	vp.Show();
	Port& port_r = port;
	cout << "Port���� Port show:\n";
	port_r.Show();
	port_r = vp;
	cout << "Port���� VP show:\n";
	port_r.Show();

	cout << port << endl;
	cout << vp << endl;
}