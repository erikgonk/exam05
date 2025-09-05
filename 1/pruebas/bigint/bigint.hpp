#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>
#include <iostream>

class bigint {
	private:
		std::string digits;
	
	public:
		bigint(); // default
		bigint(unsigned int n);
		bigint(const bigint& other);
		
		friend std::ostream& operator<<(std::ostream& os, const bigint& n);

		bigint& operator++(int);
		bigint operator+(const bigint& other) const;
		bigint operator<<(int n);
		bigint& operator<<=(int n);
		bigint operator>>(int n);
		bigint& operator>>=(int n);
		bool operator<(const bigint& other);
};

#endif