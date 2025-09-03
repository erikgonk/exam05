#include "set.hpp"

set::set(searchable_bag& ref) : ref_bag(ref) {}

void    set::insert(int value) {
    if (!ref_bag.has(value)) {
        ref_bag.insert(value);
    }
}

void    set::insert(int* value, int count) {
    for (int i = 0; i < count; i++) {
        if (!ref_bag.has(value[i])) {
            ref_bag.insert(value[i]);
    }
    }
}

bool    set::has(int value) const {
    return (ref_bag.has(value));
}

void    set::print() const {
    ref_bag.print();
}

void    set::clear() {
    ref_bag.clear();
}

const searchable_bag& set::get_bag() const {
    return ref_bag;
} 

