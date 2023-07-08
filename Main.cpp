#include<iostream>
class A {
public:
	A() {
		std::cout << "Default constructor called" << std::endl;
	}
	A(const A& other) {
		std::cout << "Copy constructor called" << std::endl;
	}
	~A() {}
public:
	void print_l(int a) {
		std::cout << "lvalue object" << std::endl;
	}
	void printRef(A& obj) {
		std::cout << "lvalue ref " << std::endl;
	}
	void printConstRef(const A& obj) {
		std::cout << "const lvalue ref " << std::endl;
	}
	void printRValueRef(A&& obj) {
		std::cout << "rvalue ref " << std::endl;
	}
	void printConstRValueRef(const A&& obj) {
		std::cout << "const rvalue ref " << std::endl;
	}
};
int main() {
	A obj;
	int a= 5;
	obj.print_l(a);
	A& objref = obj;
	obj.printRef(objref);
	const A& constobjref = obj;
	obj.printConstRef(constobjref);
	obj.printRValueRef(std::move(obj));
	obj.printConstRValueRef(std::move(obj));

	return 0;
}
