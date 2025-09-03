#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>
#include <iostream>

class bigint {
	private:
		std::string digits;
	public:
		bigint();
		bigint(unsigned int n);
		// bigint(const bigint& other);

		friend std::ostream& operator<<(std::ostream& os, const bigint& n);

		bigint operator>>(unsigned int n) const;
		bigint& operator>>=(unsigned int n);

		bigint operator<<(unsigned int n) const;
		bigint& operator<<=(unsigned int n);

		bool operator>(const bigint& other) const;
		bool operator>=(const bigint& other) const;
		bool operator<(const bigint& other) const;
		bool operator<=(const bigint& other) const;

		bool operator==(const bigint& other) const;
		bool operator!=(const bigint& other) const;

		bigint operator+(const bigint& other) const;
		bigint& operator+=(const bigint& other);
		bigint operator++();
		bigint& operator++(int); // why not int n?
};

#endif
