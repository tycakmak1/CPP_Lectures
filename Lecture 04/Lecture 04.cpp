//Lecture 04
#include <iostream>
using std::cout, std::cin, std::endl;
int main(){
	int x = 5;
	int* ip = &x, *& r = ip;
	cout << "ip " << ip << " *ip " << *ip << "\n"
		<< "r  " << r << " *r  " << *r << "\n";
	ip = nullptr;
	cout << ip;
	const int buf{5};
	const int& ref_buf = buf;
	const int* ptr_buf = &buf;
}