#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N;
	std::cin >> N;
	std::vector<int> x_vector;
	std::vector<int> y_vector;
	for (int i = 0; i < N; ++i) {
		int x, y;
		std::cin >> x >> y;
		x_vector.push_back(x);
		y_vector.push_back(y);
	}
	int maxx = 0;
	for (int i = 0; i < x_vector.size(); ++i) {
		if (y_vector[i] == 0 && x_vector[i] > maxx) {
			maxx = x_vector[i];
		}
	}
	int minx = 1001;
	for (int i = 0; i < x_vector.size(); ++i) {
		if (y_vector[i] == 0 && x_vector[i] < minx) {
			minx = x_vector[i];
		}
	}
	int maxy = 0;
	for (int i = 0; i < y_vector.size(); ++i) {
		if (abs(y_vector[i]) > abs(maxy)) {
			maxy = y_vector[i];
		}
	}
	int S = (maxx - minx) * maxy / 2;
	std::cout << S << std::endl;
	return 0;
}