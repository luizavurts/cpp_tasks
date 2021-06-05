#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, x;
		std::cin >> n >> x;
		std::vector<int> massive;
		for (int j = 0; j < n; ++j) {
			int a;
			std::cin >> a;
			massive.push_back(a);
		}
		int sum = 0;
		std::sort(massive.begin(), massive.end());
		for (int j = 0;j < n; ++j) {
			if (massive[j] + sum == x && massive[n - 1] > massive[j]) {
				int a = massive[j];
				massive[j] = massive[n - 1];
				massive[n - 1] = a;
				sum += massive[j];
			}
			else if (massive[j] + sum == x && massive[n - 1] == massive[j] && massive[0] != massive[j]) {
				sum -= massive[0];
				sum += massive[n - 1];
				massive[n - 1] = massive[0];
				sum += massive[j];
			}
			else if (massive[j] + sum == x && massive[n - 1] == massive[j] && massive[0] == massive[j]) {
				std::cout << "No";
				break;
			}
			else {
				sum += massive[j];
			}
		}
		if (sum == x) {
			std::cout << "No";
			break;
		}
		std::cout << "Yes" << " ";
		for (int j = 0; j < n; ++j) {
			std::cout << massive[j] << " ";
		}
	}
	return 0;
}