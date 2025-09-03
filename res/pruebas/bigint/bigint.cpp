#include "./bigint.hpp"

bigint::bigint() {
	digits = "0";
}

bigint::bigint(const bigint& other) {
	digits = other.digits;
}

bigint::bigint(unsigned int n) {
	if (n == 0) {
		digits = "0";
		return ;
	}
	while (n > 0) {
		digits = digits + static_cast<char>((n % 10) + '0');
		n /= 10;
	}
}

std::ostream& operator<<(std::ostream& os, const bigint& n) {
	int i = n.digits.length() - 1;
	while (i >= 0) {
		os << n.digits[i];
		i--;
	}
	// os << digits;
	return os;
}

bigint& bigint::operator++(int) {
	*this = *this + bigint(1);
	return *this;
}

bigint bigint::operator+(const bigint& other) const {
	bigint res;
	res.digits.clear();
	
	size_t i = 0;
	int carry = 0;
	
	while (i < digits.size() || i < other.digits.size() || carry != 0) {
		int digits1 = (i < digits.size()) ? digits[i] - '0' : 0;
		int digits2 = (i < other.digits.size()) ? other.digits[i] - '0' : 0;
		
		int sum = digits1 + digits2 + carry;
		res.digits += (sum % 10) + '0';
		carry = sum / 10; 
		i++;
	}
	return res;
}

bigint bigint::operator<<(int n) {
	bigint res = *this;
	res.digits.insert(0, n, '0');
	return res;
}

bigint& bigint::operator<<=(int n) {
	digits.insert(0, n, '0');
	return *this;
}

bigint bigint::operator>>(int n) {
	bigint res = *this;
	if (n > res.digits.size()) {
		res.digits = '0';
	} else {
		res.digits.erase(0, n);
	}
	return res;
}

bigint& bigint::operator>>=(int n) {
	if (n > digits.size()) {
		digits = '0';
	} else {
		digits.erase(0, n);
	}
	return *this;
}

bool bigint::operator<(const bigint& other) {
	if (digits.size() != other.digits.size())
		return digits.size() < other.digits.size();
	for (int i = digits.size() - 1; i >= 0;  i--) {
		if (digits[i] != other.digits[i])
			return digits[i] < other.digits[i];
	}
	return false;
}