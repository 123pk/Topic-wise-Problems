/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 322
Approach :- We traverse through the graph and find the smallest weighted edge and that is out answer.
Time Complexity :- O(n+m)
*/
class Solution {
public:
    
    void find(int node,vector<vector<pair<int,int>>>&graph,vector<int>&vis,int& ans){
        vis[node]++;
        
        for(auto&x:graph[node]){
             
            int cur_node = x.first;
            int cur_val = x.second;
            ans = min(ans,cur_val);
            if(vis[cur_node])continue;
            
            find(cur_node,graph,vis,ans);
                 
        }
         
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        //create graph
        vector<vector<pair<int,int>>>graph(n);
        for(auto&x:roads){
            graph[x[0]-1].push_back({x[1]-1,x[2]});
            graph[x[1]-1].push_back({x[0]-1,x[2]});
        }
        vector<int>vis(n);
      //  vector<int>dist(n,INT_MAX);
        int ans = INT_MAX;
        find(0,graph,vis,ans);
        
        
        return ans;
    }
};
