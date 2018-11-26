#include <vector>
#include <string>
#include <algorithm> // find_if(), find_if_not() C++11
#include <iostream>

bool issemicolon(const char c) {
	return c == ';';
}

void separate_words(std::vector<std::string> &split, const std::string &words) {
	auto i = words.cbegin();
	while (i != words.cend()) {

		// Ignore leading punctuation
		i = std::find_if_not(i, words.cend(), issemicolon);

		// Find end of next word
		auto j = std::find_if(i, words.cend(), issemicolon);

		// Copy the characters in [i,j)
		if (i != words.cend()) {
			split.emplace_back(i, j);
		}

		i = j;
	}

	//for (auto &w : split) {
	//	std::cout << w << std::endl;
	//}
}

// How large is the space along the same row, moving right?
int horizontal_gap_size(const std::vector<std::string> &crossword, int i, int j) {
	int res = 0;
	while (crossword[i][j] == '-') {
		++res;
		++j;
	}
	// May actually only be part of a vertical gap 
	return res == 1 ? 0 : res;
}

// How large is the space along the same column, moving down?
int vertical_gap_size(const std::vector<std::string> &crossword, int i, int j) {
	int res = 0;
	while (crossword[i][j] == '-') {
		++res;
		++i;
	}
	// May actually only be part of a horizontal gap 
	return res == 1 ? 0 : res;
}

// Complete the crosswordPuzzle function below.
std::vector<std::string> crosswordPuzzle(std::vector<std::string> crossword, std::string words) {
	std::vector<std::string> split_words;
	separate_words(split_words, words);

	std::vector<bool> word_used(split_words.size(), false);

	for (int i = 0; i < crossword.front().size(); ++i) {
		for (int j = 0; j < crossword.size(); ++j) {

		}
	}

	return crossword;
}