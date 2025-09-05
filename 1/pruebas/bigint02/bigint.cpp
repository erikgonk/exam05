#include "bigint.hpp"

bigint::bigint() {
	digits = '0';
}

bigint::bigint(unsigned int n) {
	if (n == 0) {
		digits = '0';
		return ;
	}
	while (n > 0) {
		digits = digits + static_cast<char>((n % 10) + '0');
		n /= 10;
	}
}

std::ostream& operator<<(std::ostream& os, const bigint& other) {
	int i = other.digits.length() - 1;
	while (i >= 0) {
		os << other.digits[i];
		i--;
	}
	return os;
}

bigint bigint::operator>>(unsigned int n) const {
	bigint res = *this;
	res.digits.insert(0, n, '0');
	return res;
}

bigint& bigint::operator>>=(unsigned int n) {
	digits.insert(0, n, '0');
	return *this;
}

bigint bigint::operator<<(unsigned int n) const {
	bigint res = *this;
	if (n >= res.digits.size()) {
		res.digits = '0';
	} else {
		res.digits.erase(0, n);
	}
	return res;
}

bigint& bigint::operator<<=(unsigned int n) {
	if (n >= digits.size()) {
		digits = '0';
	} else {
		digits.erase(0, n);
	}
	return *this;
}

bool bigint::operator>(const bigint& other) const {
	if (digits.length() != other.digits.length())
		return (digits.length() > other.digits.length());
	for (int i = digits.length() - 1; i >= 0; i--) {
		if (digits[i] != other.digits[i])
			return (digits[i] > other.digits[i]);
	}
	return false;
}

bool bigint::operator>=(const bigint& other) const {
	if (digits.length() != other.digits.length())
		return (digits.length() > other.digits.length());
	for (int i = digits.length() - 1; i >= 0; i--) {
		if (digits[i] != other.digits[i])
			return (digits[i] > other.digits[i]);
	}
	return true;
}

bool bigint::operator<(const bigint& other) const {
	return (*this > other);
}

bool bigint::operator<=(const bigint& other) const {
	return !(*this >= other);
}

bool bigint::operator==(const bigint& other) const {
	return digits == other.digits;
}

bool bigint::operator!=(const bigint& other) const {
	return digits != other.digits;
}


bigint bigint::operator+(const bigint& other) const {
	bigint res;
	res.digits.clear();

	int carry = 0;
	size_t i = 0;
	while (i < digits.size() || i < other.digits.size() || carry != 0) {
		int digit1 = (i < digits.size()) ? digits[i] - '0' : 0;
		int digit2 = (i < other.digits.size()) ? other.digits[i] - '0' : 0;

		int sum = digit1 + digit2 + carry;
		res.digits += (sum % 10) + '0';
		carry = sum / 10;
		i++;
	}
	return res;
}

bigint& bigint::operator+=(const bigint& other) {
	*this = *this + other;
	return *this;
}

bigint bigint::operator++() {
	bigint res = *this;
	++(*this);
	return res;
}

bigint& bigint::operator++(int) {
	*this = *this + bigint(1);
	return *this;
} // why not int n?
