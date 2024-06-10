#include<iostream>
using namespace std;

void sort(int *arr, int n) {
	int i, j, flag;
	for(int i = 0; i < n - 1; i++) {
		flag = 0;
		for(int j = 0; j < n - i - 1; j++) {
			if(arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				flag = 1;
			}
		}
		// for(int k = 0; k < n; k++) cout << arr[k] << " ";
		// cout << endl;
		if(flag == 0) break;
	}
}

int main() {
	int n; cin >> n;
	int *arr = new int[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, n);
	for(int i = 0; i < n; i++) cout << arr[i] << " ";
	delete[] arr;
}