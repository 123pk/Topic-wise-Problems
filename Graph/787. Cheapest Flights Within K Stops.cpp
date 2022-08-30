/*
Platform :- Leetcode
Approach :- We create a 3d dp where dp[i][j][k] -- stoers the min cost of flight to reach from 'i' to 'j' with 'k' stopage
            We do bfs (greedily) always choosing the path with minimum cost (dijkstra) or we can also use bellman ford .
            We store the min cost for each of the instances. 
            At the end we want the min feasible value for dp[src][dst][i] --- i =0 to k
Runtime :- O(n*m*k)
*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int dp[n][n][k+1];
        
        //let us create the graph
        vector<vector<pair<int,int>>>graph(n);
        for(auto&x:flights){
            graph[x[0]].push_back({x[1],x[2]});
            //u --- {v,cost}
        }
        
        
        //this dp[i][j][k] will store the min cost to reach out j from i with k stopage in between
        memset(dp,-1,sizeof(dp));
        
        //now we will do bfs making src as root node
        //we are storing {cost,{node,ith halt}}
        
        priority_queue<pair<int,pair<int,int>>>bfs;
        bfs.push({0,{src,-1}});
        dp[src][src][0] = 0;
        
        while(!bfs.empty()){
            int sz = bfs.size();
            for(int i=0;i<sz;++i){
                pair<int,pair<int,int>>temp = bfs.top();
                bfs.pop();
                int node = temp.second.first;
                int cost = abs(temp.first);
                int halt = temp.second.second;
               // cout<<node<<" "<<cost<<" "<<halt<<"\n";
                if(halt >= k){
                    //then there is no need to loo again
                    continue;
                }
                
                for(auto&x:graph[node]){
                    int y = x.first;
                    int val = x.second;
                    int cur_tot = cost + val;
                    if(dp[src][y][halt+1] != -1){
                        //now we will check if we are getting better price or not
                        
                        if(dp[src][y][halt+1] > cur_tot){
                            dp[src][y][halt+1] = cur_tot;
                            bfs.push({-cur_tot,{y,halt+1}});
                        }
                    }
                    else{
                        dp[src][y][halt+1] = cur_tot;
                        bfs.push({-cur_tot,{y,halt+1}});
                    }
                }
            }
        }
       // cout<<"\n";
        
        int val = -1;
        for(int i=0;i<=k;++i){
            if(dp[src][dst][i] == -1)continue;
            else if(val == -1)val = dp[src][dst][i];
            else val = min(val,dp[src][dst][i]);
        }
        
        return val;
    }
};
