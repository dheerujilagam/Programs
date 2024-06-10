#include <bits/stdc++.h>
using namespace std;

int main() {
    int **arr = new int*[4];
    for (int i = 0; i < 4; i++) arr[i] = new int[4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    /*
        int *p = *arr;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> *(p + (i * 4) + j);
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << *(p + (i * 4) + j) << " ";
            }
        }
    */
}