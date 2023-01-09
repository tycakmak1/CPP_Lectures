#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>

using std::cout, std::cin, std::endl;

class Car{
public:
	Car() : year_{ -1 }, door_number_{ -1 }{
		cout << "default ctor called\n";
	}
	Car(int year, int door_number) : year_{ year }, door_number_{ door_number }{
		cout << "ctor called\n";
	}
	Car(const Car& rhs) : year_{ rhs.year_ }, door_number_{ rhs.door_number_ }{
		cout << "copy constructor is called\n";
		print();
	}
	Car& operator=(const Car& rhs){
		year_ = rhs.year_;
		door_number_ = rhs.door_number_;
		cout << "copy assignment is called\n";
		print();
		return *this;
	}
	Car(Car&& other) : year_{ std::move(other.year_) }, door_number_{ std::move(other.door_number_) }{}
	Car& operator=(Car&& other){
		year_ = std::move(other.year_);
		door_number_ = std::move(other.door_number_);
		cout << "move asssignment is called\n";
		return *this;
	}
	void print(){
		cout << "year = " << year_ << " door number = " << door_number_ << '\n';
	}
private:
	int year_, door_number_;
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
			return *this;								// there is an alternative to this, copy & swap idiom, a topic for later.
		std::free(mp);
		mlen = other.mlen;
		mp = static_cast<char*>(std::malloc(mlen + 1));
		if(!mp)
			throw std::runtime_error{ "can not allocate memory" };
		strcpy(mp, other.mp);
		return *this;
	}
	String(String&& other) : mlen{ std::move(other.mlen) }, mp{ std::move(other.mp) }{			// ==> move ctor
		other.mlen = 0;
		other.mp = nullptr;
	}
	String& operator=(String&& other){									// ==> move assignment
		if(this == &other)
			return *this;
		free(mp);
		mlen = other.mlen;
		mp = other.mp;
		other.mlen = 0;
		other.mp = nullptr;
		return *this;
	}
	~String(){
		if(mp)
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

class Myclass{
public:
	Myclass(){
		//cout << "default ctor this = " << this << '\n';
	}
	Myclass(int a, int b){
		//cout << "a = " << a << " b = " << b << " this = " << this << '\n';
	}
	~Myclass(){
		//cout << "destructor this = " << this << '\n';
	}
	void foo()&{
		cout << "Myclass foo()&       this = " << this << '\n';
	}
	void foo()const&{
		cout << "Myclass foo()const&  this = " << this << '\n';
	}
	void foo()&&{
		cout << "Myclass foo()&&      this = " << this << '\n';
	}
	void foo()const&&{
		cout << "Myclass foo()const&& this = " << this << '\n';
	}
private:

};


int main(){
	/*cout << "Hello World!\n";

	Car car1{ 2021, 5 };
	Car car2{car1};
	Car car3;
	car3 = std::move(car2);
	cout << "car2 = ";
	car2.print();*/

	//cout << "main starts here\n";
	//Myclass&& x = Myclass{ 3,5 };					// ==> yes this is valid and a pr value expression, this line creates a temporary object
	//cout << "main continues\n";


	//THIS HERE IS ABOUT REFERENCE QUALIFIERS
	Myclass{ 3, 4 }.foo();
	Myclass x;
	const Myclass cx;
	x.foo();
	cx.foo();
	std::move(x).foo();
	std::move(cx).foo();

	return 0;
}
