// #pragma once

// #include "array_bag.hpp"
// #include "searchable_bag.hpp"

// class searchable_array_bag : public array_bag, public searchable_bag {
//     public:
//         bool has(int value) const;
// };


#ifndef SEARCHABLE_ARRAY_BAG_HPP
#define SEARCHABLE_ARRAY_BAG_HPP

#include "searchable_bag.hpp"
#include "array_bag.hpp"

#include <iostream>
#include <string>

class searchable_array_bag : public searchable_bag, public array_bag {
    public:
        // searchable_array_bag() : array_bag() {}
        // searchable_array_bag(const searchable_array_bag& other) : array_bag(other) {}
        // searchable_array_bag& operator=(const searchable_array_bag& other) {
        //     if (this != &other) array_bag::operator=(other);
        //     return *this;
        // }
        bool    has(int n) const;
};
#endif