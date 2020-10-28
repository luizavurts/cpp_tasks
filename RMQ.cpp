#include <iostream> 
#include <vector>
#include <algorithm>
#include <tuple>


std::tuple<int, int> Maximum(std::vector<int> vec) {
    std::sort(vec.begin(), vec.end());
	int a = 0;
	int count = 0;
	for (int i = 0; i < vec.size(); ++i) {
		if (vec[i] > a) {
			a = vec[i];
			count = i;
		}
	}
	return std::tuple <int, int> (a, count);
}
std::tuple<int, int> FindMax(int l, int r, int L, int R, std::vector<int> vec) {
	if (l == L && r == R) {
	    return Maximum(vec);
	}
	int M = (L + R - 1) / 2;
	int x = 0;
	int c = 0;
	if (l <= M) {
		R = M;
		std::tuple<int, int> x, c = FindMax(l, std::min(r, M), L, M, vec);
	}
	if (r > M) {
		L = M + 1;
		std::tuple<int, int> x, c = FindMax(std::max(l, M), r, M + 1, R, vec);
	}
	return std::tuple<int, int> (x, c);
}
int main() {
	int N;
	std::cin >> N;
	std::vector<int> A;
	for (int i = 0; i < N; ++i) {
		int a;
		std::cin >> a;
		A.push_back(a);
	}
	int k;
	std::cin >> k;
	for (int i = 0; i < k; ++i) {
		int l;
		int r;
		std::cin >> l >> r;
		std::tuple<int, int> a = FindMax(l, r, 0, A.size(), A);
		std::cout << std::get<0>(a) << " " << std::get<1>(a) << std::endl;
	}
	return 0;
}