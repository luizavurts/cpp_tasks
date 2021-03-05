#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class SegmentTreeMax {
public:
	SegmentTreeMax(size_t size) : tree(4 * size, 0), size(size) {}

	int Max(size_t begin, size_t end) {
		return Max(begin, end, 1, 0, size);
	}

	int Max(size_t begin, size_t end, size_t node, size_t node_begin, size_t node_end) {
		if (node_begin == begin && node_end == end) {
			return tree[node];
		}
		size_t node_middle = (node_begin + node_end) / 2;
		if (node_middle <= begin) {
			return Max(begin, end, node * 2 + 1, node_middle, node_end);
		}
		else if (begin < node_middle && node_middle < end) {
			return std::max(Max(begin, node_middle, node * 2, node_begin, node_middle),
				Max(node_middle, end, node * 2 + 1, node_middle, node_end));
		}
		else {
			return Max(begin, end, node * 2, node_begin, node_middle);
		}
	}

	void Update(size_t index, int value) {
		Update(index, value, 1, 0, size);
	}

	void Update(size_t index, int value, size_t node, size_t node_begin, size_t node_end) {
		if (node_end - node_begin == 1) {
			tree[node] = value;
			return;
		}
		size_t node_middle = (node_begin + node_end) / 2;
		if (index < node_middle) {
			Update(index, value, node * 2, node_begin, node_middle);
		}
		else {
			Update(index, value, node * 2 + 1, node_middle, node_end);
		}
		tree[node] = std::max(tree[node * 2], tree[node * 2 + 1]);

	}
private:
	std::vector<int> tree;
	size_t size;
};

class SegmentTreeMin {
public:
	SegmentTreeMin(size_t size) : tree(4 * size, 0), size(size) {}

	int Min(size_t begin, size_t end) {
		return Min(begin, end, 1, 0, size);
	}

	int Min(size_t begin, size_t end, size_t node, size_t node_begin, size_t node_end) {
		if (node_begin == begin && node_end == end) {
			return tree[node];
		}
		size_t node_middle = (node_begin + node_end) / 2;
		if (node_middle <= begin) {
			return Min(begin, end, node * 2 + 1, node_middle, node_end);
		}
		else if (begin < node_middle && node_middle < end) {
			return std::min(Min(begin, node_middle, node * 2, node_begin, node_middle),
				Min(node_middle, end, node * 2 + 1, node_middle, node_end));
		}
		else {
			return Min(begin, end, node * 2, node_begin, node_middle);
		}
	}

	void Update(size_t index, int value) {
		Update(index, value, 1, 0, size);
	}

	void Update(size_t index, int value, size_t node, size_t node_begin, size_t node_end) {
		if (node_end - node_begin == 1) {
			tree[node] = value;
			return;
		}
		size_t node_middle = (node_begin + node_end) / 2;
		if (index < node_middle) {
			Update(index, value, node * 2, node_begin, node_middle);
		}
		else {
			Update(index, value, node * 2 + 1, node_middle, node_end);
		}
		tree[node] = std::min(tree[node * 2], tree[node * 2 + 1]);

	}
private:
	std::vector<int> tree;
	size_t size;
};

std::vector<int> PrefixSums(const std::vector<int>& input_array) {
	std::vector<int> prefix_sums(input_array.size() + 1, 0);
	for (size_t i = 0; i < input_array.size(); ++i) {
		prefix_sums[i + 1] = prefix_sums[i] + input_array[i];
	}
	return prefix_sums;
}

class IntervalSums {
public:
	IntervalSums(const std::vector<int>& input_array) : prefix_sums(PrefixSums(input_array)) {}

	int GetIntervalSum(size_t begin_index, size_t end_index) {
		return prefix_sums[end_index] - prefix_sums[begin_index];
	}
private:
	std::vector<int> prefix_sums;
};

int NumberOfNewValues(const std::vector<int>& s, int l, int r) {
	std::vector<int> massive(s.size(), 0);
	for (int i = 1; i < massive.size(); ++i) {
		massive[i] = massive[i - 1] + s[i - 1];
	}
 	IntervalSums sum(s);
	int m = sum.GetIntervalSum(l, r);
	std::vector<int> begin;
	for (int i = 0; i < l; ++i) {
		begin.push_back(massive[i]);
	}
	std::vector<int> end;
	for (int i = r + 1; i < massive.size(); ++i) {
		end.push_back(massive[i]);
	}
	SegmentTreeMax a(begin.size());
	int max_of_the_first_segment = a.Max(std::begin(begin), std::end(begin));
	SegmentTreeMin b(begin.size());
	int min_of_the_first_segment = b.Min(std::begin(begin), std::end(begin));
	SegmentTreeMax c(begin.size());
	int max_of_the_second_segment = c.Max(std::begin(end), std::end(end));
	SegmentTreeMin d(begin.size());
	int min_of_the_second_segment = d.Min(std::begin(end), std::end(end));
	max_of_the_second_segment += m;
	min_of_the_second_segment += m;
	int max;
	int min;
	if (max_of_the_first_segment > max_of_the_second_segment) {
		max = max_of_the_first_segment;
	}
	else {
		max = max_of_the_second_segment;
	}
	if (min_of_the_first_segment < min_of_the_second_segment) {
		min = min_of_the_first_segment;
	}
	else {
		min = min_of_the_second_segment;
	}
	int number_of_new_values = max - min + 1;
}

int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, m;
		std::cin >> n >> m;
		std::vector<int> s;
		for (int i = 0; i < n; ++i) {
			char k;
			std::cin >> k;
			if (k == '+') {
				s.push_back(1);
			}
			else {
				s.push_back(-1);
			}
		}
		for (int i = 0; i < m; ++i) {
			int l, r;
			std::cin >> l >> r;
		}
	}
	return 0;
}