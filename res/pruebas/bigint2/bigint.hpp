#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>

class bigint {
    std::string digits;
    public:
        bigint();
        bigint(unsigned int n);
        bigint(bigint& b);

        friend std::iostream& operator<<(std::ostream& os, const bigint& b);
        
        bigint operator+(const bigint& b) const;
        bigint operator+=(const bigint& b) const;
        bigint operator++();
        bigint operator++(int n);

        bigint operator!=(const bigint& b) const;
        bigint operator==(const bigint& b) const;

        bigint operator<<(const bigint& b) const;
        bigint operator<<=(const bigint& b) const;
        bigint operator>>(const bigint& b) const;
        bigint operator>>=(const bigint& b) const;

        bigint operator<(const bigint& b) const;
        bigint operator>(const bigint& b) const;
        bigint operator<=(const bigint& b) const;
        bigint operator>=(const bigint& b) const;

};

#endif