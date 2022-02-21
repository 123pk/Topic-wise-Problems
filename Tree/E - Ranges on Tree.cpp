/*
Platform :- Atcoder
Contest :- Atcoder Beginner Contest 240
Approach :- We assign the values ( ith leaf has {i,i} range ) to leaf nodes then we accumulate the result for their parents . For finding leaf we use BFS and for assinging the 
           [l,r] range we use DFS . 
*/
#include<bits/stdc++.h>
using namespace std;
pair<int,int>zz;

pair<int,int> dfs(vector<vector<int>>&graph,int node,int &l,vector<int>&leaf,vector<pair<int,int>>&ans,vector<int>&vis){
    vis[node]++;
    if(leaf[node]){
        ans[node] = {l,l};
        l++;
        return ans[node];
    }
    
    for(auto &x:graph[node]){
        if(vis[x])continue;
        zz = dfs(graph,x,l,leaf,ans,vis);
        ans[node].first = min(ans[node].first,zz.first);
        ans[node].second = max(ans[node].second,zz.second);
        
    }
    return ans[node];
    
}

int main(){
    int n;
    cin>>n;
    
    vector<vector<int>>graph(n);
    int u,v;
    for(int i = 1;i<n;++i){
        cin>>u>>v;
        u--;v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    //First find the leaf nodes and their parents no of leaf nodes in the subtree is 
    //the range for the given set of nodes 
    
    vector<int>vis(n);
    queue<int>bfs;
    bfs.push(0);
    vis[0]++;
    vector<int>parent(n,-1);
    vector<int>not_leaf(n,-1);
    
    while(!bfs.empty()){
        int c = bfs.size();
        for(int i = 0;i<c; ++i){
            int temp = bfs.front();
            bfs.pop();
            
            for(auto&x:graph[temp]){
                if(vis[x])continue;
                vis[x]++;
                bfs.push(x);
                parent[x] = temp;
                not_leaf[temp]=1;
            }
        }
    }
    
    vector<int>vis2(n);
    //queue<int>bfs2;
    vector<pair<int,int>>ans(n,{INT_MAX,0});
    pair<int,int>value;
    vector<int>leaf(n);
     
    for(int i = 0;i<n;++i){
        if(not_leaf[i]==-1){
            leaf[i]++;
            //this is leaf node 
             
        }
    }
     
    //wE Do dfs and assign each leaf node a value and its parent is updated every time
    int l = 1;
    value = dfs(graph,0,l,leaf,ans,vis2);
    
    for(auto &x:ans)cout<<x.first<<" "<<x.second<<"\n";
    
    
}
