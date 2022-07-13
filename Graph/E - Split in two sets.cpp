/*
Platform :- Codeforces 
Contest :- Codeforces Round 805 Div 3
Approach :- We will make graph of the points and if there is cycle of odd edge length then we cannot seperatte them out , or if we have same elements in pair,or 
            if frequency of some element is >2
*/
#include<bits/stdc++.h>
using namespace std;


bool find(int node,int parent,vector<vector<int>>&graph,vector<int>&vis,int len){
    vis[node] = 1;
    
    for(auto&x:graph[node]){
        if(x == parent)continue;
        if(vis[x] == 1){
            if((len+1) %2)return true;
            else return false;
        }
        
        if(vis[x] == 0)return find(x,node,graph,vis,len+1);
    }
    vis[node] = 2;
    return false;
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        int f = 0;
        map<int,int>count;
        
        //this will take care of already used or formed edges
        //we will not repeat them
        set<pair<int,int>>used;
        
        vector<vector<int>>graph(n);
        vector<pair<int,int>>P;
        for(int i=0;i<n;++i){
            int u,v;
            cin>>u>>v;
            
            count[u]++;
            count[v]++;
            if(count[u]>2 || count[v]>2 || u == v){
                f=1;
            }
            
            if(used.size()){
                if(used.find({min(u,v),max(u,v)}) != used.end())continue;
                else used.insert({min(u,v),max(u,v)});
            }
            else used.insert({min(u,v),max(u,v)});
           // cout<<min(u,v)<<" "<<max(u,v)<<"\n";
            P.push_back({u-1,v-1});
            graph[u-1].push_back(v-1);
            graph[v-1].push_back(u-1);
            
            if(count[u]>2 || count[v]>2){
                f=1;
            }
        }
        
        if(f)cout<<"NO\n";
        else{
            
            
            vector<int>vis(n+1);
            for(int i=0;i<P.size();++i){
                //if(P[i].first>n)continue;
                if(vis[P[i].first])continue;
                
                if(find(P[i].first,P[i].first,graph,vis,0)){
                    f=1;
                    break;
                }
                
            
            }
            
            
            if(f)cout<<"NO\n";
            else cout<<"YES\n";
        }
    }
}
