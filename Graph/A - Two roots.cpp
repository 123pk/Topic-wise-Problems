/*
Platform :- Codeforces
Contest :- Codeforces Round 333 Div 1 
Approach :- IF you will analyse you will find that shortest path of one of medium (railways , road) is 1 as if there is no track from (1-->n) then there will surely be one
            road from (1-->n) and vice versa . 
            Now problem comes donw to finding the smallest path from 1 to n in other medium , if we cannot reach to n then it is '-1' else it is that path len our solution
Time complexity :- O(V+E)
*/
#include<bits/stdc++.h>
using namespace std;

int find(int start,vector<vector<int>>&graph,int dest){
    
    queue<pair<int,int>>bfs;
    bfs.push({start,0});
    vector<int>dist(dest+1,INT_MAX);
    dist[start] = 0;
    
    while(!bfs.empty()){
        int c = bfs.size();
        for(int i=0;i<c;++i){
            pair<int,int>temp = bfs.front();
            bfs.pop();
            int node = temp.first;
            int cost = temp.second;
            //cout<<node<<"\n";
            for(auto&x:graph[node]){
              //  cout<<x<<" ";
                if(dist[x]>(cost+1)){
                    dist[x] = cost+1;
                    bfs.push({x,cost+1});
                }
                
            }
          //  cout<<"\n\n";
        }
    }
    
    
    if(dist[dest] == INT_MAX)return -1;
    return dist[dest];
}

int main(){
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        //point to note 
        //one of the path will have minimum time  = 1, as 1 will connect n directly
        int n,m;
        cin>>n>>m;
        
        int f = 0;
        vector<vector<int>>train_graph(n);
        for(int i=1;i<=m;++i){
            int u,v;
            cin>>u>>v;
            u--;v--;
            
            train_graph[u].push_back(v);
            train_graph[v].push_back(u);
            int small = min(u,v);
            int big = max(u,v);
            if(small == 0 && big == n-1){
                f=1;
            }
        }
        
        if(m == 0 || m == ((n*(n-1))/2)){
            cout<<"-1";
            continue;
        }
        //now what we want we want to create another graph for bus 
        
        //this means there is no railways track between 1 and n
        if(f == 0){
            int val = find(0,train_graph,n-1);
            cout<<val;
        }
        else{
            vector<vector<int>>bus_graph(n);
            //here we have a railway track between 1 and n
            //so we want the smallest time to reach n
            for(int i=0;i<n;++i){
                int j =0 ;
                sort(train_graph[i].begin(),train_graph[i].end());
                
                for(int k=0;k<n;++k){
                   if(i == k)continue;
                   
                   if(j == train_graph[i].size()){
                       bus_graph[i].push_back(k);
                         
                         continue;
                   }
                     if(k == train_graph[i][j]){
                         j++;
                     }
                     else{
                         bus_graph[i].push_back(k);
                         
                     }
                   
                        
                }
        
             }
              
             int val = find(0,bus_graph,n-1);
             
             cout<<val;
        }
    }
}
