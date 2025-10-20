#include "bigint.hpp"

bigint::bigint(){
    digits = "0";
}

bigint::bigint(unsigned int n){
    if (n == 0) {
        digits = "0";
        return;
    }
    while (n > 0) {
        char x = ('0' + (n%10));
        digits = digits + x;
        n = n/10;
    }
}

std::ostream& operator<<(std::ostream& os, const bigint& n){
    int i = n.digits.length() - 1;

    while(i >= 0) {
        os << n.digits[i]; 
        i--;
    }
    return os;
}


bigint::bigint(const bigint& other) {
    digits = other.digits;
}

// bigint bigint::operator+(const bigint& other) const{
//     bigint result;
//     result.digits.clear();

//     int carry = 0;
//     size_t i = 0;

//     while(i < digits.size() || i < other.digits.size() || carry != 0) {
//         int digit1 = (i < digits.size()) ? digits[i] - '0' : 0;
//         int digit2 = (i < other.digits.size()) ? other.digits[i] - '0' : 0;

//         int sum = digit1 + digit2 + carry;
//         result.digits += (sum % 10) + '0';
//         carry = sum / 10;
//         i++;
//     }
//     return result;
// }

#include <sstream>

int sumInt(std::string s) {
	std::stringstream str(s);
	unsigned int res;
	str >> res;
	return res;

}

bigint& bigint::operator+=(const bigint& other){
    *this = *this + other; // add this number with 'other' and assign the result to this object
    return *this; // return the reference to this object to allow chained calls
}

bigint bigint::operator<<(unsigned int n) const{
    bigint result = *this;
    result.digits.insert(0, n, '0');
    return result;
}

bigint bigint::operator+(const bigint& other) const{
	bigint res;
	res.digits.clear();

	int i = 0;
	int carry = 0;

	while (carry > 0 || i < digits[i] || i < other.digits.size()) {
		int d1 = (i < digits.size()) ? digits[i] - '0' : 0;
		int d2 = (i < other.digits.size()) ? other.digits[i] - '0' : 0;
		
		int sum = carry + d1 + d2;
		res.digits += (sum%10) + '0';
		carry = sum / 10;
		i++;
	}
	return res;
}

bigint& bigint::operator<<=(unsigned int n){
    digits.insert(0, n, '0');
    return *this;
}

bigint& bigint::operator++(){
    *this = *this + bigint(1);
    return *this;
}
bigint bigint::operator++(int){
    bigint temp = *this;
    ++(*this);
    return temp;
}

bigint bigint::operator>>(unsigned int n) const{
    bigint result = *this;
    if (n >= result.digits.size()) {
        result.digits = "0";
    } else {
        result.digits.erase(0, n);
    }
    return result;
}

bigint& bigint::operator>>=(unsigned int n){
    if (n >= digits.size()) {
        digits = "0";
    } else {
        digits.erase(0, n);
    }
    return *this;
}

bool bigint::operator==(const bigint& other) const{
    return this->digits == other.digits;
}
bool bigint::operator!=(const bigint& other) const{
    return !(this->digits == other.digits);
}

bool bigint::operator<(const bigint& other) const{
    if (this->digits.size() != other.digits.size()){
        return this->digits.size() < other.digits.size();
    }
    for (int i = digits.size() - 1; i >= 0; --i){
        if (digits[i] != other.digits[i])
            return digits[i] < other.digits[i];
    }
    return false; // =
}

bool bigint::operator<=(const bigint& other) const{
    if (this->digits.size() != other.digits.size()){
        return this->digits.size() < other.digits.size();
    }
    for (int i = digits.size() - 1; i >= 0; --i){
        if (digits[i] != other.digits[i])
            return digits[i] < other.digits[i];
    }
    return true; // =
}
bool bigint::operator>(const bigint& other) const{
    return other < *this;
}
bool bigint::operator>=(const bigint& other) const{
    return !(*this <= other);
}
