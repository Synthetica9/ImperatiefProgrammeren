// Assignment_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>

const double epsilon = 0.001;

int inclusion(double v) {
	int i = 0;
	int n = 0;
	do {
		n++;
	} while (n * n <= v);

	if (n*n > v) {
		n--;
	}
	double a = static_cast<double>(n);
	double b = a + 1;
	double x = (a + b) / 2;
	while (abs(x * x - v) > epsilon) {
		i++;
		std::cout << i << ' ' << x << '\n';
		if (x * x < v) {
			a = x;
		}
		else {
			b = x;
		}
		x = (a + b) / 2;
	}
	return i;
}

void factorize(int n) {
	bool first_factor = true;
	std::cout << n << " = ";
	int i = 2;
	while (n > 1) {
		if (n % i == 0) {
			if (!first_factor) {
				std::cout << " * ";
			} else {
				first_factor = false;
			}
			std::cout << i;
			n = n / i;
		} else {
			i++;
		}
	}
	std::cout << '\n';
}

double f(double x, double v) {
	return x*x - v;
}

double df(double x) {
	return 2 * x;
}

int newtonraphson(double v) {
	int i = 0;
	double x = (v > 1) ? v : 1;
	while (f(x,v) >= epsilon) {
		i++;
		x = x - (f(x, v) / df(x));
		std::cout << i << ' ' << x << '\n';
	}
	return i;
}

const std::string bases = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void convert_bases(){
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
		current_char = toupper(in_number[in_len - i ]);
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
//	std::cout << "Comparing the Newton-Ralphson method and the inclusion method \n" <<
//		"Enter a number to compare the number of steps required to compute it:";
//	double v;
//	std::cin >> v;
//	std::cout << "\nNewton-Ralphson method:\n";
//	int a = newtonraphson(v);
//	std::cout << "\nInclusion";
//	int b = inclusion(v);
//	std::cout << "Number of steps for the Newton-Ralphson method: " << a << "\nNumber of steps for the inclusion method: " << b << '\n';
//	
	convert_bases();
	return 0;
}