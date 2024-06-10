#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(int node, vector<int>adj[], vector<int> &vis){
	vis[node]=1;
	cout<<node<<" ";
	for(auto it:adj[node]){
		if(!vis[it]){
			dfs(it,adj,vis);
		}
	}
}

void bfs(int node, vector<int>adj[], vector<int>&visited, queue<int>&q){
	visited[node]=1;
	q.push(node);
	while(!q.empty()){
		int n=q.front();
		q.pop();
		cout<<n<<" ";
		for(int i=0;i<adj[n].size();i++){
			if(!visited[adj[n][i]]){
				visited[adj[n][i]]=1;
				q.push(adj[n][i]);
			}
		}
	}
}

int main(){
	int n,m; cin>>n>>m;
	vector<int>adj[n+1];
	vector<int>vis(n+1,0);
	for(int i=0;i<m;i++){
		int u,v; cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i])
			dfs(i,adj,vis);
	}
	cout<<"\n";
	queue<int>q;
	vector<int>visited(n+1,0);
	for(int i=1;i<=n;i++){
		if(!visited[i])
			bfs(i,adj,visited,q);
	}
}