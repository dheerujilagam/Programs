#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    vector<int> ST;
    vector<int> arr;
    int n;

    int ConstructST(int ind, int st, int se) {
        if (st == se) return ST[ind] = arr[st];
        int mid = (st + se) / 2;
        return ST[ind] = ConstructST(2 * ind + 1, st, mid) + ConstructST(2 * ind + 2, mid + 1, se);
    }

    int getSum(int ind, int qs, int qe, int ss, int se) {
        if (se < qs || qe < ss) return 0;
        if (qs <= ss && se <= qe) return ST[ind];
        int mid = (ss + se) / 2;
        return getSum(2 * ind + 1, qs, qe, ss, mid) + getSum(2 * ind + 2, qs, qe, mid + 1, se);
    }

    void updateValue(int ind, int qi, int st, int end, int dif) {
        if (qi < st || qi > end) return ;
        ST[ind] += dif;
        if (st < end) {
            int mid = (st + end) / 2;
            updateValue(2 * ind + 1, qi, st, mid, dif);
            updateValue(2 * ind + 2, qi, mid + 1, end, dif);
        }
    }

public:
    SegmentTree(vector<int>& inputArr) {
        arr = inputArr;
        n = arr.size();
        int x = (int)(ceil(log2(n)));
        int len = 2 * (int)pow(2, x) - 1; // segment tree length formula
        ST.resize(len, 0);
        ConstructST(0, 0, n - 1);
    }

    int getSum(int qs, int qe) {
        return getSum(0, qs, qe, 0, n - 1);
    }

    void updateValue(int qi, int val) {
        updateValue(0, qi, 0, n - 1, val - arr[qi]);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    SegmentTree st(arr);

    int queryLen; cin >> queryLen;
    while (queryLen--) {
    	int type = 0; cin >> type;
    	if (type == 0) {
    		int s, e; cin >> s >> e;
    		cout << st.getSum(s, e) << "\n";
    	} else {
    		int ind, value; cin >> ind >> value;
    		st.updateValue(ind, value);
    	}
    }

}
