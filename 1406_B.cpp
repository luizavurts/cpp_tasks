#include <iostream>
#include <vector>
#include <algorithm>

int64_t ProductOfFiveNumbers(std::vector<int> array) {
	int64_t max = -243000000000000000;
	if (array.size() == 5) {
		int64_t product = 1;
		for (int i = 0; i < array.size(); ++i) {
			product *= array[i];
		}
		max = std::max(max, product);
	}
	int negative = std::count_if(array.begin(), array.end(), [](const int value) {return value < 0;});
	int positive = std::count_if(array.begin(), array.end(), [](const int value) {return value > 0;});
	int zero = std::count_if(array.begin(), array.end(), [](const int value) {return value == 0;});
	std::sort(array.begin(), array.end());
	if (array.size() >= 6 && negative == array.size()) {
		int64_t product = 1;
		for (int i = array.size() - 1; i >= array.size() - 5; --i) {
			product *= array[i];
		}
		max = std::max(max, product);
	}
	else {
		if (positive >= 5) {
			int64_t product = 1;
			for (int i = array.size() - 1; i >= array.size() - 5; --i) {
				product *= array[i];
			}
			max = std::max(max, product);
		}

		if (positive >= 3 && negative >= 2) {
			int64_t product = 1;
			for (int i = 0; i < 2; ++i) {
				product *= array[i];
			}
			for (int i = array.size() - 1; i >= array.size() - 3; --i) {
				product *= array[i];
			}
			max = std::max(max, product);
		}
		if (positive >= 1 && negative >= 4) {
			int64_t product = 1;
			for (int i = 0; i < 4; ++i) {
				product *= array[i];
			}
			for (int i = array.size() - 1; i >= array.size() - 1; --i) {
				product *= array[i];
			}
			max = std::max(max, product);
		}
		if (zero > 0 && !(positive >= 5) && !(positive >= 3 && negative >= 2) && !(positive >= 1 && negative >= 4)) {
			int64_t product = 0;
			max = std::max(max, product);
		}
	}
	return max;
}

int main() {
	int a;
	std::cin >> a;
	for (int i = 0; i < a; ++i) {
		int b;
		std::cin >> b;
		std::vector<int> array;
		for (int j = 0; j < b; ++j) {
			int c;
			std::cin >> c;
			array.push_back(c);
		}
		std::cout << ProductOfFiveNumbers(array) << std::endl;
	}
	return 0;
}