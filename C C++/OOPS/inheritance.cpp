#include <iostream>

using namespace std;

// Base class
class Animal {
public:
    void eat() {
        cout << "Eating food." << endl;
    }
};

// Base class
class Vehicle {
public:
    void drive() {
        cout << "Driving a vehicle." << endl;
    }
};

// Derived class inheriting from Animal using virtual inheritance
class Dog : virtual public Animal {
public:
    void bark() {
        cout << "Barking like a dog." << endl;
    }
};

// Derived class inheriting from Animal using virtual inheritance
class Cat : virtual public Animal {
public:
    void meow() {
        cout << "Meowing like a cat." << endl;
    }
};

// Derived class inheriting from Dog and Cat using virtual inheritance
class Pet : public Dog, public Cat {
public:
    void play() {
        cout << "Playing with the pet." << endl;
    }
};

// Derived class inheriting from Pet using multilevel inheritance
class PetVehicle : public Pet {
public:
    void drivePet() {
        cout << "Driving with the pet." << endl;
    }
};

int main() {
    PetVehicle pv;
    pv.eat();         // Accessing eat() from Animal
    pv.bark();        // Accessing bark() from Dog
    pv.meow();        // Accessing meow() from Cat
    pv.play();        // Accessing play() from Pet
    pv.drivePet();    // Accessing drivePet() from PetVehicle
    return 0;
}
