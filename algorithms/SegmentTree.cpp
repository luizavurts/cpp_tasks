#include <vector>
#include <algorithm>
#include <iostream>
class SegmentTree {
public:
	SegmentTree(size_t size): tree(4 * size, 0), size(size) {}

	int Sum(size_t begin, size_t end) {
		return Sum(begin, end, 1, 0, size);
	}

	int Sum(size_t begin, size_t end, size_t node, size_t node_begin, size_t node_end) {
		if (node_begin == begin && node_end == end) {
			return tree[node];
		}
		size_t node_middle = (node_begin + node_end) / 2;
		if (node_middle <= begin) {
			return Sum(begin, end, node * 2 + 1, node_middle, node_end);
		}
		else if (begin < node_middle && node_middle < end) {
			return Sum(begin, node_middle, node * 2, node_begin, node_middle) +
				Sum(node_middle, end, node * 2 + 1, node_middle, node_end);
		}
		else {
			return Sum(begin, end, node * 2, node_begin, node_middle);
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
		tree[node] = tree[node * 2] + tree[node * 2 + 1];

	}
private:
	std::vector<int> tree;
	size_t size;
};

int main() {
	SegmentTree a(10);
	a.Update(3, 8);
	a.Update(7, 4);
	std::cout << a.Sum(2, 5) << std::endl;
	return 0;
}