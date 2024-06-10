// + operator overloading -------------------------------------
// #include<bits/stdc++.h>
// using namespace std;

// class Complex {
// private:
// 	int real, img;
// public:
// 	Complex(int a = 2, int b = 3) {
// 		real = a;
// 		img = b;
// 	}

// 	Complex operator+(Complex const& obj) {
// 		Complex res;
// 		res.real = real + obj.real;
// 		res.img = img + obj.img;
// 		return res;
// 	} 

// 	void print() {
// 		cout << real << " + i" << img << endl;
// 	}
// };	

// int main() {
// 	Complex c1(10, 5), c2(3, 6), c3;
// 	Complex c4 = c1 + c2 + c3;
// 	c4.print();
// }


// - operator overloading ------------------------------------- 

#include<bits/stdc++.h>
using namespace std;

class Complex {
private:
	int real, img;
public:
	Complex(int a = 0, int b = 0) {
		real = a;
		img = b;
	}

	Complex operator-(Complex const& obj) {
		Complex res;
		res.real = real - obj.real;
		res.img = img - obj.img;
		return res;
	} 

	void print() {
		cout << real << " - i" << img << endl;
	}
};	

int main() {
	Complex c1(10, 5), c2(3, 6), c3(0, 0);
	Complex c4 = c1 - c2 - c3;
	c4.print();
}