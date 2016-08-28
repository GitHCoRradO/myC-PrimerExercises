#ifndef EX_14_2_H
#define EX_14_2_H

#include <iostream>
using std::istream;
using std::ostream;
#include <string>
using std::string;

class Sales_data {
friend istream &operator>>(istream &, Sales_data &);	//inout operator
friend ostream &operator<<(ostream &, const Sales_data &); //output operator
friend Sales_data operator+(const Sales_data &, const Sales_data &);	//addition operator

public:
	//constructors
	Sales_data() : Sales_data("", 0, 0.0) { }
	Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n * p) { }
	Sales_data(const string &s) : Sales_data(s, 0, 0) { }
	Sales_data(istream &);
	//member functions
	Sales_data &operator+=(const Sales_data &); //compound assignment operator
	string isbn() const { return bookNo; }
private:
	double avg_price() const;
	
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
istream &operator>>(istream &, Sales_data &);
ostream &operator<<(ostream &, const Sales_data &);
Sales_data operator+(const Sales_data &, const Sales_data &);

inline double Sales_data::avg_price() const {
	return units_sold ? revenue/units_sold : 0;
}

ostream &operator<<(ostream &os, const Sales_data &item) {
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
	return os;
}

istream &operator>>(istream &is, Sales_data &item) {
	double price;
	is >> item.bookNo >> item.units_sold >> price;
	if (is)
		item.revenue = item.units_sold * price;
	else
		item = Sales_data();
	return is;
}

#endif