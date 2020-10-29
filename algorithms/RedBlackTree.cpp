#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cassert>

enum class Color {
	UNDEFINED = 0,
	RED = 1,
	BLACK = 2
};

class RBTreeNode {
public:
	RBTreeNode(): left(nullptr), right(nullptr), parent(nullptr), value(), color(Color::BLACK), is_empty(true) {}

	RBTreeNode* left;
	RBTreeNode* right;
	RBTreeNode* parent;
	int value;
	Color color;
	bool is_empty;
};

class RBTreeIterator {
public:

	RBTreeIterator(RBTreeNode* node) : node(node) {}

	int& operator*() {
		return node->value;
	}

	void operator++() {
		if (!node->right->is_empty) {
			node = node->right;
			while (!node->left->is_empty) {
				node = node->left;
			}
		}
		else {
			while (node->parent != nullptr && node->parent->left != node) {
				node = node->parent;
			}
			node = node->parent;			
		}
	}

	bool operator==(const RBTreeIterator& other) {
		return node == other.node;
	}

	bool operator!=(const RBTreeIterator& other) {
		return !(node == other.node);
	}
private:
	RBTreeNode* node;
};


class RBTree {
public:
	RBTreeIterator begin() const{
		RBTreeNode* node = root;
		if (root->is_empty) {
			return RBTreeIterator(nullptr);
		}
		while (!node->left->is_empty) {
			node = node->left;
		}
		return RBTreeIterator(node);
	}

	RBTreeIterator end() const{
		return RBTreeIterator(nullptr);
	}
	RBTree(): root(new RBTreeNode()) {}

	RBTree(const RBTree& template_to_copy_from): root(new RBTreeNode()) {
		Copy(template_to_copy_from);
	}

	void RemoveAllNodes() {
		while (!root->is_empty) {
			Remove(root->value);
		}
	}

	void Copy(const RBTree& other_tree) {
		for (RBTreeIterator it = other_tree.begin(); it != other_tree.end(); ++it) {
			Add(*it);
		}
	}

	RBTree& operator=(const RBTree& other) {
		RemoveAllNodes();
		Copy(other);
	}

	~RBTree() {
		RemoveAllNodes();
		delete root;
	}

	void MoveUpperNode(RBTreeNode* prev_top_node,  RBTreeNode* new_top_node, RBTreeNode* parent) {
		if (parent == nullptr) {
			root = new_top_node;
		}
		else {
			if (prev_top_node == parent->left) {
				parent->left = new_top_node;				
			}
			else {
				parent->right = new_top_node;				
			}
		}
		new_top_node->parent = parent;
	}

	void SolveRedConflict(RBTreeNode* node) {
		if (node == root) {
			return;
		}
		RBTreeNode* node_parent = node->parent;
		if (node_parent->color == Color::BLACK) {
			return;
		}
		if (node_parent == root) {
			node_parent->color = Color::BLACK;
			return;
		}
		RBTreeNode* grandparent = node_parent->parent;
		RBTreeNode* uncle;
		if (grandparent->left == node_parent) {
			uncle = grandparent->right;
		}
		else {
			uncle = grandparent->left;
		}
		if (uncle->color == Color::RED) {
			grandparent->color = Color::RED;
			node_parent->color = Color::BLACK;
			uncle->color = Color::BLACK;
			SolveRedConflict(grandparent);
			return;
		}
		if (node_parent == grandparent->left) {
			if (node == node_parent->left) {
				RBTreeNode* brother = node_parent->right;
				RBTreeNode* ggparent = grandparent->parent;
				node_parent->right = grandparent;
				grandparent->parent = node_parent;
				grandparent->left = brother;
				brother->parent = grandparent;
				node_parent->color = Color::BLACK;
				grandparent->color = Color::RED;
				MoveUpperNode(grandparent, node_parent, ggparent);
				return;
			}
			else {
				RBTreeNode* son = node->left;
				RBTreeNode* daughter = node->right;
				RBTreeNode* ggparent = grandparent->parent;
				node->left = node_parent;
				node_parent->parent = node;
				node->right = grandparent;
				grandparent->parent = node;
				MoveUpperNode(grandparent, node, ggparent);
				node_parent->right = son;
				son->parent = node_parent;
				grandparent->left = daughter;
				daughter->parent = grandparent;
				node->color = Color::BLACK;
				grandparent->color = Color::RED;
				return;
			}
		}
		else {
			if (node == node_parent->right) {
				RBTreeNode* ggparent = grandparent->parent;
				RBTreeNode* brother = node_parent->left;
				node_parent->left = grandparent;
				grandparent->parent = node_parent;
				MoveUpperNode(grandparent, node_parent, ggparent);
				grandparent->right = brother;
				brother->parent = grandparent;
				node_parent->color = Color::BLACK;
				grandparent->color = Color::RED;
				return;
			}
			else {
				RBTreeNode* ggparent = grandparent->parent;
				RBTreeNode* son = node->left;
				RBTreeNode* daughter = node->right;
				node->left = grandparent;
				grandparent->parent = node;
				node->right = node_parent;
				node_parent->parent = node;
				MoveUpperNode(grandparent, node, ggparent);
				node_parent->left = daughter;
				daughter->parent = node_parent;
				grandparent->right = son;
				son->parent = grandparent;
				node->color = Color::BLACK;
				grandparent->color = Color::RED;
				return;
			}
		}
	}

	void Add(int number) {
		RBTreeNode* node = Find(number);
		if (!node->is_empty) {
			return;
		}
		node->value = number;
		node->color = Color::RED;
		node->is_empty = false;
		node->left = new RBTreeNode();
		node->left->parent = node;
		node->right = new RBTreeNode();
		node->right->parent = node;
		SolveRedConflict(node);
	}

	RBTreeNode* MoveEmptyDownRecursive(RBTreeNode* node) {
		if (!node->left->is_empty) {
			RBTreeNode* node_1 = node;
			node = node->left;
			while (!node->right->is_empty) {
				node = node->right;
			}
			node_1->value = node->value;
			return MoveEmptyDownRecursive(node);
		}
		if (!node->right->is_empty) {
			RBTreeNode* node_2 = node;
			node = node->right;
			while (!node->left->is_empty) {
				node = node->left;
			}
			node_2->value = node->value;
			return MoveEmptyDownRecursive(node);
		}
		return node;
	}

	void ResolveBlackImbalance(RBTreeNode* node) {
		if (node == root) {
			return;
		}
		RBTreeNode* parent = node->parent;
		RBTreeNode* sister;
		if (node == parent->left) {
			sister = parent->right;
		}
		else {
			sister = parent->left;
		}
		if (sister->color == Color::RED) {
			
			if (node == parent->left) {
				RBTreeNode* niece = sister->left;
				if (niece->left->color == Color::RED) {
					RBTreeNode* grandniece = niece->left;
					RBTreeNode* ggniece = grandniece->left;
					RBTreeNode* ggnephew = grandniece->right;
					RBTreeNode* grandparent = parent->parent;
					parent->right = ggniece;
					ggniece->parent = parent;
					parent->parent = grandniece;
					grandniece->left = parent;
					grandniece->right = niece;
					niece->parent = grandniece;
					grandniece->parent = sister;
					sister->left = grandniece;
					niece->left = ggnephew;
					ggnephew->parent = niece;
					MoveUpperNode(parent, sister, grandparent);
					sister->color = Color::BLACK;
					return;
				}
				else if (niece->right->color == Color::RED) {
					RBTreeNode* grandnephew = niece->right;
					RBTreeNode* grandparent = parent->parent;
					RBTreeNode* grandniece = niece->left;
					parent->right = grandniece;
					grandniece->parent = parent;
					parent->parent = niece;
					niece->left = parent;
					MoveUpperNode(parent, sister, grandparent);
					sister->color = Color::BLACK;
					niece->color = Color::RED;
					grandnephew->color = Color::BLACK;
					return;
				}
				else {
					RBTreeNode* grandparent = parent->parent;
					parent->right = niece;
					niece->parent = parent;
					parent->parent = sister;
					sister->left = parent;
					MoveUpperNode(parent, sister, grandparent);
					sister->color = Color::BLACK;
					niece->color = Color::RED;
					return;
				}
			}
			else {
				RBTreeNode* niece = sister->right;
				if (niece->right->color == Color::RED) {
					RBTreeNode* grandniece = niece->right;
					RBTreeNode* ggniece = grandniece->right;
					RBTreeNode* ggnephew = grandniece->left;
					RBTreeNode* grandparent = parent->parent;
					parent->left = ggniece;
					ggniece->parent = parent;
					parent->parent = grandniece;
					grandniece->right = parent;
					grandniece->left = niece;
					niece->parent = grandniece;
					grandniece->parent = sister;
					sister->right = grandniece;
					niece->right = ggnephew;
					ggnephew->parent = niece;
					MoveUpperNode(parent, sister, grandparent);
					sister->color = Color::BLACK;
					return;
				}
				else if (niece->left->color == Color::RED) {
					RBTreeNode* grandnephew = niece->left;
					RBTreeNode* grandparent = parent->parent;
					RBTreeNode* grandniece = niece->right;
					parent->left = grandniece;
					grandniece->parent = parent;
					parent->parent = niece;
					niece->right = parent;
					MoveUpperNode(parent, sister, grandparent);
					sister->color = Color::BLACK;
					niece->color = Color::RED;
					grandnephew->color = Color::BLACK;
					return;
				}
				else {
					RBTreeNode* grandparent = parent->parent;
					parent->left = niece;
					niece->parent = parent;
					parent->parent = sister;
					sister->right = parent;
					MoveUpperNode(parent, sister, grandparent);
					sister->color = Color::BLACK;
					niece->color = Color::RED;
					return;
				}
			}
		}
		else {
			if (node == parent->left) {
				if (sister->left->color == Color::RED) {
					RBTreeNode* niece = sister->left;
					RBTreeNode* grandniece = niece->left;
					RBTreeNode* grandnephew = niece->right;
					RBTreeNode* grandparent = parent->parent;
					parent->right = grandniece;
					grandniece->parent = parent;
					parent->parent = niece;
					niece->left = parent;
					sister->left = grandnephew;
					grandnephew->parent = sister;
					sister->parent = niece;
					niece->right = sister;
					MoveUpperNode(parent, niece, grandparent);
					niece->color = parent->color;
					parent->color = Color::BLACK;
					return;
				}
				else if (sister->right->color == Color::RED) {
					RBTreeNode* niece = sister->left;
					RBTreeNode* nephew = sister->right;
					RBTreeNode* grandparent = parent->parent;
					parent->right = niece;
					niece->parent = parent;
					parent->parent = sister;
					sister->left = parent;
					MoveUpperNode(parent, sister, grandparent);
					sister->color = parent->color;
					parent->color = Color::BLACK;
					nephew->color = Color::BLACK;
				}
				else {
					if (parent->color == Color::RED) {
						parent->color = Color::BLACK;
						sister->color = Color::RED;
					}
					else {
						sister->color = Color::RED;
						ResolveBlackImbalance(parent);
					}
				}
			}
			else {
				if (sister->right->color == Color::RED) {
					RBTreeNode* niece = sister->right;
					RBTreeNode* grandniece = niece->right;
					RBTreeNode* grandnephew = niece->left;
					RBTreeNode* grandparent = parent->parent;
					parent->left = grandniece;
					grandniece->parent = parent;
					parent->parent = niece;
					niece->right = parent;
					sister->right = grandnephew;
					grandnephew->parent = sister;
					sister->parent = niece;
					niece->left = sister;
					MoveUpperNode(parent, niece, grandparent);
					niece->color = parent->color;
					parent->color = Color::BLACK;
					return;
				}
				else if (sister->left->color == Color::RED) {
					RBTreeNode* niece = sister->right;
					RBTreeNode* nephew = sister->left;
					RBTreeNode* grandparent = parent->parent;
					parent->left = niece;
					niece->parent = parent;
					parent->parent = sister;
					sister->right = parent;
					MoveUpperNode(parent, sister, grandparent);
					sister->color = parent->color;
					parent->color = Color::BLACK;
					nephew->color = Color::BLACK;
				}
				else {
					if (parent->color == Color::RED) {
						parent->color = Color::BLACK;
						sister->color = Color::RED;
					}
					else {
						sister->color = Color::RED;
						ResolveBlackImbalance(parent);
					}
				}
			}

		}
	}

	void Remove(int number) {
		RBTreeNode* node = Find(number);
		if (node->is_empty) {
			return;
		}
	    node = MoveEmptyDownRecursive(node);
		if (node->color == Color::RED) {
			node->is_empty = true;
			node->color = Color::BLACK;
			delete node->left;
			delete node->right;
			return;
		}
		node->is_empty = true;
		delete node->left;
		delete node->right;
		ResolveBlackImbalance(node);
	}

	RBTreeNode* Find(int number) {
		RBTreeNode* node = root;
		while (!node->is_empty && number != node->value) {
			if (number < node->value) {
				node = node->left;
			}
			else {
				node = node->right;
			}
		}
		return node;
	}

	bool IsThereNumber(int number) {
		RBTreeNode* node = root;
		while (!node->is_empty && number != node->value) {
			if (number < node->value) {
				node = node->left;
			}
			else {
				node = node->right;
			}
		}
		return !node->is_empty;
	}

	void PreOrderOutputTree(RBTreeNode* node, int spaces_count) {
		if (node->is_empty) {
			return;
		}
		for (int i = 0; i < spaces_count; ++i) {
			std::cout << " ";
		}
		std::cout << node->value << std::endl;
		PreOrderOutputTree(node->left, spaces_count + 2);
		PreOrderOutputTree(node->right, spaces_count + 2);
	}

	void OutputTree() {
		PreOrderOutputTree(root, 0);
	}
private:
	RBTreeNode* root;
};

void CheckSetMatchesTree(const std::set<int>& some_set, const RBTree& tree) {
	auto set_it = some_set.begin();
	RBTreeIterator it = tree.begin();
	while (set_it != some_set.end() && it != tree.end()) {
		assert(*set_it == *it);
		++set_it;
		++it;
	}
	assert(set_it == some_set.end());
	assert(it == tree.end());
}

void TestRBTree(size_t size_of_tree) {
	int size = rand() % size_of_tree + 1;
	std::set<int> random_set;
	RBTree tested_tree;
	for (int j = 0; j < size; ++j) {
		int number = rand() % 100000;
		random_set.insert(number);
		tested_tree.Add(number);
	}
	CheckSetMatchesTree(random_set, tested_tree);
	std::vector<int> random_vector(random_set.begin(), random_set.end());
	std::random_shuffle(random_vector.begin(), random_vector.end());
	int how_many_to_remove = rand() % random_vector.size();
	for (int j = 0; j < how_many_to_remove; ++j) {
		int number = random_vector.back();
		random_vector.pop_back();
		random_set.erase(number);
		tested_tree.Remove(number);
	}
	CheckSetMatchesTree(random_set, tested_tree);
	std::cout << "OK\n";
}

int main() {
	RBTree tree;
	for (int i = 0; i < 1000; ++i) {
		TestRBTree(1000);
	}
	for (int i = 0; i < 100; ++i) {
		TestRBTree(10000);
	}
	return 0;
}