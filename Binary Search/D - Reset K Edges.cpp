/*
Platform :- Codeforces
Contest :- Educational Round 136
Appraoch :- Binary search on depth
Time Complexity:- O(n log n)
*/
#include<bits/stdc++.h>
using namespace std;
//we will use dfs in place of bfs
//we will break the edge while coming form left towards the root

int find(int node,vector<vector<int>>&tree,int& k,int&f,int len){
    
    if(tree[node].size() == 0){
        //there are not child 
        return 1;
    }
    
    int val = 0;
    for(auto&x:tree[node]){
        //we will check if the lenght is reached or not if it is reache then we do
        //cut the edge else we don't have the time to do so 
        int temp = find(x,tree,k,f,len);
        if(temp == len){
            if(node){
               // cout<<(node+1)<<" got from "<<(x+1)<<"\n";
                if(k == 0)f=1;
                else k--;
            }
        }
        else val = max(val,temp);
    }
    
    
    return val+1;
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        
        vector<vector<int>>tree(n);
        for(int i=1;i<n;++i){
            int u;
            cin>>u;
            u--;
            tree[u].push_back(i);
        }
        
        //I am using binary search and using that I will find the max height
        int start = 1,end = n,mid = (start+end)/2;
         
        
        int ans  = n;
        
        while(start<=end){
            
            //so I will check if I can achieve a height of mid in k operations or not
            int f = 0,d = k;
             
            int z = find(0,tree,d,f,mid);
            //cout<<mid<<" "<<f<<" "<<k<<"\n";
            if(f){
                //I was not able to 
                //I will increase the hiight
                start = mid+1;
                mid = (start+end)/2;
            }
            else{
                ans = min(ans,mid);
                end = mid-1;
                mid = (start+end)/2;
            }
        }
        
        cout<<ans<<"\n";
    }
}
