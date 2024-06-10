#include<iostream>
#include <vector>
using namespace std;
#define pb push_back

void heapify(vector<int> &heapTree, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1, right = 2 * i + 2;
    if(left < n && heapTree[left] < heapTree[smallest]) smallest = left;
    if(right < n && heapTree[right] < heapTree[smallest]) smallest = right;
    if(smallest != i) {
        swap(heapTree[i], heapTree[smallest]);
        heapify(heapTree, n, smallest);
    }
}

void insert(vector<int> &heapTree, int num) {
	int n = heapTree.size();
	if(n == 0) {
		heapTree.pb(num);
	} else {
		heapTree.pb(num);
		for(int i = (n / 2) - 1; i >= 0; i--) heapify(heapTree, n + 1, i);
	}
}

void deleteNode(vector<int> &heapTree, int num) {
	int n = heapTree.size(), i = 0;
	while(i < n) {
		if(heapTree[i] == num) break;
		i++;
	}
	swap(heapTree[i], heapTree[n - 1]);
	heapTree.pop_back();
	n = heapTree.size();
	for(int i = n / 2 - 1; i >= 0; i--) heapify(heapTree, n, i);
}

int main() {
	int n, cur; cin >> n;
	vector<int> heapTree;
	for(int i = 0; i < n; i++) {
		cin >> cur;
		insert(heapTree, cur);
	} 
	for(int i = 0; i < heapTree.size(); i++) cout << heapTree[i] << " ";
	cout << endl;
	deleteNode(heapTree, 15);
	for(int i = 0; i < heapTree.size(); i++) cout << heapTree[i] << " ";
}
