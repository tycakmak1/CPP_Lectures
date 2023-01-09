#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>

using std::cout, std::cin, std::endl;

class myclass{
public:
	myclass(){
		x_ = 0;
		y_ = 4;
	}
	void print()const{
		cout << "x = " << x_ << " y = " << y_ << " this = " << this << '\n';
	}
	void set(int x, int y){
		x_ = x;
		y_ = y;
		return;
	}
private:
	int x_{}, y_{};
};

class String{
public:
	String() = default;
	String(const char* p) : mlen{ std::strlen(p) }, mp{ static_cast<char*>(std::malloc(mlen + 1)) }{	// ==> this is shallow copy
		if(!mp)
			throw std::runtime_error{ "can not allocate memory" };
		std::strcpy(mp, p);										// the difference between two copy ctors is in this line, notice the second argument.
	}
	String(const String& other) : mlen{ other.mlen }, mp{ static_cast<char*>(std::malloc(mlen + 1)) }{	// ==> this is deep copy
		if(!mp)
			throw std::runtime_error{ "can not allocate memory" };
		std::strcpy(mp, other.mp);									// the difference between two copy ctors is in this line, notice the second argument.
	}
	String& operator=(const String& other){
		if(this == &other)								// removal of this control mechanism, creates a dangling handle problem caused by self assignment.
												// there is an alternative to this, copy & swap idiom, a topic for later.
			return *this;
		std::free(mp);
		mlen = other.mlen;
		mp = static_cast<char*>(std::malloc(mlen + 1));
		if(!mp)
			throw std::runtime_error{ "can not allocate memory" };
		strcpy(mp, other.mp);
		return *this;
	}
	~String(){
		std::free(mp);
	}
	void print()const{
		cout << "[" << mp << "]\n";
	}
	std::size_t length()const{
		return mlen;
	}
private:
	std::size_t mlen{};
	char* mp{};
};

void func(String s){
	cout << "func called\n";
	s.print();
}

int main(){
	myclass m;
	m.print();
	myclass& rtv_m = m;
	rtv_m.set(7, 24);
	rtv_m.print();
	m.print();
	cout << "\n\n";

	String str{ "hello world!" };
	str.print();
	auto len = str.length();
	cout << "len = " << len << '\n';
	func(str);
	cout << "back to main\n";
	str.print();
	cout << str.length();
	cout << "\n\n";

	String s{ "goodbye world!" };
	s.print();
	s = str;
	s = s;
	str = str;
	s.print();
	str.print();

	return 0;
}
