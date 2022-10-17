/*
Platform :- Codeforces
Contest :- Educational Round 136
Appraoch :- Binary search on depth
Time Complexity:- O(n log n)
*/
#include<bits/stdc++.h>
using namespace std;

void check(int start,vector<vector<int>>&tree,int len,int& f,int k){
    
    queue<pair<int,int>>bfs;
    bfs.push({start,0});
  //  cout<<start<<" "<<len<<" "<<f<<" "<<k<<"\n";
    
    while(!bfs.empty()){
        pair<int,int>temp = bfs.front();
        int node = temp.first;
        int depth = temp.second;
        bfs.pop();
        if(len == 2){
            cout<<node+1<<" "<<depth<<" "<<k<<"\n";
        }
        for(auto&x:tree[node]){
            if(depth == len){
                //I need to cut this node
                //edge
                if(k == 0){
                    f=1;
                    //I cannot delete the node
                    break;
                }
                k--;
                bfs.push({x,1});
            }
            else{
                bfs.push({x,depth+1});
            }
        }
        
        if(f)break;
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
            int f = 0;
            
            check(0,tree,mid,f,k);
            
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
