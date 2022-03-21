/*
Platform :- CSES
Approach :- Choose any arbitary point and let us assume it be root , now find the farthest point from that point and it will work as one end of diameter , now from that
            point find the farthest point in tree and that will give us the second point of diameter and no of edges in it is our required length of diameter.
            We will use DFS to find the farthest point.
*/
#include<bits/stdc++.h>
using namespace std;
 
//the basic approach for thhis is to find the length of longest path in tree
//let n be no of edges in path then the solution is n+1>>1
 
void find(vector<vector<int>>&graph,int node,int len,vector<int>&vis){
   len++; 
   vis[node] = len;
    
    vector<int>temp;
    for(auto&x:graph[node]){
        if(vis[x])continue;
        find(graph,x,len,vis);
    }
   
}
 
int main(){
    int n;
    cin>>n;
    
    //vector<int>node(n);
    vector<vector<int>>graph(n);
    int u,v;
    for(int i=1;i<n;++i){
        cin>>u>>v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    //so basic a
    vector<int>dist1(n) ,dist2(n);
    find(graph,0,0,dist1);
    int d = 0;
    int mx = 0,node = -1;
    for(auto&x:dist1){
        if(mx<x){
            node = d;
            mx = x;
        }
        d++;
    }
    
    find(graph,node,0,dist2);
    //int d = 0;
    int mx2 = 0;
    for(auto&x:dist2){
       // cout<<x<<" ";
        if(mx2<x){
            //node = d;
            mx2 = x;
        }
      //  d++;
    }
    
    int ans = mx2-1;
    //ans = ans/2;
    cout<<ans;
}
