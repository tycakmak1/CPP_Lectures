#pragma once
#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
class complex{
public:
	complex() : x_{ 0 }, y_{ 0 }{}
	complex(double x, double y) : x_{ x }, y_{ y }{}
	complex(const complex& b) : x_{ b.x_ }, y_{ b.y_ }{}
	void operator=(const complex& z){
		x_ = z.x_;
		y_ = z.y_;
		return;// *this;
	}
	inline complex& operator++(){
		++x_;
		--y_;
		return *this;
	}
	complex operator++(int){
		complex return_val{ *this };
		++* this;
		return return_val;
	}
	complex& operator+=(const complex& z){
		x_ += z.x_;
		y_ += z.y_;
		return *this;
	}
	complex& operator-=(const complex& z){
		x_ -= z.x_;
		y_ -= z.y_;
		return *this;
	}
	void print()const& {
		std::cout << "const&  x = " << x_ << " y = " << y_ << '\n';
		return;
	}
	void print()const&& {
		std::cout << "const&& x = " << x_ << " y = " << y_ << '\n';
		return;
	}
	friend std::ostream& operator<<(std::ostream& out, const complex& z){			// usually called inserter
		return out << "z = (" << z.x_ << ", " << z.y_ << ")\n";
	}
	friend std::istream& operator>>(std::istream& in, complex& z){				// usually called extractor
		//.. code goes here
		return in >> z.x_ >> z.y_;
	}
	friend complex operator*(const complex&, const complex&);
private:
	double x_, y_;
};
complex operator-(const complex&, const complex&);
complex operator+(const complex&, const complex&);
#endif