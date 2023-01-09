#include <iostream>
#include <vector>
using std::cout, std::cin, std::endl, std::vector;

class Myclass{
public:
	friend int get_mx();
	friend int get_mx(Myclass x){
		return x.mx;
	}
	void print()const&{
		cout << "mx = " << mx << " my = " << my << " x_ = " << x_ << " this = " << this << '\n';
	}
	Myclass(int x, int y) : mx{ x }, my{ y }{}
	static int x_;
	static int foo(){
		return 777;
	}
private:
	//int mx;
	int mx, my;
};
int get_mx(){
	Myclass x{ 3, 5 };
	return x.mx;
}

int foo(){
	return 5;
}

int Myclass::x_ = foo();

class Complex{
	Complex(double x, double y){
		cout << "Complex cartesian\n";
	}
	Complex(double angle, double distance, int){
		cout << "Complex polar\n";
	}
public:
	static Complex create_cartesian(double x, double y){
		return Complex(x, y);
	}
	static Complex create_polar(double angle, double distance){
		return Complex(angle, distance, 0);
	}
};

class A;
class B{
	friend class A;
};

int main(){
	Myclass m1{ 10, 20 };
	Myclass m2{ 11, 21 };
	m1.print();
	Myclass::x_ = ::foo();
	m1.print();
	Myclass::x_ = 7;
	m1.print();
	m2.print();
	cout << "x_ changed to 19\n";
	Myclass::x_ = 19;
	m1.print();
	m2.print();
	int temp = -123;
	cout << temp % 10 << '\n';

	Complex::create_cartesian(3.5, 5.3);
	Complex::create_polar(3.5, 5.3);



	return 0;
}