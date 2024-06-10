#include<bits/stdc++.h>
using namespace std;

//function that have current index or vertex, visited array and parent node.
bool dfs(int node, int parent, vector<int>&vis, vector<int>adj[]){
	
	//Mark the current node as visited.
	vis[node]=1;
	for(auto it:adj[node]){
		/*Find all the vertices which are not visited and are adjacent to the current node. 
		Recursively call the function for those vertices, 
		If the recursive function returns true return true.*/
		if(!vis[it]){
			if(dfs(it,node,vis,adj))
				return true;
		}
		//If the adjacent node is not parent and already visited then return true.
		else if(it!=parent)
			return true;
	}
	return false;
}

bool isCycle(int n, vector<int>adj[]){
	vector<int>vis(n,0);
	for(int i=0;i<n;i++){
		if(!vis[i]){
			if(dfs(i,-1,vis,adj))
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
		adj[v].push_back(u);
	}
	if(isCycle(n,adj))
		cout<<"Cycle Detected";
	else
		cout<<"No Cycle Detected";
}

/*
Time Complexity: O(V+E). 
The program does a simple DFS Traversal of the graph which is represented using adjacency list. So the time complexity is O(V+E).
Space Complexity: O(V). 
To store the visited array O(V) space is required.
*/