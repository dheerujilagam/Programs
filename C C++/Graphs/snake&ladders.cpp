#include<bits/stdc++.h>
using namespace std;
void ways(vector<int>adj[], vector<int>&dis, int pos, int moves){
    if(pos>=100){
        dis[100]=min(dis[100],moves);
        return ;
    }
    dis[pos]=min(dis[pos],moves);
    for(int i=1;i<=6;i++){
        if(adj[pos+i].size()!=0 and dis[pos+i]>=moves+1 and pos+i<=100){
            dis[pos+i]=moves+1;
            ways(adj,dis,adj[pos+i][0],moves+1);
        }
    }
    if(pos+6>100)
        ways(adj,dis,100,moves+1);
    else
        ways(adj,dis,pos+6,moves+1);
    return ;
}
int main(){
    int tc; cin>>tc;
    while(tc--){
        int ladders,snakes; cin>>ladders;
        vector<int>adj[101];
        int u,v,ob=0; 
        while(ladders--){
            cin>>u>>v;
            adj[u].push_back(v);
        }
        cin>>snakes;
        while(snakes--){
            cin>>u>>v;
            adj[u].push_back(v);
            if(u>=93 and u<=99)
                ob++;
        }
        if(ob>=6)
            cout<<-1<<"\n";
        else{
            vector<int>dis(101,INT_MAX);
            ways(adj,dis,1,0);
            cout<<dis[100]<<"\n";
        }
    }
}
