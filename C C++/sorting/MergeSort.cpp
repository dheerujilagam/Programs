#include<iostream>
using namespace std;

void merge(int *arr, int l, int m, int r) {
	int n1 = m - l + 1, n2 = r - m;
	int *a1 = new int[n1], *a2 = new int[n2];
	for(int i = 0; i < n1; i++) a1[i] = arr[l + i];
	for(int i = 0; i < n2; i++) a2[i] = arr[m + i + 1];
	int i = 0, j = 0, k = l;
	while(i < n1 && j < n2) {
		if(a1[i] <= a2[j]) {
			arr[k] = a1[i++];
		} else {
			arr[k] = a2[j++];
		}
		k++;
	}
	while(i < n1) {
		arr[k++] = a1[i++];
	}
	while(j < n2) {
		arr[k++] = a2[j++];
	}
	delete[] a1;
	delete[] a2;
}
 
void mergeSort(int *arr, int l, int r) {
	if(l >= r) return ;
	int m = (l + r) / 2;
	mergeSort(arr, l, m);
	mergeSort(arr, m + 1, r);
	merge(arr, l, m, r);
}

int main() {
	int n; cin >> n;
	int *arr = new int[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	mergeSort(arr, 0, n - 1);
	for(int i = 0; i < n; i++) cout << arr[i] << " ";
	delete[] arr;
}