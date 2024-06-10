#include<bits/stdc++.h>
using namespace std;

class parent {
public:
	void print() { 
		cout << "parent class" << endl;
	}
};

class child : public parent {
public:
	void print() {
		cout << "child class" << endl;
		// Call Overridden Function From Derived Class
		parent :: print();
	}
};

int main() {
	child c1;
	// c1.parent :: print();
	parent* ptr = &c1;
	ptr->print();
	c1.print();
}