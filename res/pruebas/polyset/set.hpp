#ifndef SET_HPP
#define SET_HPP

#include <string>
#include <iostream>

#include "searchable_bag.hpp"

class set: public searchable_bag {
    private:
        searchable_bag& ref_bag;
    public:
        set(searchable_bag& ref);

        void insert(int value);
        void insert(int *array, int size);

        bool has(int value) const;

        void print() const;
        void clear();

        const searchable_bag& get_bag() const; 
};

#endif