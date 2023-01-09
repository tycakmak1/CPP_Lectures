//Lecture 06
#include <iostream>
using std::cout, std::cin, std::endl;

enum class nec{
	red,
	black,
	yellow
};

int main(){

	int x1 = -5;
	unsigned short x2 = x1;
	cout << x1 << ' ' << x2;
	return 0;
}