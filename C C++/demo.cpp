#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// template<typename... T>
// void see(T&... args) { ((cin >> args), ...);}
// template<typename... T>
// void put(T&&... args) { ((cout << args << " "), ...);}
// template<typename... T>
// void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
// #define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
// void err(istream_iterator<string> it) {}
// template<typename T, typename... Args>
// void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << "=" << a << ", "; err(++it, args...);}
// #define int long long
// #define pb push_back
// #define F first
// #define S second
// #define ll long long
// #define ull unsigned long long
// #define ld long double
// #define pii pair<int,int>
// #define vi vector<int>
// #define vii vector<pii>
// #define vc vector
// #define L cout<<'\n';
// #define E cerr<<'\n';
// #define all(x) x.begin(),x.end()
// #define rep(i,a,b) for (int i=a; i<b; ++i)
// #define rev(i,a,b) for (int i=a; i>b; --i)
// #define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
// #define setpr(x) cout<<setprecision(x)<<fixed
// #define sz size()
// #define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
// #define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
// #define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
// const ll inf = INT_MAX;
// const ld ep = 0.0000001;
// const ld pi = acos(-1.0);
// const ll md = 1000000007;

const int mod = 1e9 + 7;
const int MAX_SUM = 1e5 + 1;
const int MAX_VALUE = 101;
bool dp[MAX_VALUE][MAX_SUM];

int main() {  
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < MAX_SUM; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - arr[i - 1] >= 0 && dp[i - 1][j - arr[i - 1]]) dp[i][j] = true; 
        }
    }
    vector<int> res;
    for (int i = 1; i <= MAX_SUM; i++) if (dp[n][i]) res.push_back(i);
    cout << res.size() << endl;
    for (int it : res) cout << it << " ";
    cout << endl;
}   


