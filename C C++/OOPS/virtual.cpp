#include <iostream>
using namespace std;

class Base {
public:
    virtual void print() {
        cout << "Base class" << endl;
    }
};

class Derived : public Base {
public:
    void print() override {
        cout << "Derived class" << endl;
    }
};

int main() {
    Base* ptr = new Derived();
    ptr->print();  // Output: "Derived class"

    delete ptr;

    return 0;
}
