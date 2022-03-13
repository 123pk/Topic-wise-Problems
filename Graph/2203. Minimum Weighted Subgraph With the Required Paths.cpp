/*
Platform :- Leecode
Contest :- Leetcode Weekly contest 284
Approach :- You need to use pen and paper and think about it , We will use three dijkstra one for 'src1' ,one for'src2' and one for 'dest' , we will create two graph one that is 
            given and other one has reverse direction of edges ( we will use this to go from destination to source nodes) .
            Now if it is not possible to reach from any of source nodes then the answer is -1 else the min cost is( cost_to_reach_dest_from_src1 + cost_to_reach_dest_from_src2)
            and for all the common points/nodes we can visit from all the three , we will find ( cost1[i] + cost2[i] + cost3[i] ) and min of all such value is answer.
*/
void find(vector<vector<pair<int,int>>>&graph,int start,vector<long long>&cost){
   
    priority_queue<pair<long long,int>,vector<pair<long long,int>> , greater<pair<long long,int>>>bfs;
    bfs.push({0ll,start});
    
    int node;
    long long value , sum;
    pair<long long,int>temp;
    
    
    while(!bfs.empty()){
        int c = bfs.size();
        
        for(int i=0;i<c;++i){
            temp = bfs.top();
            bfs.pop();
            
            node = temp.second;
            value = temp.first;
            if(value!=cost[node])continue;
            
            for(auto&x:graph[node]){
                sum = value + x.second;
                
                if(cost[x.first]>sum){
                    cost[x.first] = sum;
                    bfs.push({sum,x.first});
                }
            }
            
        }
    }
}


class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        long long ans = -1;
        
        //if there is no path from any of source node to dest node return -1
        
        //basic approach is to find the 
        vector<vector<pair<int,int>>>graph(n),rev_graph(n);
        for(int i=0;i<edges.size();++i){
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            rev_graph[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        //basic approach now is to find the min cost of visiting all other points 
        //first we find min cost to vist each node that can be reached from source 1
        vector<long long>cost1(n,1e18),cost2(n,1e18),cost3(n,1e18);
        
        int f = 0;
        cost1[src1] = 0;
        cost2[src2] = 0;
        cost3[dest] = 0;
        
        find(graph,src1,cost1);
        if(cost1[dest] == 1e18)return -1;
        
        find(graph,src2,cost2);
        if(cost2[dest] == 1e18)return -1;
        
        find(rev_graph,dest,cost3);
        
        //now we will do simple traversal and when we have any common node
        ans = cost1[dest] + cost2[dest];
        
        //now we will look for common values or values that can be reached by all the three 
        long long tot_sum;
        for(int i=0;i<n;++i){
            if(cost1[i]!=1e18 && cost2[i]!=1e18 && cost3[i]!=1e18){
                tot_sum = cost1[i] + cost2[i] + cost3[i];
                ans = min(ans,tot_sum);
            }
        }
        
        return ans;
    }
};
