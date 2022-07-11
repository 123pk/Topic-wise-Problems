/*
Platform :- Codeforces
Contest :- Codeforces Round 805 Div 3
Approach :- For each query we find the end two points , basically if we consider diameter then we want to finnd the end points of diameter ( end points of path) , now
            we will find distance of each node from one of the end point and we will traverse throgh one of the end point and will check if we get the values in increasing
            order of distance or not , if we reach till the last node then its a valid path else not .
Time complexity :- O(nlogn * q ) since q is small it is O(n log n)
*/
#include<bits/stdc++.h>
using namespace std;

vector<int>randm;
int find(vector<vector<int>>&tree,int node,int n,set<int>&unq,int flag){
    
    vector<int>vis(n);
    //node and their occurence in order
    vector<pair<int,int>>details;
    
    queue<pair<int,int>>bfs;
    bfs.push({node,0});
    vis[node]++;
    int req = node;
    int mx = 0;
    if(flag)details.push_back({0,node});
    
    while(!bfs.empty()){
        int c = bfs.size();
        for(int i=0;i<c;++i){
            pair<int,int>temp = bfs.front();
            bfs.pop();
            int x = temp.first;
            int val = temp.second;
            
            for(auto&y:tree[x]){
                if(vis[y])continue;
                vis[y]++;
                if(unq.find(y) != unq.end()){
                    if(flag)details.push_back({val+1,y});
                    if(mx<(val+1)){
                        mx = val+1;
                        req = y;
                    }
                }
                bfs.push({y,val+1});
            }
        }
    }
    
    if(flag){
        randm.clear();
        sort(details.begin(),details.end());
        
        for(auto&x:details){
            randm.push_back(x.second);
        }
    }
    return req;
}

int main(){
    int n;
    cin>>n;
    
    vector<vector<int>>tree(n);
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    int q;
    cin>>q;
    
    for(int i=0;i<q;++i){
        int k;
        cin>>k;
        
        set<int>B;
        int x;
        for(int j=0;j<k;++j){
            cin>>x;
            x--;
            B.insert(x);
        }
        
        int node = *B.begin();
        int start =  find(tree,node,n,B,0);
        
        int end = find(tree,start,n,B,1);
        
        queue<pair<int,int>>bfs;
        bfs.push({start,0});
        vector<int>vis(n);
        vis[start]++;
        int f = 0;
       // cout<<i+1<<" -- > "<<endl;
        while(!bfs.empty()){
            int c = bfs.size();
          //  cout<<c<<endl;
            for(int j=0;j<c;++j){
                pair<int,int> temp = bfs.front();
                bfs.pop();
                int node_val = temp.first;
                int idx = temp.second;
               // cout<<node_val+1<<" "<<idx+1<<endl;
                if(idx == k-1 && node_val == randm[k-1]){
                    f=1;break;
                }
                
                for(auto&x:tree[node_val]){
                    if(vis[x])continue;
                    vis[x]++;
                    if(x == randm[idx+1]){
                        bfs.push({x,idx+1});
                    }
                    else bfs.push({x,idx});
                }
                
            }
            if(f)break;
        }
        
        if(f)cout<<"YES\n";
        else cout<<"NO\n";
        
    }
}
