//Lecture 08
#include <iostream>
using std::cout, std::cin, std::endl;
void bar(int&){
	cout << 3;
}
void bar(int&&){
	cout << 4;
}
void foo(int& x){
	cout << 1;
	bar(x);
}
void foo(int&& x){
	cout << 2;
	bar(x);
}
void f(int&& x){
	cout << x << "int&&\n";
}
static void f(int& x){
	cout << x << "int&\n";
}

struct Nec;

Nec* f1(){
	return nullptr;
}

int* f2(){
	return nullptr;
}

int main(){
	Nec*(*p_f1)() = f1;
	int*(*p_f2)() = f2;
	foo(10);
	cout << '\n';
	int x{10};
	foo(x);
	f(x);
	cout << '\n';
	int&& r = 10;
	cout << &r << '\n';
	__cplusplus;
	cout << "x: " << x << '\n';
	cout << sizeof(x *=5) << '\n';
	cout << "x: " << x << '\n';

	int a[5]{0, 1, 2, 3, 4};
	int* p1_a = a;
	int b[5]{};
	int* p1_b = b;
	int n = 5;
	while(n--)
		*p1_b++ = *p1_a++;
	n = 5;
	while(n--)
		cout << "a[" << n << "] = " << *--p1_a << "\tb[" << n << "] = " << *--p1_b << '\n';
	for(int i{0}; i < 5; i++)
		cout << a[i] << ' ' << b[i] << '\n';


	return 0;
}