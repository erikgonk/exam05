#include "vect2.hpp"

vect2::vect2() {
	x = 0;
	y = 0;
}

vect2::vect2(int x, int y) {
	this->x = x;
	this->y = y;
}

std::ostream& operator<<(std::ostream& os, const vect2& n) {
	os << '{' << n[0] << ',' << n[1] << '}';
	return os;
}


int vect2::operator[](int pos) const {
	if (pos == 0)
		return this->x;
	return this->y;
}

int& vect2::operator[](int pos) {
	if (pos == 0)
		return this->x;
	return this->y;
}

vect2& vect2::operator++() {
	this->x += 1;
	this->y += 1;
	return (*this);
}

vect2 vect2::operator++(int) {
	vect2 vec = *this;
	++(*this);
	return vec;
}

vect2& vect2::operator+=(const vect2& other) {
	this->x += other.x;
	this->y += other.y;
	return (*this);
}

vect2 vect2::operator--(int) {
	vect2 vec = *this;
	--(*this);
	return vec;
}

vect2& vect2::operator--() {
	this->x -= 1;
	this->y -= 1;
	return (*this);
}

vect2& vect2::operator-=(const vect2& other) {
	this->x -= other.x;
	this->y -= other.y;
	return (*this);
}

vect2 vect2::operator*(int n) const {
	vect2 res = *this;
	res.x *= n;
	res.y *= n;
	return (res);
}

vect2 vect2::operator*(const vect2& other) const {
	vect2 res = *this;
	res.x *= other.x;
	res.y *= other.y;
	return (res);
}

vect2& vect2::operator*=(int n) {
	x *= n;
	y *= n;
	return (*this);
}

vect2 operator*(int n, const vect2& other) {
	vect2 res = other;
	res *= n;
	return (res);
}

vect2 vect2::operator+(const vect2& other) const {
	vect2 res = *this;
	res.x += other.x;
	res.y += other.y;
	return (res);
}

vect2 vect2::operator-(const vect2& other) const {
	vect2 res = *this;
	res.x -= other.x;
	res.y -= other.y;
	return (res);
}
