#include <iostream>
#include <vector>
#include <string>

void CompareSymbols(int suffix_index, const std::string& input_string, std::vector<int>& z, int& begin, int& end, int i) {
	while (suffix_index < input_string.size() && input_string[suffix_index] == input_string[suffix_index - i]) {
		++suffix_index;
	}
	z[i] = suffix_index - i;
	begin = i;
	end = suffix_index;
}

std::vector<int> GetZIndex(const std::string& input_string) {
	std::vector<int> z(input_string.size(), 0);
	int begin = 0;
	int end = 0;
	for (int i = 1; i < z.size(); ++i) {
		if (i >= end) {
			CompareSymbols(i, input_string, z, begin, end, i);
		}
		else if(i - begin + z[i - begin] < end - begin) {
			z[i] = z[i - begin];
		}
		else {
			CompareSymbols(end, input_string, z, begin, end, i);
		}
	}
	return z;
}

std::vector<int> FindSubstring(const std::string& text, const std::string& pattern) {
	std::vector<int> z = GetZIndex(pattern + text);
	std::vector<int> indices;
	for (int i = 0; i < text.size(); ++i) {
		if (z[pattern.size() + i] >= pattern.size()) {
			indices.push_back(i);
		}
	}
	return indices;
}

int main() {
	std::string text;
	std::string pattern;
	std::cin >> text >> pattern;
    std::vector<int> indices = FindSubstring(text, pattern);
	for (int i : indices) {
		std::cout << i << std::endl;
	}
	return 0;
}