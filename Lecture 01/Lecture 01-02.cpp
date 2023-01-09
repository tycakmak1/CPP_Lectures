//Lecture 01-02
#include <iostream>

template<typename T>
struct ValCat{
	static constexpr const char* p = "PR value";
};

template<typename T>
struct ValCat<T&>{
	static constexpr const char* p = "L value";
};

template<typename T>
struct ValCat<T&&>{
	static constexpr const char* p = "X value";
};

#define print_val_cat(expr) std::cout << "Value category of '" #expr "' is " << ValCat<decltype(expr)>::p << std::endl;

int& foo(){
	int temp{5};
	return temp;
}

int bar(){
	return 1;
}

int main(){
	int x{5};
	int* ptr_x{&x};
	std::cout << "ptr_x " << ptr_x << std::endl
		<< "*ptr_x " << *ptr_x << std::endl;
	int& ref_x{x};
	ref_x++;
	std::cout << "x " << x << std::endl;
	std::cout << "ref_x " << ref_x << std::endl;
	print_val_cat(*ptr_x);
	print_val_cat(ptr_x);
	print_val_cat(x);
	print_val_cat(++x);
	print_val_cat(foo());
	print_val_cat(bar());
	int a1;		//default initialization, a1 has (indeterminate)garbage value
	int a2 = 10;	//copy initialization
	int a3(5);	//direct initialization
	int a4{45};	//brace initialization, generally known as uniform or list initialization
	int a5{};	//value initialization
	std::cout << "a2 " << a2 << std::endl
		<< "a3 " << a3 << std::endl
		<< "a4 " << a4 << std::endl;
	int arr_a[5]{};
	for(int i{0}; i < 5; ++i)
		std::cout << "a[" << i << "] = " << arr_a[i] << std::endl;
	auto* temp = &x;
	std::cout << "temp " << temp << std::endl
		<< "x " << x << std::endl
		<< "*temp " << *temp << std::endl;
	bool flag{};	//flag = false
	std::cout << std::boolalpha << flag << std::endl;
	int* ptr3_x = (int*)flag;	//implicit typecasting from bool to pointer
	if(ptr3_x == nullptr)
		std::cout << ptr3_x << " ";
	return 0;
}