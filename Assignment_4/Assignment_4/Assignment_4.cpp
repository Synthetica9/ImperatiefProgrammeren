#include <iostream>

bool is_leap_year(int year) {
	return (year % 100 == 0) ? ((year / 100) % 4 != 0) : (year % 4 == 0);
};


const int test_years[] = {
	1900, 1999,
	2000, 2012,
	2013, 2014,
	2015, 2016
};

enum Month {
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};


typedef struct date {
	int day;
	Month month;
} date;

int nr_of_days_in_month(int year, Month month) {
	int result; //Best practice: single return point, not bloody 12
	switch (month) {
		case January: result = 31;
			break;
		case February: result = is_leap_year(year) ? 29 : 28;
			break;
		case March: result = 31;
			break;
		case April: result = 30;
			break;
		case May: result = 31;
			break;
		case June: result = 30;
			break;
		case July: result = 31;
			break;
		case August: result = 30;
			break;
		case September: result = 30;
			break;
		case October: result = 31;
			break;
		case November: result = 30;
			break;
		case December: result = 31;
			break;
	}
	return result;
}

Month easter_month(int year) {
	int a = year % 19;
	int b = year / 100;
	int c = year % 100;
	int d = b / 4;
	int e = b % 4;
	int f = (b + 8) / 25;
	int g = (b - f + 1) / 3;
	int h = (19 * a + b - d - g + 15) % 30;
	int i = c / 4;
	int k = c % 4;
	int l = (32 + 2 * e + 2 * i - h - k) % 7;
	int m = (a + 11 * h + 22 * l) / 451;
	int month = (h + l - 7 * m + 114) / 31;
	return Month(month);
}

int easter_day(int year) {
	int a = year % 19;
	int b = year / 100;
	int c = year % 100;
	int d = b / 4;
	int e = b % 4;
	int f = (b + 8) / 25;
	int g = (b - f + 1) / 3;
	int h = (19 * a + b - d - g + 15) % 30;
	int i = c / 4;
	int k = c % 4;
	int l = (32 + 2 * e + 2 * i - h - k) % 7;
	int m = (a + 11 * h + 22 * l) / 451;
	int day = ((h + l - 7 * m + 114) % 31) + 1;
	return day;
}

int main() {
	for (int year: test_years) {
		std::cout 
			<< year << ':' << is_leap_year(year) 
			<< ", " << easter_day(year) << '-' << easter_month(year) << std::endl;
	}
}