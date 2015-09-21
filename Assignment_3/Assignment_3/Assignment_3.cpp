// Assignment_3.cpp : Defines the entry point for the console application.
// Name / student number / study student 1 : Patrick Hilhorst / S4577434 / Computer Science
// Name / student number / study student 2 : Fons van der Plas / S4576586 / Mathematics

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const double epsilon = 0.001;

int inclusion(double v)
{
	int i = 0;
	int n = 0;
	while (n * n <= v)
	{
		n++;
		i++;
		cout << i << '\t' << n << endl;
	}

	if (n * n > v)
	{
		n--;
	}
	double a = static_cast<double>(n);
	double b = a + 1;
	double x = (a + b) / 2;
	while (abs(x * x - v) > epsilon)
	{
		i++;
		cout << i << '\t' << x << endl;
		if (x * x < v)
		{
			a = x;
		}
		else
		{
			b = x;
		}
		x = (a + b) / 2;
	}
	return i;
}

void factorize(int n)
{
	bool first_factor = true;
	cout << n << " = ";
	int i = 2;
	while (n > 1)
	{
		if (n % i == 0)
		{
			if (!first_factor)
			{
				cout << " * ";
			}
			else
			{
				first_factor = false;
			}
			cout << i;
			n = n / i;
		}
		else
		{
			i++;
		}
	}
	cout << endl;
}

double f(double x, double v)
{
	return x * x - v;
}

double df(double x)
{
	return 2 * x;
}

int newtonraphson(double v)
{
	int i = 0;
	double x = (v > 1) ? v : 1;
	while (f(x, v) >= epsilon)
	{
		i++;
		x = x - (f(x, v) / df(x));
		cout << i << '\t' << x << endl;
	}
	return i;
}

const string bases = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void convert_bases()
{
	int in_base;
	cout << "Enter input base: ";
	cin >> in_base;

	int out_base;
	cout << "Enter output base: ";
	cin >> out_base;

	string in_number;
	cout << "Enter input number: ";
	cin >> in_number;

	int in_len = in_number.length();
	int out_num = 0;
	char current_char;
	int current_mult = 1;
	for (int i = 1; i <= in_len; i++)
	{
		current_char = toupper(in_number[in_len - i]);
		out_num += current_mult * bases.find(current_char);
		current_mult *= in_base;
	}
	int current_last_digit;
	string out_number = "";
	while (out_num)
	{
		current_last_digit = out_num % out_base;
		out_number += bases[current_last_digit];
		out_num /= out_base;
	}
	for (int i = out_number.length() - 1; i >= 0; i--)
	{
		cout << out_number[i];
	}
	cout << endl;
}

int main()
{
	cout <<
		"1. Compare methods for calculating a square root" << endl <<
		"2. Factorize an integer" << endl <<
		"3. Convert numbers between bases" << endl;
	int choice = 0;
	while (choice != 1 && choice != 2 && choice != 3)
	{
		cout << "Which one do you choose? ";
		cin >> choice;
		cout << endl;
	}

	int a;
	int b;
	int n;
	switch (choice)
	{
	case 1:
		cout <<
			"Comparing the Newton-Ralphson method and the inclusion method " << endl <<
			"Enter a number to compare the number of steps required to compute it:";
		double v;
		cin >> v;
		cout << endl << "Newton-Ralphson method:" << endl;
		a = newtonraphson(v);
		cout << endl << "Inclusion" << endl;
		b = inclusion(v);
		cout <<
			"Number of steps for the Newton-Ralphson method: " << a << endl <<
			"Number of steps for the inclusion method: " << b << endl;
		break;
	case 2:
		cout << "Enter an integer to factorize: ";
		cin >> n;
		factorize(n);
		break;
	case 3:
		convert_bases();
		break;
	}
	return 0;
}