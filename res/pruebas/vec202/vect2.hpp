#ifndef VECT2_HPP
#define VECT2_HPP

#include <string>
#include <iostream>

class vect2 {
	private:
		int x;
		int y;
	public:
		vect2();
		vect2(int x, int y);
		
		friend std::ostream& operator<<(std::ostream& os, const vect2& n);

		int operator[](int pos) const;
		int& operator[](int pos);

		vect2 operator++(int);
		vect2& operator++();
		vect2& operator+=(const vect2& other);

		vect2 operator--(int);
		vect2& operator--();
		vect2& operator-=(const vect2& other);

		vect2 operator*(int n) const;
		vect2 operator*(const vect2& other) const;
		vect2& operator*=(int n);

		vect2 operator+(const vect2& other) const;
		vect2 operator-(const vect2& other) const;
};

vect2 operator*(int n, const vect2& other);

#endif
