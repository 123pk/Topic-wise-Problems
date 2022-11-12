/*
Platform :- Coding competition with google
Contest :- Google Kickstart Round H 2022
Approach :- We will 
*/

#include<bits/stdc++.h>
using namespace std;
 
int find(int i,vector<vector<int>>&graph,vector<int>&vis,vector<int>&score){
   
    vis[i]++;
    int c = 0;
    
    for(auto&x:graph[i]){
        if(vis[x]){
            c += score[x];
        }
        else{
            c += find(x,graph,vis,score);
        }
    }
    
    return score[i] = c+1;
}

int main(){
    int t;
    cin>>t;
    
    for(int z=1;z<=t;++z){
        cout<<"Case #"<<z<<": ";
        int n;
        cin>>n;
        
        vector<long long>cap(n);
        vector<pair<long long,int>>P;
        for(int i=0;i<n;++i){
            cin>>cap[i];
            P.push_back({cap[i],i});
        }
        
        vector<vector<int>>graph(n);
       
        for(int i=1;i<n;++i){
            int u,v;
            cin>>u>>v;
            u--;
            v--;
           if(cap[u] == cap[v]){
               //there is no sense of joining this
           }
           else{
               if(cap[u]>cap[v]){
                   graph[u].push_back(v);
                  // degree[v]++;
               }
               else {
                   graph[v].push_back(u);
                  // degree[u]++;
               }
           }
        }
      
        int ans = 1;
        
        vector<int>score(n),vis(n);
        for(int i=0;i<n;++i){
            if(vis[i])continue;
           ans = max(ans,find(i,graph,vis,score));
        } 
        cout<<ans<<"\n";
    }
}
