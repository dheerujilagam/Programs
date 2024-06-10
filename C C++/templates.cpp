#include <iostream>
using namespace std;

template <typename T> void bubbleSort(T a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; i < j; j--)
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
}

int main() {
	string a[5] = { "KTM", "Triumph", "Jawa", "RE", "BMW" };
	int n = sizeof(a) / sizeof(a[0]);
	bubbleSort<string>(a, n);
	cout << " Sorted array : ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}

// template specialization for function and class
/*
template<> void fun(int a) {
    cout << "Specialized Template for int type: " << a << endl;
}

template <> class Test <int> {
public:
   Test() {
       // Initialization of data members
       cout << "Specialized template object\n";
   }
};
*/