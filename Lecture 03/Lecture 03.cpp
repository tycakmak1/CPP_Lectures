//Lecture 03
#include <iostream>
using std::cout, std::cin, std::endl;
struct point {
	double x, y;
};

std::ostream& operator<<(std::ostream& out, const point p){
	return ((p.y == 0) ? (out << p.x << " +i" << p.y) : ((p.y < 0) ? (out << p.x << " -i" << -p.y) : (out << p.x << " +i" << p.y)));
}
point times(point p){
	return {p.x * 2, p.y * 2};
}
int main(){
	int x{10};
	if(int num{x}; ++num == 11)// same as if(int num{x}; num++, num == 11)
		cout << "suck it" << " num = " << num << "\n";
	int y = x++;
	cout << "x " << x << " y " << y << "\n";

	unsigned int z = 15;
	cout << "z " << z << "\n";

	int a[5] = {1, 2, 3};
	int* p_a = a;
	auto t = sizeof p_a++;
	cout << "x " << t << " *p_a " << *p_a << "\n";
	point p1{3, 4};
	cout << p1 << "\n";
	int temp{}, * ptr_temp = &temp;
	if(p1 = {5, 12}, x != 10){
		cout << x << "\n";
		cout << p1 << "\n";
	}
	return 0;
}