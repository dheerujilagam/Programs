#include<bits/stdc++.h>
using namespace std;

string lcs(int i, int j, string &s1, string &s2, int n, int m, vector<vector<string>> &dp) {
	if(i >= n || j >= m) return "";
	if(dp[i][j] != "/") return dp[i][j]; 
	if(s1[i] != s2[j]) {
		string t1 = lcs(i + 1, j, s1, s2, n, m, dp);
		string t2 = lcs(i, j + 1, s1, s2, n, m, dp);
		return dp[i][j] = t1.length() > t2.length() ? t1 : t2;
	}
	string s = s1[i] + lcs(i + 1, j + 1, s1, s2, n, m, dp);
	return dp[i][j] = s;
}

string solve(string &s1, string &s2) {
	int n = s1.length(), m = s2.length();
	vector<vector<string>> dp(n, vector<string> (m, "/"));
	return lcs(0, 0, s1, s2, n, m, dp);
}

int main(){
	string s1, s2; cin >> s1 >> s2;
	cout << solve(s1, s2) << endl;
}