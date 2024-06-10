
#include<bits/stdc++.h> 
using namespace std; 

void DFS(vector<int> adj[], int u, stack<int> &st, vector<int> &visited) 
{   
    visited[u]=1;
    
    for(int v:adj[u]){
        if(!visited[v])
            DFS(adj,v,st,visited);
    }
    st.push(u);
}

void topologicalSort(vector<int> adj[], int V) 
{ 
    vector<int>visited(V,0);
    stack<int> st;
    
    for(int u=0;u<V;u++){
        if(!visited[u]){
            DFS(adj,u,st,visited);
        }
    }
    
    while(!st.empty()){
        int u=st.top();
        st.pop();
        cout<<u<<" ";
    }
   
}

int main() 
{ 
    int n,m; cin>>n>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
    }
  
    topologicalSort(adj,n);

    return 0; 
} 
