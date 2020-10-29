#include <iostream> 
#include <vector>
#include <algorithm>
int GetAverage(std::vector<int> vec) {
	std::vector<int> V((vec.size() - 1) * (vec.size() + 1) + vec.size() + 1, 0);
	for (int size = 1; size <= vec.size() - size; ++size) {
		for (int i = 0; i < vec.size(); ++i) {
			if (size == 1) {
				V[i * (vec.size() + 1) + i + 1] = vec[i];
			}
			for (int k = i + 1; k < i + size; ++k) {
				V[i * (vec.size() + 1) + i + size] = (V[i * (vec.size() + 1) + k] + V[k * (vec.size() + 1) + i + size]) / 2;
				V[i * (vec.size() + 1) + i + size] = std::max(V[i * (vec.size() + 1) + i + size], (V[i * (vec.size() + 1) + k] + V[k * (vec.size() + 1) + i + size]) / 2);
			}
		}
	}
	return V[(vec.size() + 1) + vec.size()];
	
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
	int res = GetAverage(A);
	std::cout << res;
	return 0;
}
