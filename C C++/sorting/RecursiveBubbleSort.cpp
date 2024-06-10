#include<iostream>
using namespace std;

void sort(int *arr, int n) {
	if(n == 1) return;
	int count = 0;
	for(int i = 0; i < n - 1; i++) {
		if(arr[i] > arr[i + 1]) {
			swap(arr[i], arr[i + 1]);
			count++;
		}
	}
	if(count == 0) return ;
	sort(arr, n - 1);
}

int main() {
	int n; cin >> n;
	int *arr = new int[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, n);
	for(int i = 0; i < n; i++) cout << arr[i] << " ";
	delete[] arr;
}