// Assignment_3.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cmath>
#include <string>

const double epsilon = 0.001;

int inclusion(double v) {
	int i = 0;
	int n = 0;
	while (n * n <= v) {
		n++;
		i++;
		std::cout << i << '\t' << n << std::endl;
	}

	if (n * n > v) {
		n--;
	}
	double a = static_cast<double>(n);
	double b = a + 1;
	double x = (a + b) / 2;
	while (std::abs(x * x - v) > epsilon) {
		i++;
		std::cout << i << '\t' << x << std::endl;
		if (x * x < v) {
			a = x;
		} else {
			b = x;
		}
		x = (a + b) / 2;
	}
	return i;
}

double f(double x, double v) {
	return x * x - v;
}

double df(double x) {
	return 2 * x;
}

double max(double a, double b) {
	return  (a > b) ? a : b;
}

int newtonraphson(double v) {
	int i = 0;
	double x = max(v, 1);
	while (f(x, v) >= epsilon) {
		i++;
		x = x - (f(x, v) / df(x));
		std::cout << i << '\t' << x << std::endl;
	}
	return i;
}

// Version of newtonraphson that actually calculates the value
double calc_newtonraphson(double v) {
	double x = max(v, 1);
	while (f(x, v) >= epsilon) {
		x = x - (f(x, v) / df(x));
	}
	return x;
}

void output_factor(bool& first_factor, int i) {
	if (!first_factor) {
		std::cout << " * ";
	} else {
		first_factor = false;
	}
	std::cout << i;
}

void factorize(int n) {
	bool first_factor = true;
	std::cout << n << " = ";
	int i = 2;
	int sqrt_n = calc_newtonraphson(n);
	// We won't find any prime factors above sqrt(n), so we store this whenever i is changed.
	while (n > 1 && i < sqrt_n) {
		if (n % i == 0) {
			output_factor(first_factor, i);
			n = n / i;
		} else {
			i++;
			sqrt_n = calc_newtonraphson(n);
		}
	}
	if (n != 1) {
		//in case we terminated by exceeding the square root:
		output_factor(first_factor, n);
	}
	std::cout << std::endl;
}

const std::string bases = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void convert_bases() {
	int in_base;
	std::cout << "Enter input base: ";
	std::cin >> in_base;

	int out_base;
	std::cout << "Enter output base: ";
	std::cin >> out_base;

	std::string in_number;
	std::cout << "Enter input number: ";
	std::cin >> in_number;

	int in_len = in_number.length();
	int out_num = 0;
	char current_char;
	int current_mult = 1;
	for (int i = 1; i <= in_len; i++) {
		current_char = toupper(in_number[in_len - i]);
		out_num += current_mult * bases.find(current_char);
		current_mult *= in_base;
	}
	int current_last_digit;
	std::string out_number = "";
	while (out_num) {
		current_last_digit = out_num % out_base;
		out_number += bases[current_last_digit];
		out_num /= out_base;
	}
	for (int i = out_number.length() - 1; i >= 0; i--)
		std::cout << out_number[i];
	std::cout << std::endl;
}

int main() {
	std::cout <<
		"1. Compare methods for calculating a square root" << std::endl <<
		"2. Factorize an integer" << std::endl <<
		"3. Convert numbers between bases" << std::endl;
	int choice = 0;
	while (choice < 1 || choice > 3) {
		std::cout << "Which one do you choose? ";
		std::cin >> choice;
		std::cout << std::endl;
	}

	int a;
	int b;
	int n;
	switch (choice) {
		case 1:
			std::cout <<
				"Comparing the Newton-Ralphson method and the inclusion method " << std::endl <<
				"Enter a number to compare the number of steps required to compute it:";
			double v;
			std::cin >> v;
			std::cout << std::endl << "Newton-Ralphson method:" << std::endl;
			a = newtonraphson(v);
			std::cout << std::endl << "Inclusion" << std::endl;
			b = inclusion(v);
			std::cout <<
				"Number of steps for the Newton-Ralphson method: " << a << std::endl <<
				"Number of steps for the inclusion method: " << b << std::endl;
			break;
		case 2:
			std::cout << "Enter an integer to factorize: ";
			std::cin >> n;
			factorize(n);
			break;
		case 3:
			convert_bases();
			break;
	}
	return 0;
}
