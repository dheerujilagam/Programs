#include<iostream>
using namespace std;

int QuickSort(int *arr, int st, int end) {
    int p = arr[end];
    int l = st - 1;
    for(int i = st; i < end; i++) {
        if(arr[i] < p) {
            l++;
            swap(arr[l], arr[i]);
        }
    }
    swap(arr[l + 1], arr[end]);
    return l + 1;
}

void sort(int *arr, int l, int r) {
    if(l < r) {
        int p = QuickSort(arr, l, r);
        sort(arr, l, p - 1);
        sort(arr, p + 1, r);
    }
}

int main() {
    int n; cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, 0, n - 1);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    delete[] arr;
}
