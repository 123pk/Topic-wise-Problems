/*
Platform :- Leetcode
Approach :- You need to see those points as node and create one undirected weighted connected graph with weight between two nodes [i,j] = manhattan distance between
            ( points[i] & points[j] ) . Now for that graph we need to find the MST and sum of weights is our answer . 
            I have used prims algorithm for the following .
Time Complexity :- O(E log N)
*/

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int ans = 0;
        
        /*
        Appproach is to consider each point as a node and we create a connected graph 
        then the minimum spanning tree and sum of edge weight or cost (manhattan distance) is our answer
        */
        
        int n = points.size();
        vector<pair<int,int>>graph[n];
        
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                //so we have an edge from i,j
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                graph[i].push_back({dist,j});
                graph[j].push_back({dist,i});
            }
        }
        
        priority_queue<pair<int,int>>P;
        for(auto&x:graph[0]){
            P.push({-x.first,x.second});
        }
        
        vector<int>vis(n);
        int count = 1;
        vis[0]++;
        while(!P.empty()){
            pair<int,int>temp = P.top();
            P.pop();
            int node = temp.second;
            int cost = abs(temp.first);
            
            if(vis[node] == 0){
                vis[node]++;
                ans += cost;
                count++;
                for(auto&x:graph[node]){
                    if(vis[x.second])continue;
                    P.push({-x.first,x.second});
                }
            }
            if(count == n)break;
        }
        
        
        return ans;
    }
};
