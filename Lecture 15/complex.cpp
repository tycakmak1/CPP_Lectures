#include "complex.h"
complex operator+(const complex& z1, const complex& z2){
	std::cout << "outside\n";
	return complex{ z1 } += z2;
}
complex operator-(const complex& z1, const complex& z2){
	return complex{ z1 } -= z2;
}
complex operator*(const complex& z1, const complex& z2){
	return {z1.x_ * z2.x_ - z1.y_ * z2.y_, z1.x_ * z2.y_ + z1.y_ * z2.x_};
}