#include <iostream>
#include <string>

const std::string PATTERN = "abacaba";


int ReplaceAllQuestionMarksByDAndCountAbacabaSubstrings(std::string& s) {
	for (char& ch : s) {
		if (ch == '?') {
			ch = 'd';
		}
	}
	int m = 0;
	for (size_t i = 0; i + 7 <= s.size(); ++i) {
		int n = 0;
		for (size_t j = 0; j != 7; ++j) {
			if (s[i + j] == PATTERN[j]) {
				++n;
			}
		}
		if (n == 7) {
			++m;
		}
	}
	return m;
}



int main() {
	int T;
	std::cin >> T;
	for (int i = 0; i != T; ++i) {
		int n;
		std::cin >> n;
		std::string s;
		std::cin >> s;
		std::string e = s;
		int f = ReplaceAllQuestionMarksByDAndCountAbacabaSubstrings(s);
		if (f > 1) {
			std::cout << "No" << std::endl;
			continue;
		}
		if (f == 1) {
			std::cout << "Yes" << std::endl;
			std::cout << s << std::endl;
			continue;
		}
		s = e;
		int p = 0;
		for (size_t x = 0; x + 7 <= s.size(); ++x) {
			int h = 0;
			for (int y = 0; y != 7; ++y) {
				if (s[x + y] == PATTERN[y] || s[x + y] == '?') {
					s[x + y] = PATTERN[y];
					++h;
				}
			}
			if (h == 7) {
				int d = ReplaceAllQuestionMarksByDAndCountAbacabaSubstrings(s);
				if (d == 1) {
					std::cout << "Yes" << std::endl;
					std::cout << s << std::endl;
					++p;
					break;
				}
			}
			s = e;
		}
		if (p == 0) {
			std::cout << "No" << std::endl;
		}
	}
	return 0;
}

