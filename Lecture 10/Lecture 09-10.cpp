//Lecture 09 - 10
#include <iostream>
#include "taha.h"
#include "yasin.h"
#include "cakmak.h"

using std::cout, std::cin, std::endl;
class MyClass{
public:
	int data{};
	void f1(){
		cout << "Hello World!\n";
		return;
	}
};

class car{
	const char* make_;// { "No information given" };
	const char* model_;// { "No information given" };
	int year_;// { -1 };
public:
	car(){
		make_ = "No information given";
		model_ = "No information given";
		year_ = -1;
	}
	car(const char* make, const char* model, int year){
		make_ = make;
		model_ = model;
		year_ = year;
	}
	void set_info(const char* make, const char* model, int year){
		make_ = make;
		model_ = model;
		year_ = year;
	}
	void get_info(){
		cout << "Make  : " << make_
			<< "\nModel : " << model_
			<< "\nYear  : " << year_ << '\n';
	}
	void f1(){
		cout << year_ + 13 << '\n';
	}
};

class ptr{
public:
	ptr* f1(){
		cout << "f1, this = " << this << '\n';
		return this;
	}
	ptr* f2(){
		cout << "f2, this = " << this << '\n';
		return this;
	}
	ptr* f3(){
		cout << "f3, this = " << this << '\n';
		return this;
	}
};

void f1(int x = 5){
	cout << x * x << '\n';
}

void fconst(const int* p){
	cout << "const int*\n";
	return;
}

void fconst(int* p){
	cout << "int*\n";
	return;
}

constexpr int foo(int a, int b){
	return a * a + b * b;
}


int main(){
	int temp = 5;
	fconst(&temp);
	const int* ptv_temp = &temp;
	int temp2 = 6;

	ptr temp_ptr;
	ptr* ptv_temp_tr = &temp_ptr;
	(&temp_ptr)->f1()->f2()->f3();
	ptv_temp_tr->f1()->f2()->f3();
	ptr* (ptr:: * ptf_ptr_f1)() = &ptr::f1;
	ptr* (ptr:: * ptf_ptr_f2)() = &ptr::f2;
	ptr* (ptr:: * ptf_ptr_f3)() = &ptr::f3;
	cout << "ptf_ptr_f1 = " << ptf_ptr_f1 << '\n';
	cout << "ptf_ptr_f2 = " << ptf_ptr_f2 << '\n';
	cout << "ptf_ptr_f3 = " << ptf_ptr_f3 << '\n';
	(((temp_ptr.*ptf_ptr_f1)()->*ptf_ptr_f2)()->*ptf_ptr_f3)();

	void(car:: * ptf_get_info)() = &car::get_info;
	car temp_car1("Audi", "A3 Sportback", 2021);
	(temp_car1.*ptf_get_info)();
	temp_car1.f1();
	car temp_car3;
	(temp_car3.*ptf_get_info)();
	int xx = 5;
	int* ptv_xx = &xx;
	cout << &*ptv_xx << '\n';

	constexpr int x = foo(1, 2);
	const int arr[x]{ 0, 1, 2, 3, 4 };
	const int yy = 5;
	constexpr const int* ptv_yy = &yy;

	cout << "*ptv_yy = " << *ptv_yy << "\nptv_yy = " << ptv_yy << '\n';

	void(*ptf_f1)(int) = f1;
	void(MyClass:: * ptf_f11)() = &MyClass::f1;
	MyClass a{};
	a.data = 5;
	(a.*ptf_f11)();
	MyClass* ptv_a = &a;

	((&a)->*ptf_f11)();
	(ptv_a->*ptf_f11)();
	cout << "\n\n";
	cout << "&func = " << &func << '\n';
	f2();
	f3();
	return 0;
}