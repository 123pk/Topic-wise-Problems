/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 289
Approach :- We will do dfs and while returning or backtracking we will also get information regarding maximum no of different characters we can get if we choose that child
           of curren node , we will store the max of all in current node of all values received and we have also option to have a path between two sibling including current
            node.
*/
class Solution {
public:
    //max val store the maximum value for each of the node to its descendents possible
    int find(vector<vector<int>>&graph,int node,int& ans,vector<int>&max_val,string&s){
        
        //if we are at leaf node
        if(graph[node].size() == 0){
            max_val[node] = 1;
            return 1;
        }
        
        for(auto&x:graph[node]){
            int val = find(graph,x,ans,max_val,s);
            if(s[node] != s[x]){
               ans = max(ans,max_val[node]+val);   
               max_val[node] = max(max_val[node],val+1);
            }
        }
        
        return max_val[node];
    }
    
    int longestPath(vector<int>& parent, string s) {
        int ans = 1;
        int n = parent.size();
        vector<vector<int>>graph(n);
        
        for(int i = 1;i<n;++i){
          
            graph[parent[i]].push_back(i);
            
        }
        
        vector<int>max_val(n,1);
         
        int val =  find(graph,0,ans,max_val,s);
        return ans;
    }
};
