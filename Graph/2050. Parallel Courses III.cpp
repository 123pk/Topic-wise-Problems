/*
Platform :- Leetcode
Quality :- Very good
Approach :- We will use topological sort we will start with nodes which have no incoming edge , we will also maintain one max_time array which will store the max_time 
            it will require to comlete ith subject .
            We maintain one count array which is basically the no of incoming edges for each node , we do bfs and reduce the count of node if count[node] == 0, we add in 
            bfs traversal with max_time .
            At the end the max time out of all subjects to finish is our required answer.
Time Complexity :- O(E+N log n)
*/
class Solution {
public:
    
    int dfs(int node,vector<vector<int>>&graph,vector<int>&cost,vector<int>&time,vector<int>&count){
        
        int tot = 0;
        
        for(auto&x:graph[node]){
            count[x]--;
            if(count[x] == 0){
                tot = max(tot,dfs(x,graph,cost,time,count));
            }
        }
        
        return cost[node] = tot +  time[node];
    }
    
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        //so the approach is to create a graph and check for cycles in connected components
        //if there is any cycle then we cannot finit it 
        //else the max time to finisht the course/visit all connected noded in that component is our answerr
        
        vector<vector<int>>graph(n);
        vector<int>count(n);
        //we will have edge from pre-requisite to subject
        for(auto&x:relations){
            graph[x[0]-1].push_back(x[1]-1);
            
            //this is count of parents we have
            count[x[1]-1]++;
        }
        
        vector<int>vis(n);
        vector<int>dist(n);
        queue<pair<int,int>>bfs;
        for(int i=0;i<n;++i){
            if(count[i] == 0){
                //do the bfs
                //int val = dfs(i,graph,dist,time,count);
                bfs.push({i,time[i]});
                dist[i] = time[i];
            }
        }
        
        int ans = 0;
        //we will not lookf or cycles as it is given we have acyclic graph
       while(!bfs.empty()){
           pair<int,int>temp = bfs.front();
           bfs.pop();
           int node = temp.first;
           int cost = temp.second;
           
           for(auto&x:graph[node]){
               count[x]--;
               if(count[x] == 0){
                   dist[x] = max(dist[x],cost+time[x]);
                   bfs.push({x,dist[x]});
               }
               else{
                   dist[x] = max(dist[x],cost+time[x]);
               }
           }
       }
         
        for(auto&x:dist)ans = max(ans,x);
        return ans;
    }
};
