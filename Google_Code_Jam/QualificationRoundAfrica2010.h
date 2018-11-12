#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

void brute_force_prices_search(const std::vector<int> &prices, const int &credit, int &i, int &j) {
	for (i = 0; i < prices.size() - 1; ++i) {
		for (j = i + 1; j < prices.size(); ++j) {
			if (prices[i] + prices[j] == credit) { return; }
		}
	}
}

// Problem A. Store Credit
void QualificationRoundAfrica2010A(const std::string &version) {

	std::string inpath("QualificationRoundAfrica2010/A-" + version + "-practice.in");
	// std::ios_base::openmode inmode = (std::ios_base::in | std::ios_base::binary);
	std::ifstream infile(inpath);
	if (!infile) { throw(std::runtime_error("Cannot open infile " + inpath)); }

	std::string outpath("QualificationRoundAfrica2010/A-" + version + "-practice.out");
	// std::ios_base::openmode outmode = (std::ios_base::out | std::ios_base::binary);
	std::ofstream outfile(outpath);
	if (!outfile) { throw(std::runtime_error("Cannot open outfile " + outpath)); }

	int total_tests;
	infile >> total_tests;

	int test_count = 0, credit, items;
	while (infile >> credit >> items) {

		++test_count;

		std::cout << credit << " " << items << std::endl;

		std::vector<int> prices;
		int price;
		while (items--) {
			infile >> price;
			prices.push_back(price);
			std::cout << price << " ";
		}
		std::cout << std::endl;

		int i, j;
		brute_force_prices_search(prices, credit, i, j);

		std::ostringstream ss;
		ss << "Case #" << test_count << ": " << (i + 1) << " " << (j + 1) << std::endl;
		std::cout << ss.str();
		outfile << ss.str();
	}

	std::cout << (total_tests == test_count ? "Correct" : "INCORRECT") << " number of test cases processed" << std::endl;
}


// Problem B.Reverse Words
void QualificationRoundAfrica2010B(const std::string &version) {

	std::string inpath("QualificationRoundAfrica2010/B-" + version + "-practice.in");
	std::ifstream infile(inpath);
	if (!infile) { throw(std::runtime_error("Cannot open infile " + inpath)); }

	std::string outpath("QualificationRoundAfrica2010/B-" + version + "-practice.out");
	std::ofstream outfile(outpath);
	if (!outfile) { throw(std::runtime_error("Cannot open outfile " + outpath)); }

	int total_tests;
	infile >> total_tests;

	int test_count = 0;
	std::string line;
	while (std::getline(infile, line)) {

		++test_count;

		std::istringstream iss(line);

		std::vector<std::string> words;
		std::string word;
		while (iss >> word) {
			words.push_back(word);
		}

		std::string rev_line;
		for (std::vector<std::string>::const_reverse_iterator crit = words.crbegin(); crit != words.crend(); ++crit) {
			rev_line += (" " + *crit);
		}

		std::ostringstream oss;
		oss << "Case #" << test_count << ":" << rev_line << std::endl;
		std::cout << oss.str();
		outfile << oss.str();
	}

	std::cout << (total_tests == test_count ? "Correct" : "INCORRECT") << " number of test cases processed" << std::endl;
}


void append_translated_letter(std::string &translated, const char &digit, const int &count) {
	if (!translated.empty() && translated.back() == digit) {
		translated.append(" ");
	}
	translated.append(std::string(count, digit));
}

// Problem C. T9 Spelling
void QualificationRoundAfrica2010C(const std::string &version) {

	std::string inpath("QualificationRoundAfrica2010/C-" + version + "-practice.in");
	std::ifstream infile(inpath);
	if (!infile) { throw(std::runtime_error("Cannot open infile " + inpath)); }

	std::string outpath("QualificationRoundAfrica2010/C-" + version + "-practice.out");
	std::ofstream outfile(outpath);
	if (!outfile) { throw(std::runtime_error("Cannot open outfile " + outpath)); }

	int total_tests;
	infile >> total_tests;

	int test_count = 0;
	std::string message;
	while (std::getline(infile, message)) {

		++test_count;

		std::string translated;
		for (std::string::const_iterator cit = message.cbegin(); cit < message.cend(); ++cit) {

			switch (*cit) {
			case 'a':
				append_translated_letter(translated, '2', 1); break;
			case 'b':
				append_translated_letter(translated, '2', 2); break;
			case 'c':
				append_translated_letter(translated, '2', 3); break;
			case 'd':
				append_translated_letter(translated, '3', 1); break;
			case 'e':
				append_translated_letter(translated, '3', 2); break;
			case 'f':
				append_translated_letter(translated, '3', 3); break;
			case 'g':
				append_translated_letter(translated, '4', 1); break;
			case 'h':
				append_translated_letter(translated, '4', 2); break;
			case 'i':
				append_translated_letter(translated, '4', 3); break;
			case 'j':
				append_translated_letter(translated, '5', 1); break;
			case 'k':
				append_translated_letter(translated, '5', 2); break;
			case 'l':
				append_translated_letter(translated, '5', 3); break;
			case 'm':
				append_translated_letter(translated, '6', 1); break;
			case 'n':
				append_translated_letter(translated, '6', 2); break;
			case 'o':
				append_translated_letter(translated, '6', 3); break;
			case 'p':
				append_translated_letter(translated, '7', 1); break;
			case 'q':
				append_translated_letter(translated, '7', 2); break;
			case 'r':
				append_translated_letter(translated, '7', 3); break;
			case 's':
				append_translated_letter(translated, '7', 4); break;
			case 't':
				append_translated_letter(translated, '8', 1); break;
			case 'u':
				append_translated_letter(translated, '8', 2); break;
			case 'v':
				append_translated_letter(translated, '8', 3); break;
			case 'w':
				append_translated_letter(translated, '9', 1); break;
			case 'x':
				append_translated_letter(translated, '9', 2); break;
			case 'y':
				append_translated_letter(translated, '9', 3); break;
			case 'z':
				append_translated_letter(translated, '9', 4); break;
			case ' ':
				append_translated_letter(translated, '0', 1); break;
			}
		}

		std::ostringstream ss;
		ss << "Case #" << test_count << ": " << translated << std::endl;
		std::cout << ss.str();
		outfile << ss.str();
	}

	std::cout << (total_tests == test_count ? "Correct" : "INCORRECT") << " number of test cases processed" << std::endl;
}
