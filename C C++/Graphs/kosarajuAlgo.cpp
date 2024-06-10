#include<bits/stdc++.h>
using namespace std;

class Solution{

	void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st){
        vis[node]=1;
        for(int it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,st);
            }
        }
        st.push(node);
    }
    
    void dfsT(int node, vector<int> adjT[], vector<int> &vis){
        vis[node]=1;
        for(int it:adjT[node]){
            if(!vis[it]){
                dfsT(it,adjT,vis);
            }
        }
    }

	public :
	int kosaraju(int n, vector<int> adj[]){
        stack<int>st;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        
        vector<int>adjT[n];
        for(int i=0;i<n;i++){
            vis[i]=0;
            for(int it:adj[i]){
                adjT[it].push_back(i);
            }
        }
        
        int connected=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis[node]){
                connected++;
                dfsT(node,adjT,vis);
            }
        }
        
        return connected;
    }
};

int main(){
	int n,m; cin>>n>>m;
	vector<int>adj[n];
	int u,v;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		adj[u].push_back(v);
	}
	Solution ob;
	cout<<"Strongly connected components :"<<ob.kosaraju(n,adj)<<endl;
}