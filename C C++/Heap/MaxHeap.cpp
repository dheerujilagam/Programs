#include<iostream>
#include <vector>
using namespace std;
#define pb push_back

void heapify(vector<int> &heapTree, int n, int i) {
    int largest = i;
    int left = 2 * i + 1, right = 2 * i + 2;
    if(left < n && heapTree[left] > heapTree[largest]) largest = left;
    if(right < n && heapTree[right] > heapTree[largest]) largest = right;
    if(largest != i) {
        swap(heapTree[i], heapTree[largest]);
        heapify(heapTree, n, largest);
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
	int n = heapTree.size(), i;
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