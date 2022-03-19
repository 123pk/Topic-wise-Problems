/*
Platform :- Codechef
Contest :- Codechef Lunctime March 2022
Approach :- We do bfs on nodes that are frozen and we use a vis array to visit the unvisited ones only , we do so whenever we have some time lapse or query of
            type 2 . We bfs for 't' minutes or until the time our queue is not empty. For 3rd query if the node is already visited then it means it is frozen and we
            print "YES" else "NO"
*/
#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    
    int u,v;
    vector<vector<int>>graph(n);
    for(int i=0;i<m;++i){
        cin>>u>>v;
        u--;v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    //so basic approach is to find the minimum time required by each node to 
    //get frozen
    int y;
    long long t;
    long long time_till = 0;
    vector<int>used(n);
    vector<long long>min_time(n,1e18);
    vector<pair<int,long long>>queries;
    queue<int>bfs;
    
    
    
    for(int i=0;i<q;++i){
        int x;
        cin>>x;
        if(x==1){
            cin>>y;
            y--;
            if(used[y])continue;
            bfs.push({y});
            used[y]++;
           /* if(used[y])continue;
            used[y]++; 
            min_time[y] = time_till;
            */
        }
        else if(x==2){
            cin>>t;
            
            while(t && !bfs.empty()){
                int c = bfs.size();
                for(int j=0;j<c;++j){
                    //pair<int,long long>temp 
                    int node = bfs.front();
                    bfs.pop();
                 //   int node = temp.first;
                   // long long val = temp.second;
            
                    for(auto&x:graph[node]){
                         if(used[x])continue;
                         used[x]++;
                         bfs.push(x);
                    }
                }
                t--;
            }
            /*time_till+=t;*/
        }
        else{
            cin>>y;
            y--;
            if(used[y])cout<<"YES\n";
            else cout<<"NO\n";
            
        }
    }
    
}
