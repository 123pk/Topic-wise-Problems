/*
Platform :- CSES Problem set 
Approach :- This is also based on diameter of tree problem , the max distance of any node is the maximum of value of distances from end points of diameter .
           So first we will find end points of diameter and then we will find the distance of each noode from those points ,the max value out of two is the required value
           for each node .
Time Complexity :- O(n) -- time for dfs call 
Space Complexity :- O(n) where n is no of nodes
*/
#include<bits/stdc++.h>
using namespace std;
 
//the basic approach for thhis is to find the length of longest path in tree
//let n be no of edges in path then the solution is n+1>>1
 
void find(vector<vector<int>>&graph,int node,int len,vector<int>&vis){
   len++; 
   vis[node] = len;
  //  cout<<node+1<<" "<<len<<"\n";
    vector<int>temp;
    for(auto&x:graph[node]){
        if(vis[x])continue;
        find(graph,x,len,vis);
    }
    
 //   sort(temp.begin(),temp.end(),greater<int>());
    
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
    
    //First we will find farthest point from any arbitary node that will be one of end points of diameter
    vector<int>dist1(n) ,dist2(n),dist3(n);
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
 
    int z = node;
           
     //here we will find the farthest point from one of end point of diameter and that will give us the second end point
    find(graph,node,0,dist2);
 
    int mx2 = 0;
    d = 0;//
    
    vector<pair<int,int>>P;
    int e = 0;
    for(auto&x:dist2){
        if(mx2<x){
            mx2 = x;
            d = e;
        }
        e++;
    }
    
    //findind distance of each node from other end point of diameter
    find(graph,d,0,dist3);
     
     for(int i=0;i<n;++i){
       cout<<max(dist2[i],dist3[i])-1<<" ";   
     }
    
    
    
}
