 #include "searchable_tree_bag.hpp"

bool searchable_tree_bag::has(int n) const {
	node *node = tree;
	while (node != NULL) {
		if (node->value < n)
			node = node.l;
		else if (node->value > n)
			node = node.r;
		else
			return true;
	}
	return false;
}
