#include<iostream>
using namespace std;

int minElement(int *arr, int i, int j) {
	if(i == j) return i;
	int k = minElement(arr, i + 1, j);
	return arr[i] < arr[k] ? i : k;
}

void sort(int *arr, int n, int index) {
	if(index == n) return ;
	int minIndex = minElement(arr, index, n - 1);
	if(minIndex != index) swap(arr[index], arr[minIndex]);
	sort(arr, n, index + 1);
}

int main(){
	int n; cin >> n;
	int *arr = new int[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, n, 0);
	for(int i = 0; i < n; i++) cout << arr[i] << " ";
	delete[] arr;
}