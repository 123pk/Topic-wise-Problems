/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 320
Approach :- We will use DFS and for each node we want to get number of cars coming to that node and number of passenger,
            for fuel we can always add number of cars moving out of this node.
            We will modify the seating arrangement on each nodes baseed on passengers,
            Let x =  pasengers reached node 
            then x+1 will leave as (1)passenger will from current node
            and they will require 'ceil(x+1/seat)' = cars , those many cars will travel 1 unit distance while reaching to parent node and that will cost them 
            'car' liter of fuel.
 Time Complexity :- O(m+n)
*/
class Solution {
public:
    
    pair<long long,long long> dfs(int node,map<int,vector<int>>&tree,int seats,long long& ans,map<int,int>&vis){
        vis[node]++;
        long long cars = 0;
        long long passengers = 0;
        
        for(auto&x:tree[node]){
            if(vis[x])continue;
            pair<long long,long long>temp = dfs(x,tree,seats,ans,vis);
            cars += temp.first;
            passengers += temp.second;
        }
        
        if(node){
            passengers += 1ll;
            long long z = seats;
            cars = passengers/seats;
            if(passengers%seats)cars++;
            ans += cars;
        }
        return {cars,passengers};
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        long long ans = 0;
        int n = roads.size();
        if(n == 0)return ans;
        
        map<int,vector<int>>tree;
        for(auto&x:roads){
            tree[x[0]].push_back(x[1]);
            tree[x[1]].push_back(x[0]);
        }
        map<int,int>vis;
        pair<long long,long long>temp = dfs(0,tree,seats,ans,vis);
        return ans;
    }
};
