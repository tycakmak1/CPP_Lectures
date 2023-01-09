//Lecture 07
#include <iostream>
using std::cout, std::cin, std::endl;
enum class Pos{on, off, hold};

char* mystrchr(const char* p, int c){
	while(*p){
		if(*p == c){
			return const_cast<char*>(p);
		}
		++p;
	}
	if(c == '\0')
		return const_cast<char*>(p);
	return nullptr;
}

int fib(int a, int b){
	cout << a << ' ' << b << '\n';
	return 1;
}

void f(int* a){
	cout << "int*\n";
	return;
}

void f(const int* a){
	cout << "const int*\n";
	return;
}
void f(int& a){
	cout << "int&\n";
	return;
}

void f(const int& a){
	cout << "const int&\n";
	return;
}
int main(){
	int num = 5;
	const int* cp_num = &num;
	int* p_num = &num;
	int& r_num = num;
	const int& cr_num = num;
	f(cp_num);
	f(p_num);
	f(cr_num);
	f(r_num);

	void(*ptr1_f)(int*) = &f;
	void(*ptr2_f)(const int*) = &f;
	cout << ptr1_f << '\n'
		<< ptr2_f << '\n';
	int(*ptr_fib1)(int, int) = fib;			//pointer to function
	int(*ptr_fib2)(int, int) = &fib;		//pointer to function
	int(&ref_fib1)(int, int) = fib;			//reference to function
	int(&ref_fib2)(int, int) = *ptr_fib1;		//reference to function
	int(*&ref_fib3)(int, int) = ptr_fib1;		//reference to pointer to function
	int(**ref_ref_fib1)(int, int) = &ptr_fib1;	//pointer to pointer to function

	cout << "(*ptr_fib)(3, 5) ";
	(*ptr_fib1)(3, 5);
	cout << "ptr_fib(3, 5) ";
	ptr_fib1(3, 5);
	cout << "ref_fib(3, 5) ";
	ref_fib1(3, 5);
	cout << "(*ptr_fib)(3, 5) ";
	(*ptr_fib1)(3, 5);
	int (*a[2])(int, int){ptr_fib2, ptr_fib1};
	for(int i{}; i < 2; i++)
		cout << "a[" << i << "] = " << a[i] << '\n';
	int ret = (ref_fib2)(3, 5);
	cout << "ret " << ret << '\n';





	int x = 10;
	int y = 3;
	double dval1 = static_cast<double>(x) / y;
	int ival1 = static_cast<int>(dval1);
	cout << dval1 << "\n";
	cout << ival1 << "\n";

	Pos mypos = Pos::off;
	int ival2 = static_cast<int>(mypos);
	cout << ival2 << "\n";

	char* ptr = reinterpret_cast<char*>(& dval1);
	cout << *ptr << "\n";

	const unsigned int uval{456U};
	int* p = reinterpret_cast<int*>(const_cast<unsigned int*>(&uval));

	return 0;
}