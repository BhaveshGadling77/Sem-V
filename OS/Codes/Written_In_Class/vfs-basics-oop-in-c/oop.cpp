#include <iostream>
class animal {
	public:
	int x;
	void talk() {
		std::cout << "Animal Talking" << std::endl;
		x = 20;
	}
	virtual void me() {
		std::cout << "This is animal" << x << std::endl;
	}
	void nothing() {
		std::cout << "Nothing in animal " << std::endl;
	}
};
class tiger: public animal {
	public:
	int y;
	void talk() {
	 	std::cout << "Tiger Rouring" << std::endl;
		x = 30;
		y = 100;
	}
	void me() {
		std::cout << "This is tiger " << x << " y = " << y << std::endl;
	}
	void eat() {
		std::cout << "Eat tiger " << std::endl;
	}
	
};
class cat: public animal {
	public:
	int z;
	void talk() {
	 	std::cout << "Cat Muttering" << std::endl;
		x = 50;
		z = 200;
	}
	void me() {
		std::cout << "This is cat " << x << " z = " << z << std::endl;
	}
	
};
int main() {
	int i;
	animal *a = new animal();
	tiger *t = new tiger();
	cat *c = new cat();
	a->talk();
	t->talk();	
	c->talk();
	t->me();
	c->me();
	t->nothing();
	std::cin >> i;
	if(i  < 5) {
		a = c;
	} else {
		a = t;
	}
	a->talk();
	a->me();
}
