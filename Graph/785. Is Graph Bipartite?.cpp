/*
Platform :- Leetcode
Approach :- So since we want to divide our graph into two disjoint segment such that adjacent nodes are in diffenent segment , this problem can be changed to 
            can we color given graph with two color  or not ? If we can then the graph is bipartite else not .
            
            So for doing that we will run a loop from 0 to n-1 and if we haven not colored any node  , then we will do bfs on that nodes and color all the nodes in that
            subgraph, we will try to color adacent nodes with differnt color and if we find any node which is adjacent and have same color as current node then we cannot 
            color our graph using two color and we will return false,
            else if we are able to color all the nodes we will return true
            
Time Complexity :- O(n), as we are visiting any node atmax once 
*/
class Solution {
public:
    
    bool find (int x,vector<vector<int>>&graph,vector<int>&vis){
        //we will visit or color all the nodes that are not colored starting from node 'x'
        queue<pair<int,int>>bfs;
        bfs.push({x,1});
        vis[x] = 1;
        
        while(!bfs.empty()){
            int d = bfs.size();
            for(int i=0;i<d;++i){
                pair<int,int> temp = bfs.front();
                bfs.pop();
                
                int node = temp.first;
                int color = temp.second;
                int option;
                if(color == 1)option = 2;
                else option = 1;
                for(auto&x:graph[node]){
                    //if two adjacent nodes are of same color then graph is not bipartite
                    if(vis[x]){
                        if(vis[x]!=option)return false;
                    }
                    else {
                        vis[x] = option;
                        bfs.push({x,option});
                    }
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n);
        
        
        for(int i=0;i<n;++i){
            if(vis[i])continue;
            if(!find(i,graph,vis))return false;
        }
        return true;
    }
};
