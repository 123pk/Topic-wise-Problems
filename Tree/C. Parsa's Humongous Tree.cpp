/*
Platform :- Codeforces
Contest :- Codeforces Round 722 Div 2
Approach :- We do dfs and while coming back from leaf we check what will happen if we choose [l] and [r] from {l,r} It is optimal to chose the bounday points .
*/
#include<bits/stdc++.h>
using namespace std;

pair<long long,long long> helper;
//long long c,d,e,f;

pair<long long,long long> find(int node,vector<vector<int>>&tree,vector<int>&vis,vector<pair<long long,long long>>&value,long long&ans){
    
    vis[node]++;
    
    long long val1 = 0;
    long long val2 = 0;
  //  c = value[node].first;
   // d = value[node].second;
    
    for(auto&x:tree[node]){
        if(vis[x])continue;
        vis[x]++;
        helper = find(x,tree,vis,value,ans);
        long long a = helper.first;
        long long b = helper.second;
        
     //   e = value[x].first;
     //   f = value[x].second;
        val1 += max(abs(value[node].first-value[x].first)+a,abs(value[node].first-value[x].second)+b);
        val2 += max(abs(value[node].second-value[x].first)+a,abs(value[node].second-value[x].second)+b);
    }
    
    ans = max(val1,val2);
    return {val1,val2};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<pair<long long,long long>>value(n);
        for(int i=0;i<n;++i)cin>>value[i].first>>value[i].second;
        
        //now make the tree
        vector<vector<int>>tree(n);
        for(int i=1;i<n;++i){
            int u,v;
            cin>>u>>v;
            u--;
            v--;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        
        //now what we will maintain two values one where we choose the max value and one in which we choose the min value
        
        long long ans = 0;
        vector<int>vis(n);
        helper = find(0,tree,vis,value,ans);
        
        
        cout<<ans<<"\n";
    }
}
