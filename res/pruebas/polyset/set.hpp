#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include <string>

#include "searchable_bag.hpp"

class set {
	private:
		searchable_bag& bag_ref();
	public:
		set(searchable_bag& bag_ref);
		void insert(int);
		void insert(int *, int);
		void print() const;
		void clear();

		bool has(int n) const;
		const searchable_bag& get_bag() const;
};
#endif
