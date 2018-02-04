#include <iostream>

class A {
	int bar = 1;
	void sayhi() {
		std::cout << "hi " << bar;
	}
};

struct B : A {
	A foo;
};

int main() {
	A foo;
	foo.sayhi;
}