#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>&P,pair<int,int>&Q){
    if(P.first == Q.first){
        return P.second<Q.second;
    }
    return P.first<Q.first;
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<int>dp(n);
        vector<int>graph[n],graph2[n],graph3[n];
        int u,v;
        for(int i=0;i<m;++i){
            cin>>u>>v;
            u--;
            v--;
            graph[min(u,v)].push_back(max(u,v));
            graph2[u].push_back(v);
            graph2[v].push_back(u);
            graph3[u].push_back(v);
            graph3[v].push_back(u);
        }
         
        vector<pair<int,int>>P;
        int mx = 0;
        for(int i=0;i<n;++i){ 
            sort(graph[i].begin(),graph[i].end());
            if(graph[i].size()){
                P.push_back({min(i,graph[i][graph[i].size()-1]),max(i,graph[i][graph[i].size()-1])});
            }
            else{
                if(mx<=i){
                    P.push_back({i,i});
                    mx = i;
                }
            }
        }
        
        for(int i=1;i<n;++i){
            dp[i] = dp[i-1]+1;
        }
        
        sort(P.begin(),P.end(),comp);
        vector<int>vis2(n);
        vector<int>temp2;
        for(int i=0;i<n;++i){
            if(vis2[i])continue;
            queue<int>bfs;
            temp2.clear();
            bfs.push(i);
            vis2[i]++;
            int mx = dp[i];
            temp2.push_back(i);
            while(!bfs.empty()){
                int c = bfs.size();
                for(int i = 0;i<c;++i){
                    int val = bfs.front();
                    bfs.pop();
                    for(auto&x:graph3[val]){
                        if(vis2[x])continue;
                        vis2[x]++;
                        temp2.push_back(x);
                        bfs.push(x);
                        mx = min(mx,dp[x]);
                    }
                }
            }
            
            for(auto&x:temp2){
                dp[x] = min(dp[x],mx);
            }
        }
        
        
        for(int i=0;i<P.size();++i){
            
            dp[P[i].second] = min(dp[P[i].second],dp[P[i].first]);
             
        }
        for(int i=0;i<n;++i){
            dp[i] = min(dp[i],dp[i-1]+1);
            //cout<<dp[i]<<" ";
        }
        vector<int>vis(n);
        vector<int>temp;
        for(int i=0;i<n;++i){
            if(vis[i])continue;
            queue<int>bfs;
            temp.clear();
            bfs.push(i);
            vis[i]++;
            int mx = dp[i];
            temp.push_back(i);
            while(!bfs.empty()){
                int c = bfs.size();
                for(int i = 0;i<c;++i){
                    int val = bfs.front();
                    bfs.pop();
                    for(auto&x:graph2[val]){
                        if(vis[x])continue;
                        vis[x]++;
                        temp.push_back(x);
                        bfs.push(x);
                        mx = min(mx,dp[x]);
                    }
                }
            }
            
            for(auto&x:temp){
                dp[x] = min(mx,dp[x]);
            }
        }
        
        for(int i=0;i<n;++i){
            dp[i] = min(dp[i],dp[i-1]+1);
            //cout<<dp[i]<<" ";
        }
       // cout<<" --- ";
        cout<<dp[n-1]<<"\n";
    }
}
