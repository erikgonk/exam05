// #pragma once

// #include "tree_bag.hpp"
// #include "searchable_bag.hpp"

// class searchable_tree_bag : public tree_bag, public searchable_bag {
// public:

//     bool has(int value) const;
// };

#ifndef SEARCHABLE_TREE_BAG_HPP
#define SEARCHABLE_TREE_BAG_HPP

#include  <string>
#include <iostream>

#include "searchable_bag.hpp"
#include "tree_bag.hpp"

class searchable_tree_bag : public searchable_bag, public tree_bag {
    public:
        // searchable_tree_bag() : tree_bag() {}
        // searchable_tree_bag(const searchable_tree_bag& other) : tree_bag(other) {}
        // searchable_tree_bag& operator=(const searchable_tree_bag& other) {
        //     if (this != &other) tree_bag::operator=(other);
        //     return *this;
        // }
        bool has(int n) const;
};

#endif
