/*
Platform :- Leetcode
Approach :- We will use dijkstra algorithms with priority on minimum cost/fees path first . We can use set of pair where first element is the element with smallest
            cost/fees . 
            We will move along the path if the 'time_take <= maxTime' , 
            -- Then we will check for cost , if cost to reach node 'x' is less than already stored value to reach there then we update it and do traversal again
            --- Else we look for minimum time to reach current node if that can be modified we again take it in consideration and do traversal again
*/
class Solution {
public:
    int dp[1001],st[1001];
    int minCost(int mxtime, vector<vector<int>>& edges, vector<int>& fees) {
        
        int n = fees.size();
        for(int i=0;i<n;++i){
            dp[i] = st[i] = INT_MAX;
        } 
        vector<vector<int>>graph[n];
        for(auto&x:edges){ 
            graph[x[0]].push_back({x[1],x[2]});
            graph[x[1]].push_back({x[0],x[2]});
        }
        
         
        set<pair<int,pair<int,int>>>P;
        P.insert({fees[0],{0,0}});
         
        
        while(!P.empty()){
            auto it = P.begin();
            pair<int,pair<int,int>>temp = *it;
            P.erase(it);
            int cost = temp.first;
            int tm = temp.second.first;
            int node = temp.second.second;
            
           // cout<<tm<<" "<<cost<<" "<<node<<"\n";
            
            for(auto&x:graph[node]){
                 
                int cur_time = x[1];
                cur_time += tm;
                
                if(cur_time <= mxtime){
                    int cur_cost = fees[x[0]] + cost;
                    if(dp[x[0]]>cur_cost){
                        dp[x[0]] = cur_cost;
                        st[x[0]] = cur_time;
                        P.insert({cur_cost,{cur_time,x[0]}});
                    }
                    else if(st[x[0]]>cur_time){
                        st[x[0]] = cur_time;
                        P.insert({cur_cost,{cur_time,x[0]}});
                    }
                }
            }
        }
        if(dp[n-1] == INT_MAX)return -1;
        return dp[n-1];
    }
};
