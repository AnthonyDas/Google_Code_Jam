#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

// Problem A. Counting Sheep
void QualificationRound2016A(const std::string &version) {

	std::string inpath("QualificationRound2016/A-" + version + "-practice.in");
	std::ifstream infile(inpath);
	if (!infile) { throw(std::runtime_error("Cannot open infile " + inpath)); }

	std::string outpath("QualificationRound2016/A-" + version + "-practice.out");
	std::ofstream outfile(outpath);
	if (!outfile) { throw(std::runtime_error("Cannot open outfile " + outpath)); }

	int total_tests;
	infile >> total_tests;

	int test_count = 0, test;
	while (infile >> test) {
		++test_count;

		std::cout << test_count << " " << test << std::endl;

		std::vector<bool> digits(10, false);
		int multiplier = 0;
		while (true) {
			++multiplier;
			int product = multiplier * test;

			if (product == 0) {
				std::ostringstream ss;
				ss << "Case #" << test_count << ": INSOMNIA" << std::endl;
				std::cout << ss.str();
				outfile << ss.str();
				break;
			}

			// Add each digit to the vector of digits
			while (product) {
				digits[product % 10] = true;
				product /= 10;
			}

			// Check observed digits
			bool finished = true;
			for (std::vector<bool>::const_iterator it = std::begin(digits); it != std::end(digits); ++it) {
				if (!(*it)) {
					finished = false;
					break;
				}
			}
			if (finished) { // Have seen all digits
				std::ostringstream ss;
				ss << "Case #" << test_count << ": " << (multiplier * test) << std::endl;
				std::cout << ss.str();
				outfile << ss.str();
				break;
			}
		}
	}

	std::cout << (total_tests == test_count ? "Correct" : "INCORRECT") << " number of test cases processed" << std::endl;
}


// Problem B. Revenge of the Pancakes
void QualificationRound2016B(const std::string &version) {

	std::string inpath("QualificationRound2016/B-" + version + "-practice.in");
	std::ifstream infile(inpath);
	if (!infile) { throw(std::runtime_error("Cannot open infile " + inpath)); }

	std::string outpath("QualificationRound2016/B-" + version + "-practice.out");
	std::ofstream outfile(outpath);
	if (!outfile) { throw(std::runtime_error("Cannot open outfile " + outpath)); }

	int total_tests;
	infile >> total_tests;

	int test_count = 0, flips;
	std::string  test;
	while (infile >> test) {
		++test_count;

		std::cout << test_count << " " << test << std::endl;

		flips = 0;

		char prvchar = test.back();
		if (prvchar == '-') {
			++flips;
		}

		for (std::string::const_reverse_iterator rit = test.crbegin(); rit != test.crend(); ++rit) {
			// if (*rit == prvchar) {// Do nothing}
			if (*rit != prvchar) {
				++flips;
				prvchar = *rit;
			}
		}

		std::ostringstream ss;
		ss << "Case #" << test_count << ": " << flips << std::endl;
		std::cout << ss.str();
		outfile << ss.str();
	}

	std::cout << (total_tests == test_count ? "Correct" : "INCORRECT") << " number of test cases processed" << std::endl;
}

int convert_base_to_decimal(const std::string &x, const int &base) {
	int pow = 1, decimal = 0;
	for (std::string::const_reverse_iterator crit = x.crbegin(); crit != x.crend(); ++crit) {
		if (*crit) {
			decimal += pow * (*crit);
		}
		pow *= base;
	}
	return decimal;
}

int find_factor(const int &decimal) {
	const int lim = sqrt(decimal);
	for (int i = 2; i <= lim; ++i) {
		if (decimal % i == 0) {
			return i;
		}
	}

	return -1; // decimal is prime
}

// Problem C. Coin Jam
void QualificationRound2016C(const std::string &version) {

	std::string inpath("QualificationRound2016/C-" + version + "-practice.in");
	std::ifstream infile(inpath);
	if (!infile) { throw(std::runtime_error("Cannot open infile " + inpath)); }

	std::string outpath("QualificationRound2016/C-" + version + "-practice.out");
	std::ofstream outfile(outpath);
	if (!outfile) { throw(std::runtime_error("Cannot open outfile " + outpath)); }

	int total_tests;
	infile >> total_tests;

	int test_count = 0, N, J;
	while (infile >> N >> J) {
		++test_count;

		std::cout << test_count << " " << N << " " << J << std::endl;

		std::string trial(N, '0');
		trial.front() = trial.back() = '1';

		
	}

	std::cout << (total_tests == test_count ? "Correct" : "INCORRECT") << " number of test cases processed" << std::endl;
}
