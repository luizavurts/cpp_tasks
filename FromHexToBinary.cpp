#include <iostream>
#include <string>
#include <algorithm>

std::string FromHexToBinary(std::string string) {
	std::string s;
	for (int i = string.size(); i >= 0; --i) {
		if (string[i] == '0') {
			s.push_back('0');
			s.push_back('0');
			s.push_back('0');
			s.push_back('0');
		}
		if (string[i] == '1') {
			s.push_back('1');
			s.push_back('0');
			s.push_back('0');
			s.push_back('0');
		}
		if (string[i] == '2') {
			s.push_back('0');
			s.push_back('1');
			s.push_back('0');
			s.push_back('0');
		}
		if (string[i] == '3') {
			s.push_back('1');
			s.push_back('1');
			s.push_back('0');
			s.push_back('0');
		}
		if (string[i] == '4') {
			s.push_back('0');
			s.push_back('0');
			s.push_back('1');
			s.push_back('0');
		}
		if (string[i] == '5') {
			s.push_back('1');
			s.push_back('0');
			s.push_back('1');
			s.push_back('0');
		}
		if (string[i] == '6') {
			s.push_back('0');
			s.push_back('1');
			s.push_back('1');
			s.push_back('0');
		}
		if (string[i] == '7') {
			s.push_back('1');
			s.push_back('1');
			s.push_back('1');
			s.push_back('0');
		}
		if (string[i] == '8') {
			s.push_back('0');
			s.push_back('0');
			s.push_back('0');
			s.push_back('1');
		}
		if (string[i] == '9') {
			s.push_back('1');
			s.push_back('0');
			s.push_back('0');
			s.push_back('1');
		}
		if (string[i] == 'A') {
			s.push_back('0');
			s.push_back('1');
			s.push_back('0');
			s.push_back('1');
		}
		if (string[i] == 'B') {
			s.push_back('1');
			s.push_back('1');
			s.push_back('0');
			s.push_back('1');
		}
		if (string[i] == 'C') {
			s.push_back('0');
			s.push_back('0');
			s.push_back('1');
			s.push_back('1');
		}
		if (string[i] == 'D') {
			s.push_back('1');
			s.push_back('0');
			s.push_back('1');
			s.push_back('1');
		}
		if (string[i] == 'E') {
			s.push_back('0');
			s.push_back('1');
			s.push_back('1');
			s.push_back('1');
		}
		if (string[i] == 'F') {
			s.push_back('1');
			s.push_back('1');
			s.push_back('1');
			s.push_back('1');
		}
	}
	std::reverse(s.begin(), s.end());
	return s;
}
int main() {
	std::string s;
	std::cin >> s;
	std::cout << FromHexToBinary(s);
	return 0;
}
