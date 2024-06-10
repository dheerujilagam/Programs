#include<iostream>
using namespace std;

void sort(int *arr, int n) {
	int i, j, ind;
	for(int i = 0; i < n; i++) {
		ind = i;
		for(int j = i + 1; j < n; j++) {
			if(arr[j] < arr[ind]) ind = j;
		}
		swap(arr[i], arr[ind]);
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