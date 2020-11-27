#include <iostream>
#include <vector>

int MexOfTwoSubset() {
	int n;
	std::cin >> n;
	std::vector<int> number_count(101, 0);
	for (int j = 0; j < n; ++j) {
		int a;
		std::cin >> a;
		++number_count[a];
	}
	for (int j = 0; j < 101; ++j) {
		if (number_count[j] == 0) {
			return 2 * j;
		}
		if (number_count[j] == 1) {
			for (int x = j + 1; x < 101; ++x) {
				if (number_count[x] == 0) {
					return x + j;
				}
			}
			return 101 + j;
		}
	}
	return 202;
}
int main452ergthyj() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		std::cout << MexOfTwoSubset() << std::endl;
	}
	return 0;
}