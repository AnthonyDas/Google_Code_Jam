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

template <typename T1, typename T2>
T1 convert_binary_to_base(const T1 &bin, const T2 &base) {
	if (bin == 0) { return 0; }

	return (base * convert_binary_to_base(bin / 2, base)) + (bin % 2);
}

template <typename T>
T find_factor(const T &decimal) {
	for (T i = 2; (i * i) <= decimal; ++i) {
		if (decimal % i == 0) {
			return i;
		}
	}

	return 0; // decimal is prime
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

		// For a string of length N comprising only of 0 or 1, with the first
		// and last positions being 1, in base 2 will mean every odd number between
		// and (2^(N-1) + 1) and (2^N - 1)

		const long long int lim = pow(2, N) - 1;
		for (long long int trial = (1 << (N - 1)) + 1; J > 0; trial += 2) {

			std::vector<long long int> factors;

			// Check whether non prime in bases 2 to 10 inclusive
			bool nonprime = true;
			for (int base = 2; base <= 10; ++base) {
				long long int decimal = convert_binary_to_base(trial, base);
				long long int factor = find_factor(decimal);
				if (!factor) {
					break;
				}
				else {
					factors.push_back(factor);
				}
			}

			if (factors.size() < 9) {
				continue;
			}

			--J; // Reduce remaining Coin Jams needed

			// Print the non-trivial divisors
			std::ostringstream ss;
			ss << convert_binary_to_base(trial, 10);
			for (auto cit = factors.cbegin(); cit != factors.cend(); ++cit) {
				ss << " " << *cit;
			}
			ss << std::endl;
			std::cout << ss.str();
			outfile << ss.str();
		}
	}

	std::cout << (total_tests == test_count ? "Correct" : "INCORRECT") << " number of test cases processed" << std::endl;
}


// Problem D. Fractiles
void QualificationRound2016D(const std::string &version) {

	std::string inpath("QualificationRound2016/D-" + version + "-practice.in");
	std::ifstream infile(inpath);
	if (!infile) { throw(std::runtime_error("Cannot open infile " + inpath)); }

	std::string outpath("QualificationRound2016/D-" + version + "-practice.out");
	std::ofstream outfile(outpath);
	if (!outfile) { throw(std::runtime_error("Cannot open outfile " + outpath)); }

	int total_tests;
	infile >> total_tests;


	//std::cout << (total_tests == test_count ? "Correct" : "INCORRECT") << " number of test cases processed" << std::endl;
}