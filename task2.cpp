#include <iostream> 
#include <vector>
#include <algorithm>

std::vector<int> Get(int N) {
	std::vector<int> vec;
	int a;
	while (N != 0) {
		a = N % 10;
		vec.push_back(a);
		N /= 10;
	}
    reverse(vec.begin(), vec.end());
	return vec;
}

int Min(std::vector<int> vec) {
	int a = vec[0];
	for (int i = 0; i < vec.size(); ++i) {
		if (vec[i] == 0) {
			a *= 0;
			return 0;
		}
		else if (vec[i] == 1) {
			a *= 1;
		}
		else {
			a += vec[i];
		}
	}
	return a;
}
int main() {
	int N;
	std::cin >> N;
	std::vector<int> V = Get(N);
	int res = Min(V);
    std::cout << res;
	return 0;
}
