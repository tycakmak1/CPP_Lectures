#include <iostream>
using std::cout, std::cin, std::endl;

class MyClass{
public:
	MyClass(){
		cout << "default ctor, this = " << this << '\n';
	}
	~MyClass(){
		cout << "destructor,   this = " << this << '\n';
	}
};

MyClass g1;
MyClass g2;
MyClass g3;

void foo(){
	cout << "foo starts here\n";
	static MyClass l1;
	cout << "foo is ending\n";
	return;
}
class yas{
public:
	yas() : data_{ 1 }, temp1_{ 5 }, temp2_(4){
		//..
	}
	int data_, temp1_, temp2_;
 };

int main(){
	yas temp;
	cout << temp.data_ << ' ' << temp.temp1_;
	

	cout << "main starts here\n";
	foo();
	foo();
	foo();
	cout << "&g1 = " << &g1 << '\n';
	cout << "&g2 = " << &g2 << '\n';
	cout << "&g3 = " << &g3 << '\n';
	cout << "main is ending\n";
	return 0;
}

MyClass g4;
