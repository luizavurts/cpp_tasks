#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

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
		for (int j = 1; j < n; ++j) {
			if (map.count(numbers[i] - numbers[j])) {
				std::cout << numbers[i]  << numbers[j]  << map[numbers[i] - numbers[j]] << std::endl;
				return;
			}
			else {
				map[numbers[i] - numbers[j]] = { numbers[i], numbers[j] };

			}
		}
	}
	return 0;
}
