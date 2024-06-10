#include<bits/stdc++.h>
using namespace std;

int parent[100000];
int Rank[100000];
void SetData(){
	for(int i=0;i<100000;i++){
		parent[i]=i;
		Rank[i]=0;
	}
}

int FindParent(int node){
	if(parent[node]==node) 
		return node;
	return parent[node]=FindParent(parent[node]);
}

void Union(int u, int v){
	u=FindParent(u);
	v=FindParent(v);
	if(Rank[u]<Rank[v]){
		parent[u]=v;
	}
	else if(Rank[u]>Rank[v]){
		parent[v]=u;
	}
	else{
		parent[v]=u;
		Rank[u]++;
	}
}

int main(){
	//int n,m; cin>>n>>m;
	SetData();
	Union(1,2);
	Union(2,3);
	Union(4,5);
	Union(6,7);
	Union(5,6);
	if(FindParent(3)!=FindParent(7)){
		cout<<1<<endl;
	}
	else
		cout<<0<<endl;
}