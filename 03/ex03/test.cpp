#include "ScavTrap.hpp"
#include <iostream>

class a {
	public:
		a();
		~a();
		 void hi();
	protected:
		std::string s;
};

a::a () : s("aaa"){

}

a::~a() {

}

void a::hi () {
	std::cout << "from a" << std::endl;
}

class b : public virtual a {
	public:
		b();
		~b();

	void hi();
};

b::b() : a() {

}
b::~b() {

}

void b::hi() {
	std::cout << "from b" << std::endl;
}

class c : public virtual a {
	public:
	c();
	~c();

	void hi();
};

c::c() : a() {
	a::s = "hello";

}

c::~c() {

}

void c::hi() {
	std::cout << "from c" << std::endl;
}

class d : public b, public c {
public:
	d();
	~d();

	using b::hi;
};

d::d() : b(), c(){
	a::s = "hi";
}

d::~d() {

}

/* d::d() { */
/* 	a::s = "hi"; */
/* } */

// test
int main(void) {
	a aa;
	b bb;
	c cc;
	d dd;

	aa.hi();
	bb.hi();
	cc.hi();
	dd.hi();
}
