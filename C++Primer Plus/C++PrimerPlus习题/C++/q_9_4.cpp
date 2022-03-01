#include "q_9_4.h"
#include <iostream>
namespace SALES {
	void setSales(Sales& s, const double ar[], int n) {
		s.max = ar[0];
		s.min = ar[0];
		double sum = 0;
		for (int i = 0; i < n; i++) {
			s.sales[i] = ar[i];
			sum += ar[i];
			if (s.max < ar[i]) {
				s.max = ar[i];
			}
			if (s.min > ar[i]) {
				s.min = ar[i];
			}
		}
		s.average = sum / n;
	}
	void setSales(Sales& s) {
		//¿¡µ√–¥
	}
	void showSales(const Sales& s) {
		std::cout << "Show Sales:\n";
		std::cout << "Sales:";
		for (double t : s.sales) std::cout << t << " ";
		std::cout << std::endl;
		std::cout << "Average:" << s.average << std::endl;
		std::cout << "Max:" << s.average << std::endl;
		std::cout << "Min:" << s.min << std::endl;
	}
}