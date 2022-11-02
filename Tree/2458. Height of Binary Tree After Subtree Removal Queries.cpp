/*
Platform  :- Leetcode
Contest :- Weekly contest 317
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int dfs(TreeNode*node,vector<pair<int,int>>&depth,int& mx){
        
        if(!node)return 0;
        mx = max(mx,node->val);
        int val1 = dfs(node->left,depth) ;
        int val2 = dfs(node->right,depth);
        //cout<<node->val<<" "<<val1<<" "<<val2<<"\n";
        depth[node->val] = {val1,val2};
        return 1+max(val1,val2);
    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int>ans;
        
        /*
        So the approach is to store the max depth and second max depth at each level
        of tree , when we have a node we go to its parent and if the max_depth for that node
        is equal to max_depth of this node return value then we get the second max
        */
        
        if(!root)return ans;
        int lim = 1e5;
        vector<pair<int,int>>lvl_depth(lim),depth(lim);
        int mx = 0;
        int val = dfs(root,depth,mx);
        
        queue<TreeNode*>bfs;
        bfs.push(root);
        
        vector<int>level(mx+1);
        int c = 0;
        while(!bfs.empty()){
            int sz = bfs.size();
            int m1 = 0,m2 = 0;
            for(int i=0;i<sz;++i){
                TreeNode*node = bfs.front();
                bfs.pop();
                
                int value = node->val;
                if(node->left){
                    
                }
                
                if(node->right){
                    
                }
            }
            lvl_depth[c] = {m1,m2};
            c++;
        }
        
        return ans;
    }
};
