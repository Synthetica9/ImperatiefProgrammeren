// Assignment 4
// Name / student number / study student 1 : Patrick Hilhorst / S4577434 / Computer Science
// Name / student number / study student 2 : Fons van der Plas / S4576586 / Mathematics

#include <string>
#include <iostream>

using namespace std;

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


const string month_names[] = {
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
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


int day_number_in_year(int day, Month month, int year) {
	int num_days = day;
	for (int count_month = 1; count_month < month; count_month++)
		num_days += nr_of_days_in_month(year, Month(count_month));
	return num_days;
}


Month month_in_year_of_day_number(int day_number, int year) {
	int m = 1;
	while (
		day_number_in_year(
			nr_of_days_in_month(year, Month(m)),
			Month(m), year) 
		< day_number) {
		m++;
	}
	return Month(m);
}


int day_in_month_of_day_number(int day_number, int year) {
	return day_number - day_number_in_year(
		0, month_in_year_of_day_number(day_number, year), year);
}


int easter_day_in_year(int year) {
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
	Month month = Month((h + l - 7 * m + 114) / 31);
	return day_number_in_year(day, month, year);
}


Month easter_month(int year) {
	return month_in_year_of_day_number(easter_day_in_year(year), year);
}


int easter_day(int year) {
	return day_in_month_of_day_number(easter_day_in_year(year), year);
}


string get_month_name(Month month) {
	return month_names[month - 1];
}


string get_date_string(int day, Month month) {
	return to_string(day) + ' ' + get_month_name(month);
}


string get_date_string_by_day_number(int day, int year) {
	return get_date_string(
		day_in_month_of_day_number(day, year),
		month_in_year_of_day_number(day, year));
}


struct Event {
	int easter_offset;
	string name;
};


const Event holy_days[] = {
	{-47, "Carnival"},
	{-2, "Good Friday"},
	{0, "Easter"},
	{39, "Ascension Day"},
	{49, "Whitsuntide"}
};


void internal_show_holy_days(int year) {
	cout << endl << "Holy days in " << year << endl;
	int e_day = easter_day_in_year(year);

	for (Event holy_day : holy_days) {
		cout
			<< holy_day.name << ": "
			<< get_date_string_by_day_number(e_day + holy_day.easter_offset, year) << endl;
	}
}


void show_holy_days() {
	cout << "Enter year: ";
	int year;
	cin >> year;
	internal_show_holy_days(year);
}


void show_month(Month month, int year) {
	// The starting day is derived from January 1st 1970, by adding or substracting 365 or 366 to the starting day, and returning 
	// the result to [0,6] integer space
	int first_day_in_week = (3 + day_number_in_year(0, month, year)) % 7; // January 1st 1970 is on a Thursday = 3 (Monday = 0)
	if (year >= 1970) {
		for (int i = 1970; i < year; i++) {
			first_day_in_week = (first_day_in_week + 365 + is_leap_year(i)) % 7;
		}
	} else {
		for (int i = 1970; i > year; i--) {
			first_day_in_week = (first_day_in_week - 365 - is_leap_year(i)) % 7;
		}
		first_day_in_week += first_day_in_week < 0 ? 7 : 0; // Make the result positive: [0,6]
	}

	cout << get_month_name(month) << " " << year;
	// Every day of the week is contained in a single tab
	cout << endl << "Mo\tTu\tWe\tTh\tFr\tSa\tSu" << endl;
	for (int i = 0; i < first_day_in_week; i++) // Skip the days before the 1st
	{
		cout << '\t';
	}

	for (int n = 1; n <= nr_of_days_in_month(year, month); n++) {
		cout << n << "\t";
		if ((n + first_day_in_week) % 7 == 0) // Start the next week
		{
			cout << endl;
		}
	}
	cout << endl;
}


int main() {
	cout << "Test years:" << endl;
	for (int year : test_years) {
		cout << year << " is " << (is_leap_year(year) ? "" : "not ") << "a leap year.";
		internal_show_holy_days(year);
		cout << endl;
	}

	show_holy_days();

	cout << endl << "Show month:" << endl << "Enter year: ";
	int year_input = -1;
	cin >> year_input;
	cout << "Enter month number:";
	int month_input = -1;
	cin >> month_input;
	show_month(Month(month_input), year_input);

	int n = 1;
	while (n != 0) {
		cout << "Enter 0 to exit, 1 to display the next month: ";
		cin >> n;
		month_input = (month_input + n - 1) % 12 + 1;
		year_input += (month_input + n - 1) / 12;
		show_month(Month(month_input), year_input);
	}
}
