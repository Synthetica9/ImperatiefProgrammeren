#include <iostream>

bool is_leap_year(int year) {
	return (year % 100 == 0) ? (year % 400 == 0) : (year % 4 == 0);
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


int nr_of_days_in_month(int year, Month month) {
	int result = -1; 
	switch (month) {
		case February: 
			result = 28 + is_leap_year(year);
			break;
		case January:
		case March:
		case May:
		case July:
		case August:
		case October:
		case December:
			result = 31;
			break;
		case April:
		case June:
		case September:
		case November:
			result = 30;
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

int day_number_in_year(int day, Month month, int year) {
	int num_days = day;
	for (int count_month = 1; count_month < month; count_month++)
		num_days += nr_of_days_in_month(year, static_cast<Month>(count_month));
	return num_days;
}

Month month_in_year_of_day_number (int day_number, int year) {
	int m = 1;
	while (
		day_number_in_year(
			nr_of_days_in_month(year, static_cast<Month>(m)),
			static_cast<Month>(m), year) < day_number) {
		m++;
	}
	return static_cast<Month>(m);
}

int day_in_month_of_day_number (int day_number, int year) {
	return day_number - day_number_in_year(
		1, month_in_year_of_day_number(day_number, year), year) + 1; 
}

int main() {
	for (int year: test_years) {
		int e_day = easter_day(year);
		Month e_month = easter_month(year);
		std::cout
			<< year << ':' << is_leap_year(year)
			<< ", " << e_day << '-' << e_month << ' '
			<< day_number_in_year(e_day, e_month, year) << std::endl;
	}
}