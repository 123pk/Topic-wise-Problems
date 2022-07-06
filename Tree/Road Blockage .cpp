/*
Platform :- Geeksforgeeks
Contest :- Geek-A-thon 10 Amazon Alexa SDE hiring
Approach :- 
*/
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    int find(int node,vector<vector<int>>&tree,int parent,vector<int>&cost){
        
        int val = 0;
        
        for(auto&x:tree[node]){
           if(x == parent)continue;
           val = max(val,find(x,tree,node,cost));
        }
        cost[node] = val;
        return cost[node]+1;
    }
  
    vector<int> solve(int n, int q, vector<vector<int> > &edge,
                      vector<vector<int> > &query) {
        // code here
        vector<int>ans;
        
        vector<int>cost(n),parent(n);
        vector<vector<int>>tree(n);
        for(auto&x:edge){
            tree[x[0]].push_back(x[1]);
            tree[x[1]].push_back(x[0]);
        }
        
        //now using bfs let us find parent of each node
        queue<int>bfs;
        bfs.push(0);
        vector<int>vis(n);
        vis[0]++;
        //this means root has no parent
        parent[0] = -1;
        while(!bfs.empty()){
            int c = bfs.size();
            for(int i=0;i<c;++i){
                int node = bfs.front();
                bfs.pop();
                
                for(auto&x:tree[node]){
                    if(vis[x])continue;
                    parent[x] = node;
                    vis[x]++;
                    bfs.push(x);
                }
            }
        }
        
        
        //so basic approach to answer queries is to 
        //change only value in path from current node to 
        //root node
        
        //now let us fill our cost array whih store the length of max
        //distance we can reach from current node to leaf node
        int val = find(0,tree,-1,cost);
        
        
        //now let us check the array
       /* for(int i=0;i<n;++i){
            cout<<" for "<<i+1<<" the max value is "<<cost[i]<<"\n";
        }
        */
        //we will do changes in path from current node to root node
        //we will also take care of repeating query
        map<pair<int,int>,int>repeat;
        for(int i=0;i<q;++i){
            int u,v;
            u = query[i][0];
            v = query[i][1];
            
            //avoid repeating
            if(repeat[{min(u,v),max(u,v)}]){
                ans.push_back(repeat[{min(u,v),max(u,v)}]-1);
                continue;
            }
            
            
            int node,child;
            if(parent[u] == v){
                node = v;
                child = u;
            }
            else{
                node = u;
                child = v;
            }
            
            int f = 0,val = 0,child_val = 0,c = 0;
            //cout<<node<<" "<<child<<"\n";
            while(1){
                
                //go to all the childrends except the child one 
                for(auto&x:tree[node]){
                    if(x == parent[node])continue;
                    
                    if(x == child){
                        if(c)val= max(val,child_val+1);
                        else val = max(val,child_val);
                        continue;
                    }
                    if(cost[x]+1 == cost[node]){
                        f = 1;break;
                    }
                    val = max(val,cost[x]+1);
                   // if(u == 1)cout<<x<<" "<<cost[x]<<"\n";
                }
                if(f)break;
                
                if(parent[node] == -1)break;
                child = node;
                child_val = max(child_val,val);
                node = parent[node];
                c++;
            }
            if(f)val = cost[0];
             repeat[{min(u,v),max(u,v)}] = val+1;
                ans.push_back(val);
             
        }
        return ans;
    }
};

 
