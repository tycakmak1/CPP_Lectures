#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "complex.h"
using std::cout, std::cin, std::endl;

class myclass{
public:
	myclass() = default;
	myclass(const myclass& b) : x{ b.x }, y{ b.y }{
		cout << "copy ctor called\n";
	}
	myclass(int x, int y) : x{ x }, y{ y }{}
	myclass operator+(const myclass& b)const& {
		cout << "inside the myclass::operator+\n";
		return { x + b.x, y + b.y };
	}
	myclass& operator=(const myclass& b){
		cout << "inside the myclass::operator=\n";
		x = b.x;
		y = b.y;
		return *this;
	}
	void print()const& {
		cout << "const&  x = " << this->x << " y = " << this->y << '\n';
		return;
	}
	void print()const&& {
		cout << "const&& x = " << this->x << " y = " << this->y << '\n';
		return;
	}
private:
	int x, y;
};


int main(){
	cout << "Hello World!\n";
	myclass m1{ 1, 2 }, m2{ 3, 4 };
	m1 + m2;
	m1.print();
	myclass{ 3, 5 }.print();
	myclass{ 3, 5 };
	complex c1{ 4, 5 }, c2{ 1, 1 };
	complex c3{ c1 + c2 };
	c3.print();
	(c1 + c2).print();
	(c1 * c2).print();
	operator<<(cout.operator<<(5), '\n');
	//cout << c3 << '\n';
	cout << "c3 = " << c3 << "\n++c3 = " << ++c3 << "\nc3++ = " << c3++;
	operator<<(cout, c3);
	complex c4 = c3++;
	operator<<(cout, c4);
	operator<<(cout, c3);

	std::vector<std::string> svec = { "john", "jack", "jane" };
	auto iter1 = svec.begin();
	std::vector<std::string>::iterator iter2 = svec.begin() + 1;
	cout << *iter1 << ' ' << *iter2 << ' ' << iter2->size() << '\n';
	int a[5]{ 0, 1, 2, 3, 4 };
	std::array<int, 5> b{ 0,1,2,3,4 };

	return 0;
}