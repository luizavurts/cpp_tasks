#include <vector>
#include <iostream>

size_t FindNumber(const std::vector<int>& v, int number) {
	for (size_t i = 0; i < v.size(); ++i) {
		if (v[i] == number) {
			return i;
		}
	}
	return v.size();
}

size_t BinarySearch(const std::vector<int>& v, int number) {
	size_t begin = 0;
	size_t end = v.size();
	while (end - begin > 1) {
		size_t middle = (begin + end) / 2;
		if (v[middle] <= number) {
			begin = middle;
		}
		else {
			end = middle;
		}
	}
	if (end - begin == 0) {
		return v.size();
	}
	if (v[begin] != number) {
		return v.size();
	}
	return begin;
}

size_t BinarySearch2(const std::vector<int>& v, int number) {
	size_t begin = 0;
	size_t end = v.size() - 1;
	while (end + 1 - begin > 1) {
		size_t middle = (begin + end + 1) / 2;
		if (v[middle] <= number) {
			begin = middle;
		}
		else {
			end = middle - 1;
		}
	}
	if (end - begin < 0) {
		return v.size();
	}
	if (v[begin] == number) {
		return begin;
	}
	return v.size();
}

int main() {
	std::vector<int> v;
	v.push_back(10);
	v.push_back(15);
	v.push_back(16);
	v.push_back(20);
	v.push_back(21);
	v.push_back(24);
	std::cout << FindNumber(v, 20) << std::endl;
	std::cout << BinarySearch(v, 20) << std::endl;
	return 0;
}
