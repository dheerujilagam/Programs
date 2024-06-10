#include<bits/stdc++.h>
using namespace std;

void cycleUsingKhan(int n, vector<int> adj[]){
	vector<int>inDegree(n,0);
	for(int i=0;i<n;i++){
        for(int x:adj[i]){
            inDegree[x]++;
        }
    }

    queue<int>q;
    for(int i=0;i<n;i++){
        if(inDegree[i]==0)
            q.push(i);
    }

    int count=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        count++;
        for(int x:adj[node]){
            --inDegree[x];
            if(inDegree[x]==0)
                q.push(x);
        }
    }
    if(count!=n)
		cout<<"Cycle Detected\n";
	else
		cout<<"No Cycle Detected\n";

}

int main(){
	int n,m; cin>>n>>m;
	vector<int>adj[n];
	int u,v;
	for(int i=0;i<n;i++){
		cin>>u>>v;
		adj[u].push_back(v);
	}
	cycleUsingKhan(n,adj);
}
