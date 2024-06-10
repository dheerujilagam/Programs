#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<int>&vis1, vector<int>&vis2, vector<int>adj[]){
	vis1[node]=1;
	vis2[node]=1;
	for(auto it:adj[node]){
		if(!vis1[it]){
			if(dfs(it,node,vis1,vis2,adj))
				return true;
		}
		else if(vis2[it])
			return true;
	}
	vis2[node]=0;
	return false;
}

bool isCycle(int n, vector<int>adj[]){
	vector<int>vis1(n,0);
	vector<int>vis2(n,0);
	for(int i=0;i<n;i++){
		if(!vis1[i]){
			if(dfs(i,-1,vis1,vis2,adj))
				return true;
		}
	}
	return false;
}

int main(){
	int n,m; cin>>n>>m;
	vector<int>adj[n];
	for(int i=0;i<m;i++){
		int u,v; cin>>u>>v;
		adj[u].push_back(v);
		//adj[v].push_back(u);
	}
	if(isCycle(n,adj))
		cout<<"Cycle Detected";
	else
		cout<<"No Cycle Detected";
}