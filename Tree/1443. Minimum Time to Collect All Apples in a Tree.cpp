/*
Platform :- Leetcode
Approach :- We will do dfs and if there is any apple in descendents of current node then we need to add cost of '2' , '1' for going down and '1' for coming up till here
            So we get boolean value returned to us , which state that there is any apple with descendents of current node or not ,if yes we add '2' to our sum
Time Complexity :- O(n+m)
*/
class Solution {
public:
    int find(int node,vector<vector<int>>&tree,int n,vector<bool>&apple,vector<int>&vis,int& sum){
        vis[node]++;
        
        int f = 0;
        
        for(auto&x:tree[node]){
            if(vis[x])continue;
            if(find(x,tree,n,apple,vis,sum)){
                sum += 2;
                f = 1;
            }
        }


        if(f || apple[node])return true;
        return false;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        vector<int>vis(n);
        vector<vector<int>>tree(n);
        for(auto&x:edges){
            tree[x[0]].push_back(x[1]);
            tree[x[1]].push_back(x[0]);
        }
        int sum = 0;
        bool ans = find(0,tree,n,hasApple,vis,sum);
        return sum;
    }
};
