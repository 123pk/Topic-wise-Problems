/*
Platform :- Codeforces
Contest :- Codeforces Round 565 Div 3
Approach :- We choose any node and find one end of diameter ( farthest node from this choosen node is one end of diameter) . Now we make that node as root and do bfs
            from this and we find no of nodes in (odd level) and in (even level) . So the min of no of (odd level nodes and even level nodes) is choosen and marked
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<vector<int>>graph(n);
        for(int i=0;i<m;++i){
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        //now we will do bfs and we have two option 
        //we will color or mark or choose odd level values or even level values ones with value
        //less than equal to n/2
        //first find one end of diameter and mark it as root
        queue<pair<int,int>>bfs;
        bfs.push({0,0});
        vector<int>dist(n,INT_MAX);
        dist[0] = 0;
        int mx = 0;
        while(!bfs.empty()){
            int c = bfs.size();
            for(int i=0;i<c;++i){
                pair<int,int>temp = bfs.front();
                bfs.pop();
                
                int node = temp.first;
                int val = temp.second;
                
                for(auto&x:graph[node]){
                    if(dist[x]>(val+1)){
                        dist[x] = val+1;
                        mx = max(mx,val+1);
                        bfs.push({x,val+1});
                    }
                }
            }
        }
        
        int root = 0;
        for(int i=0;i<n;++i){
            if(dist[i] == mx){
                root = i;
                break;
            }
        }
        
        queue<int>bfs2;
        vector<int>vis(n);
        bfs2.push(root);
        vis[root]++;
        int d = 0,o = 0,e = 0;
        vector<int>even,odd;
        
        while(!bfs2.empty()){
            int c = bfs2.size();
            if(d%2){
                o+=c;
            }
            else e+=c;
            
            for(int i=0;i<c;++i){
                int node = bfs2.front();
                bfs2.pop();
                if(d%2)odd.push_back(node);
                else even.push_back(node);
                
                for(auto&x:graph[node]){
                    if(vis[x])continue;
                    vis[x]++;
                    bfs2.push(x);
                }
            }
            d++;
        }
        
        
        int req = n/2;
        if(o>req){
            cout<<e<<"\n";
            for(auto&x:even)cout<<(x+1)<<" ";
            cout<<"\n";
        }
        else{
            cout<<o<<"\n";
            for(auto&x:odd)cout<<(x+1)<<" ";
            cout<<"\n";
        }
        
    }
    
}
