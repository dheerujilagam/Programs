#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void bfs(vector<int>adj[],vector<int>&v,int n){
	queue<int>q;
	q.push(1);
	while(q.size()!=0){
		int a=q.front();
		q.pop();
		for(auto it:adj[a]){
			if(v[a]+1<=v[it]){ 
				q.push(it);
				v[it]=v[a]+1;
			}
		}
	}
	for(int i=1;i<=n;i++) 
		cout<<v[i]<<" ";
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<int>adj[n+1];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	//BFS
	vector<int>dis(n+1,INT_MAX);
	dis[1]=0;
	bfs(adj,dis,n);
}