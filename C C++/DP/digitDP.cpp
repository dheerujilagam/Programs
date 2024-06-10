#include<bits/stdc++.h>
using namespace std;
int d, k;
int dp[1000000][2][10];
int solve(int f, int ind, int count, string sq, string &m) {
	if(ind == m.length()) {
		if(count == k){ cout << sq << " "; return 1;}
		else return 0;
	}
	if(count > k) return 0;
	if(dp[ind][f][count] != -1) return dp[ind][f][count];
	int limit = 9, ans = 0, flag, cur;
	if(f == 0) limit = m[ind] - '0';
	for(int i = 0; i <= limit; i++) {
		flag = f;
		cur = count;
		if(f == 0 && i < limit) flag = 1;
		if(i == d) cur = count + 1;
		ans += solve(flag, ind + 1, cur, sq + to_string(i), m);
	}
	return dp[ind][f][count] = ans;
}
int main() {
	fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp) / sizeof(int), -1);
	string a, b; cin >> a >> b;
	cin >> d >> k;
	int x = solve(0, 0, 0, "", b);
	memset(dp, -1, sizeof(dp));
	int y = solve(0, 0, 0, "", a);
	cout << x - y << endl;
}
