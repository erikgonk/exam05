#include "set.hpp" 

set::set(searchable_bag& b) : bag_ref(b) {}

void set::insert(int n) {
	if (!bag_ref.has(n))
		bag_ref.insert(n);
}

void set::insert(int *n, int size) {
	for (int i = 0; size > i; i++) {
		if (!bag_ref.has(n[i]))
			insert(n[i]);
	}
}

void set::print() const {
	bag_ref.print();
}

void set::clear() {
	bag_ref.clear();
}

bool set::has(int n) const {
	return (bag_ref.has(n));
}

const searchable_bag& set::get_bag() const {
	return bag_ref;
}
