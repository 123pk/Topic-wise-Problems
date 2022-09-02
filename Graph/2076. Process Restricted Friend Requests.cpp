/*
Platform :- Leetcode
Approach :- For each of the requests(u,v) we will traverse through the array and find parent of each node in subtree of (u) and subtree of (v) and now we traverse through 
            the restrictions and check if ( parent[x] == parent[u] ) and  ( parent[y] == parent[v] ) or 'vice versa' this means we have restricted nodes in subtrees so we cannot
            join or fulfill this request and we add 'false' else we add 'true'
            
Time Complexity :- O(n*n)
*/
class Solution {
public:
    int traversal(int node,vector<vector<int>>&dsu,vector<int>&parent){
        queue<int>bfs;
        bfs.push(node);
        int n = dsu.size();
        vector<int>vis(n);
        int mn = INT_MAX;
        vis[node]++;
        
        while(!bfs.empty()){
            node = bfs.front();
            bfs.pop();
            mn = min(mn,node);
            
            for(auto&x:dsu[node]){
                if(vis[x])continue;
                bfs.push(x);
                vis[x]++;
            }
        }
        vis.clear();
        
        vis.resize(n);
        bfs.push(node);
        while(!bfs.empty()){
            node = bfs.front();
            bfs.pop();
            parent[node] = mn+1;
            
            for(auto&x:dsu[node]){
                if(vis[x])continue;
                bfs.push(x);
                vis[x]++;
            }
        }
        vis.clear();
        return mn+1;
    }
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<bool>ans;
        vector<int>fre(n);
        vector<vector<int>>dsu(n);
        for(auto&x:requests){
            int u = min(x[0],x[1]);
            int v = max(x[0],x[1]);
            
            fre.clear();
            fre.resize(n);
            
            int p1 = traversal(u,dsu,fre);
            int p2 = traversal(v,dsu,fre);
            
            int f = 0;
            for(auto&y:restrictions){
                if(p1 && p2 &&(fre[y[0]] == p1 && fre[y[1]] == p2) || (fre[y[0]] == p2 && fre[y[1]] == p1)){
                    f=1;
                    break;
                }
            }
            
            fre.clear();
            if(f)ans.push_back(false);
            else{
                dsu[u].push_back(v);
                dsu[v].push_back(u);
                ans.push_back(true);
            }
        }
        return ans;
    }
};
