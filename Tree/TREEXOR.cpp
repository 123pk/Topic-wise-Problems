/*
Platform :- Codechef
Contest :- Codechef starters 48 Div 2
Approach :- We will first sort the nodes by level where root is at level '1' and leaf is at 'd' where 'd' is the depth of tree . Now we will sort nodes by decreasing order
            of their level and assign first 'k' values with '1' , now we will make sure than all the nodes will assigned in such a way that the xor value of their subtree is '0'
*/
#include<bits/stdc++.h>
using namespace std;

int find(int node,vector<vector<int>>&tree,vector<int>&xor_val,vector<int>&ans){
    
    if(tree[node].size() == 0){
        return ans[node] = xor_val[node];
    }
    
    int cur = 0;
    for(auto&x:tree[node]){
        cur = cur xor find(x,tree,xor_val,ans);
    }
  // cout<<cur<<" "<<xor_val[node]<<endl;
    
    if(cur == xor_val[node]){
        if(cur)ans[node] = 0;
        else ans[node] = cur;
        return xor_val[node];
    }
    else {
        ans[node] = cur xor xor_val[node];
        return xor_val[node];
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        
        vector<vector<int>>tree(n);
        for(int i=1;i<n;++i){
            int parent;
            cin>>parent;
            tree[parent-1].push_back(i);
        }
        
        // now letus find level of each node we will assign value from the very end
        vector<pair<int,int>>level;
        queue<pair<int,int>>bfs;
        vector<int>vis(n);
        bfs.push({0,1});
        vis[0]++;
        
        while(!bfs.empty()){
            int c = bfs.size();
            for(int i=0;i<c;++i){
                pair<int,int>temp = bfs.front();
                bfs.pop();
                int node = temp.first;
                int lvl = temp.second;
                level.push_back({lvl,node});
                
                
                for(auto&x:tree[node]){
                    if(vis[x])continue;
                    vis[x]++;
                    bfs.push({x,lvl+1});
                }
            }
        }
        
        sort(level.begin(),level.end());
        reverse(level.begin(),level.end());
        
        vector<int>xor_val(n);
        for(int i=0;i<k;++i){
          xor_val[level[i].second] = 1;   
        }
        
        //now let us make changes in main string 
        vector<int>ans(n);
        
        int value = find(0,tree,xor_val,ans);
        
        for(auto&x:ans)cout<<x;
        cout<<"\n";
    }
}
