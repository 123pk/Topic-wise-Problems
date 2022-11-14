/*
Platform :- Leetcode
Contest :- Bi Weekly contest 91
Approach :- We will first make the graph , maintain one parent array which stores the parent of each node .
            Now we modify the values of nodes in path from ( root to bob node) .
            Now the problem is narrow down to find the path with max sum from root to any of leaf . We will use bfs and the max value is our answer.
Time Complexity :- O(n+e)
*/
class Solution {
public:
    
    
    void find(int i,vector<vector<int>>&graph,vector<int>&vis,vector<int>&parent){
        
        vis[i]++;
        
        for(auto&x:graph[i]){
            if(vis[x])continue;
            parent[x] = i;
            find(x,graph,vis,parent);
        }
        
    }
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        //let us first create a graph
        int n = edges.size() + 1;
        vector<vector<int>>graph(n);
        
        for(auto&x:edges){
            int u = x[0];
            int v = x[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        //now we need to get an array that stores the max we can get from our child 
        vector<int>vis(n),pass(n),parent(n,-1);
        
        find(0,graph,pass,parent);
        vector<int>path(n),pth;
        int start = bob;
        
        while(1){
            path[start]++;
            pth.push_back(start);
            start = parent[start];
            if(start == -1)break;
        }
        reverse(pth.begin(),pth.end());
         int i = 0,j = pth.size()-1;
        int tot = 0;
        while(i<=j){
            if(i == j){
                tot += (amount[pth[i]]/2);
                amount[pth[i]]/=2;
            }
            else{
                tot += (amount[pth[i]]);
                amount[pth[j]] = 0;
            }
            i++;j--;
        }
        
        //I would avaoid using them 
        queue<pair<int,int>>bfs;
        bfs.push({0,amount[0]});
        
         
        vis[0]++;
        int ans = INT_MIN;
        int d = 0;
        while(!bfs.empty()){
            int c = bfs.size();
            for(int i=0;i<c;++i){
                pair<int,int>temp = bfs.front();
                bfs.pop();
                int node = temp.first;
                int value = temp.second;
                int c = -1;
               
                for(auto&x:graph[node]){
                    if(vis[x])continue;
                    vis[x]++;
                    c = 0;
                     
                    int cur = value + amount[x];
                    bfs.push({x,cur});
                }
                if(c == -1){
                    ans = max(ans,value);
                }
            }
        }
        
        
        return ans;
    }
};
