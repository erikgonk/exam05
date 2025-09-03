#ifndef SET_HPP 
#define SET_HPP 

#include "searchable_bag.hpp"

class set {
	private:
		searchable_bag& bag_ref;
	public:
		set(searchable_bag& b);

		void insert(int n);
		void insert(int *n, int size);
		void print() const;
		void clear();
		bool has(int n) const;
		
		const searchable_bag& get_bag() const;
};

#endif
