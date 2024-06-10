#include<iostream>
using namespace std;

int getMax(int *arr, int n) {
	int maxValue = arr[0];
	for(int i = 1; i < n; i++) maxValue = (arr[i] > maxValue) ? arr[i] : maxValue;
		return maxValue;
}

void sort(int *arr, int n) {
	int maxValue = getMax(arr, n);
	int count[maxValue + 1] = {0};
	int sortedArr[n];
	for(int i = 0; i < n; i++) count[arr[i]]++;
	for(int i = 1; i <= maxValue; i++) count[i] += count[i - 1];
	for(int i = n - 1; i >= 0; i--) {
		sortedArr[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}
	for(int i = 0; i < n; i++) arr[i] = sortedArr[i];
}	

int main() {
	int n; cin >> n;
	int *arr = new int[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, n);
	for(int i = 0; i < n; i++) cout << arr[i] << " ";
	delete arr[];
}