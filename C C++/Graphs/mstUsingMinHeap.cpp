#include<bits/stdc++.h>
using namespace std;

void bfs(vector<pair<int,int>> adj[], int n){
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
	vector<int>vis(n,0);
	int ans=0;
	pq.push({0,0});
	while(!pq.empty()){
		pair<int,int>p=pq.top();
		pq.pop();
		int wt=p.first;
		int node=p.second;
		if(!vis[node]){
			vis[node]=1;
			ans+=wt;
			for(auto it:adj[node]){
				int x=it.first;
				int y=it.second;
				if(!vis[x]){
					pq.push({y,x});
				}
			}
		}
	}
	cout<<"Minimum Cost: "<<ans<<endl;	
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>>adj[n];
	for(int i=0;i<m;i++){
		int u,v,d;
		cin>>u>>v>>d;
		adj[u].push_back({v,d});
		adj[v].push_back({u,d});
	}
	//BFS
	bfs(adj,n);
}