#include <iostream> 
#include <vector>

int GetAverage(std::vector<int> vec) {
	std::vector<int> V;
	for (int size = 1; size <= vec.size(); ++size) {
		for (int i = 0; i < vec.size(); ++i) {
			if (vec.size == 1) {
				return vec[i];
			}
			for (int k = i + 1; k < i + size; ++k) {
				V[i * (size + 1) + i + size] = (V[i * (k + 1) + i + k] + V[(i + k) * (size - k + 1) + i + size]) / 2;
			}
		}
	}
}
int main() {
	int n;
	std::cin >> n;
	std::vector<int> A;
	for (int i = 0; i < n; ++i) {
		int a;
		std::cin >> a;
		A.push_back(a);
	}
	std::vector<int> B;
	for (int i = 0; i < A.size(); ++i) {
		for (int j = 0; j < A.size(); ++j) {

		}
	}
	return 0;
}