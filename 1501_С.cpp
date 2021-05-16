#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>
int main() {
	int n;
	std::cin >> n;
	std::vector<int> numbers;
	for (int i = 0; i < n; ++i) {
		int a;
		std::cin >> a;
		numbers.push_back(a);
	}
	std::sort(numbers.begin(), numbers.end());
	std::unordered_map<int, std::pair<int, int>> map;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (map.count(numbers[j] - numbers[i])) {
				std::cout << i + 1 << j + 1  << std::get<0>(map[numbers[j] - numbers[i]]) + 1
					<< std::get<1>(map[numbers[j] - numbers[i]] ) + 1 << std::endl;
				return 0;
			}
			else {
				map[numbers[j] - numbers[i]] = { i, j };

			}
		}
	}
	return 0;
}
