#include <vector>
#include <iostream>
#include <algorithm>

void MergeSort(std::vector<int>& vec) {
	if (vec.size() < 2) {
		return;
    }
	size_t size = vec.size() / 2;
	std::vector<int> first(vec.begin(), vec.begin() + size);
	std::vector<int> second(vec.begin() + size, vec.end());
	MergeSort(first);
	MergeSort(second);
	std::vector<int>::iterator first_it = first.begin();
	std::vector<int>::iterator second_it = second.begin();
	std::vector<int>::iterator vec_it = vec.begin();
	while (first_it != first.end() && second_it != second.end()) {
		if (*first_it < *second_it) {
			//*vec_it = *first_it;
			//++first_it; // first_it.operator++()
			//++vec_it;
			//first_it++; // first_it.operator++(0)
			*vec_it++ = *first_it++;
		}
		else {
			*vec_it++ = *second_it++;
		}
	}
	while (first_it != first.end()) {
		*vec_it++ = *first_it++;
	}
	while (second_it != second.end()) {
		*vec_it++ = *second_it++;
	}
}

int maingbv5tgrfb() {
	std::vector<int> vec;
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(5);
	vec.push_back(10);
	vec.push_back(7);
	//MergeSort(vec);
	std::sort(vec.begin(), vec.end());
	for (int number : vec) {
		std::cout << number << " ";
	}
	std::cout << std::endl;
	return 0;
}