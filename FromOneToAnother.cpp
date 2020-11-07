#include  <iostream>
#include <string>
#include <algorithm>

std::string FromOneToAnother(std::string string_number) {
	if (string_number.size() % 4 != 0) {
		std::string string('0', (string_number.size() / 4) + 1 - string_number.size());
		string_number = string + string_number;
	}
	std::string s;
	for (int i = string_number.size() - 1; i >= 0; i -= 4) {
		int a = i;
		int b = i - 1;
		int c = i - 2;
		int d = i - 3;
		if (string_number[a] == 0 && string_number[b] == 0 && string_number[c] == 0 && string_number[d] == 0) {
			s.push_back('0');
		}
		if (string_number[a] == 0 && string_number[b] == 0 && string_number[c] == 0 && string_number[d] == 1) {
			s.push_back('1');
		}
		if (string_number[a] == 0 && string_number[b] == 0 && string_number[c] == 1 && string_number[d] == 0) {
			s.push_back('2');
		}
		if (string_number[a] == 0 && string_number[b] == 0 && string_number[c] == 1 && string_number[d] == 1) {
			s.push_back('3');
		}
		if (string_number[a] == 0 && string_number[b] == 1 && string_number[c] == 0 && string_number[d] == 0) {
			s.push_back('4');
		}
		if (string_number[a] == 0 && string_number[b] == 1 && string_number[c] == 0 && string_number[d] == 1) {
			s.push_back('5');
		}
		if (string_number[a] == 0 && string_number[b] == 1 && string_number[c] == 1 && string_number[d] == 0) {
			s.push_back('6');
		}
		if (string_number[a] == 0 && string_number[b] == 1 && string_number[c] == 1 && string_number[d] == 1) {
			s.push_back('7');
		}
		if (string_number[a] == 1 && string_number[b] == 0 && string_number[c] == 0 && string_number[d] == 0) {
			s.push_back('8');
		}
		if (string_number[a] == 1 && string_number[b] == 0 && string_number[c] == 0 && string_number[d] == 1) {
			s.push_back('9');
		}
		if (string_number[a] == 1 && string_number[b] == 0 && string_number[c] == 1 && string_number[d] == 0) {
			s.push_back('A');
		}
		if (string_number[a] == 0 && string_number[b] == 0 && string_number[c] == 1 && string_number[d] == 1) {
			s.push_back('B');
		}
		if (string_number[a] == 1 && string_number[b] == 1 && string_number[c] == 0 && string_number[d] == 0) {
			s.push_back('C');
		}
		if (string_number[a] == 1 && string_number[b] == 1 && string_number[c] == 0 && string_number[d] == 1) {
			s.push_back('D');
		}
		if (string_number[a] == 1 && string_number[b] == 1 && string_number[c] == 1 && string_number[d] == 0) {
			s.push_back('E');
		}
		if (string_number[a] == 1 && string_number[b] == 1 && string_number[c] == 1 && string_number[d] == 1) {
			s.push_back('F');
		}
	}
    std::reverse(s.begin(), s.end());
	return s;
}

int main() {
	std::string string;
	std::cin >> string;
	std::cout << FromOneToAnother(string);
	return 0;
}
