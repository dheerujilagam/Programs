#include <bits/stdc++.h>
using namespace std;
class B;
class A{
public:
	void showA(B& b);
};

class B{
private:
	int a;
public:
	B(){
		a = 10;
	}
	friend void A::showA(B&);
};

void A::showA(B& b){
	cout << b.a << endl;
}

int main(){
	B obj;
	A objA;
	objA.showA(obj);
}


// class A {
// public:
//     void showA(B& b);  // Match the function name case
// };

// class B {
// private:
//     int a;
// public:
//     B() {
//         a = 10;
//     }
//     friend void A::showA(B& b);  // Match the function name case
// };

// void A::showA(B& b) {
//     cout << b.a << endl;
// }

// int main() {
//     B obj;
//     A objA;
//     objA.showA(obj);
//     return 0;
// }

 


 

