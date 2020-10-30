#include <vector>
#include <algorithm>
#include <iostream>


class MaximumAndIndex {
public:
	int maximum;
	int index;

	MaximumAndIndex() : maximum(0), index(0) {}
	bool operator<(const MaximumAndIndex& other) const {
		return maximum < other.maximum;
	}
};


class SegmentTree {
public:
	SegmentTree(size_t size) : tree(4 * size), size(size) {}

	MaximumAndIndex Max(size_t begin, size_t end) {
		return Max(begin, end, 1, 0, size);
	}

	MaximumAndIndex Max(size_t begin, size_t end, size_t node, size_t node_begin, size_t node_end) {
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

	void Update(size_t index, MaximumAndIndex value) {
		Update(index, value, 1, 0, size);
	}

	void Update(size_t index, MaximumAndIndex value, size_t node, size_t node_begin, size_t node_end) {
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
	std::vector<MaximumAndIndex> tree;
	size_t size;
};

int main() {
	int n;
	std::cin >> n;
	SegmentTree b(n);
	for (int i = 0; i < n; ++i) {
		int a;
		std::cin >> a;
		MaximumAndIndex c;
		c.index = i;
		c.maximum = a;
		b.Update(i, c);
	}
	int d;
	std::cin >> d;
	for (int i = 0; i < d; ++i) {
		int begin;
		int end;
		std::cin >> begin >> end;
		MaximumAndIndex g = b.Max(begin - 1, end);
		int x = g.index;
		int y = g.maximum;
		std::cout << y << " " << x << std::endl;
	}

	return 0;
}
