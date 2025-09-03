#ifndef SEARCHABLE_TREE_BAG_HPP
#define SEARCHABLE_TREE_BAG_HPP

#include "searchable_bag.hpp"
#include "tree_bag.hpp"
#include <iostream>

class searchbale_tree_bag: public searchable_bag, public tree_bag {
	bool has(int n) const;
};

#endif
