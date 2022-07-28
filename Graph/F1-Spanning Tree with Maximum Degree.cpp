/*
Platform :- Codeforces
Contest :- Codeforces Round 544 Div 3
Approach :- find the node with max degree , now we will make that node as root, now we will find the spanning tree and that is our required solution.
Time Complexity :- O(V+E)
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    
    int mx = 0;
    vector<vector<int>>graph(n);
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        int z = graph[u].size();
        int y = graph[v].size();
        mx = max(mx,y);
        mx = max(mx,z);
        
    }
     
    //now what find the biggest degree
    int root = 0;
    for(int i=0;i<n;++i){
        if(int(graph[i].size()) == mx){
            root = i;
            break;
        }
    }
    
    vector<int>vis(n);
    vis[root]++;
    
    vector<pair<int,int>>ans;
    //now basic though is to choose those nodes which are not choosen yet
    ///starting from root using bfs
    queue<int>bfs;
    bfs.push(root);
    
    while(!bfs.empty()){
        int c = bfs.size();
        for(int i=0;i<c;++i){
            int node = bfs.front();
            bfs.pop();
            
            for(auto&x:graph[node]){
                if(vis[x])continue;
                vis[x]++;
                bfs.push(x);
                ans.push_back({node+1,x+1});
            }
        }
    }
    
    for(auto&x:ans)cout<<x.first<<" "<<x.second<<"\n";
}
