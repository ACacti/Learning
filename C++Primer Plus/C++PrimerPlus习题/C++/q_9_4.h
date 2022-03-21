#pragma once
#ifndef Q_9_4
#define Q_9_4
namespace SALES {
	const int QUARTERS = 4;
	struct Sales {
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	};
	void setSales(Sales& s, const double ar[], int n = QUARTERS);
	void setSales(Sales& s);
	void showSales(const Sales& s);
}
#endif