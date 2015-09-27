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

void show_month(Month month, int year)
{
	// The starting day is derived from January 1st 1970, by adding or substracting 365 or 366 to the starting day, and returning the result to [0,6] integer space
	int first_day_in_week = (3 + day_number_in_year(0, month, year)) % 7;; // January 1st 1970 is on a Thursday = 3 (Monday = 0)
	if(year >= 1970)
	{
		for (int i = 1970; i < year; i++)
		{
			first_day_in_week = (first_day_in_week + 365 + is_leap_year(i)) % 7;
		}
	} else {
		for (int i = 1970; i > year; i--)
		{
			first_day_in_week = (first_day_in_week - 365 - is_leap_year(i)) % 7;
		}
		first_day_in_week += first_day_in_week < 0 ? 7 : 0; // Make the result positive: [0,6]
	}
	
	//std::cout << month << " " << year; //TODO: display month as string (January instead of 1)
	// Every day of the week is contained in a single tab
	std::cout << std::endl << "Mo\tTu\tWe\tTh\tFr\tSa\tSu" << std::endl;
	for (int i = 0; i < first_day_in_week; i++) // Skip the days before the 1st
	{
		std::cout << "\t";
	}

	for (int n = 1; n <= nr_of_days_in_month(year, month); n++)
	{
		std::cout << n << "\t";
		if ((n + first_day_in_week) % 7 == 0) // Start the next week
		{
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

int main() {
	std::cout << "Test years:";
	for (int year: test_years) {
		int e_day = easter_day(year);
		Month e_month = easter_month(year);
		std::cout
			<< year << ':' << is_leap_year(year)
			<< ", " << e_day << '-' << e_month << ' '
			<< day_number_in_year(e_day, e_month, year) << std::endl;
	}

	std::cout << "\nShow month:\nEnter year: ";
	int year_input = -1;
	std::cin >> year_input;
	std::cout << "Enter month number:";
	int month_input = -1;
	std::cin >> month_input;
	show_month(Month(month_input), year_input);
	
	int n = 1;
	while(n != 0)
	{
		std::cout << "Enter 0 to exit, 1 to display the next month: ";
		std::cin >> n;
		month_input = (month_input + n - 1) % 12 + 1;
		year_input += (month_input + n - 1) / 12;
		show_month(Month(month_input), year_input);
	}
}