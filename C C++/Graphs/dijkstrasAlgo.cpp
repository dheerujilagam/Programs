#include<bits/stdc++.h>
using namespace std;

void bfs(vector<pair<int,int>>adj[],int n, int src){

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	vector<int>dis(n,INT_MAX);
	vector<int> path(n,-1);
	pq.push({0,src});
	dis[src]=0;
	while(!pq.empty()){
		int p=pq.top().second;
		pq.pop();
		for(auto it:adj[p]){
			if(dis[p]+it.second<dis[it.first]){
				path[it.first]=p;
				dis[it.first]=dis[p]+it.second;
				pq.push({dis[it.first],it.first});
			}
		}
	}
	for(int i=0;i<n;i++)
		cout<<path[i]<<" ";
	cout<<"\n";
	for(int i=0;i<n;i++)
		cout<<dis[i]<<" ";
}

int main(){
	int n,m; cin>>n>>m;
	vector<pair<int,int>>adj[n];
	int u,v,w;
	for(int i=0;i<m;i++){
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	int src; cin>>src;
	bfs(adj,n,src);
}