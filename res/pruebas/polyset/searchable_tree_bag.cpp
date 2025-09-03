#include "searchable_tree_bag.hpp"

bool searchable_bag::has(int n) const {
	node *node = tree;
	while (node != NULL) {
		if (node->value > n)
			node = node->r;
		else if (node->value > n)
			node = node->l;
		else 
			return true;
	}
	return false;
}
