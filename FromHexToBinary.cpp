#include <iostream>
#include <string>
#include <algorithm>

std::string FromHexToBinary(std::string string) {
	std::string s;
	for (int i = 0; i < string.size(); ++i) {
		if (string[i] == '0') {
			s.push_back('0000');
		}
		if (string[i] == '1') {
			s.push_back('0001');
		}
		if (string[i] == '2') {
			s.push_back('0010');
		}
		if (string[i] == '3') {
			s.push_back('0011');
		}
		if (string[i] == '4') {
			s.push_back('0100');
		}
		if (string[i] == '5') {
			s.push_back('0101');
		}
		if (string[i] == '6') {
			s.push_back('0110');
		}
		if (string[i] == '7') {
			s.push_back('0111');
		}
		if (string[i] == '8') {
			s.push_back('1000');
		}
		if (string[i] == '9') {
			s.push_back('1001');
		}
		if (string[i] == 'A') {
			s.push_back('1010');
		}
		if (string[i] == 'B') {
			s.push_back('1011');
		}
		if (string[i] == 'C') {
			s.push_back('1100');
		}
		if (string[i] == 'D') {
			s.push_back('1101');
		}
		if (string[i] == 'E') {
			s.push_back('1110');
		}
		if (string[i] == 'F') {
			s.push_back('1111');
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