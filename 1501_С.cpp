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
	std::unordered_map<int, std::pair<int, int>> map(n);
	for (int i = numbers[0]; i < numbers[n]; ++i) {
		for (int j = numbers[1]; j < numbers[n]; ++j) {
			if (map.count(i - j)) {
				std::cout << i, j, map[i - j];
			}
			else {
				map[i - j] = { i, j };

			}
		}
	}
	return 0;
}