/*
Platform :- Leetcode
Approach :- BFS and store sum of nodes from root to current node, if we are at leaf and sum is equal to target we have the path .

Time Complexity :- O(n)
*/
class Solution {
public:
    
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
       if(!root)return false;
        
        queue<pair<TreeNode*,int>>bfs;
        bfs.push({root,root->val});
        
        while(!bfs.empty()){
            TreeNode* node = bfs.front().first;
            int val = bfs.front().second;
            bfs.pop();
            if(!node->left && !node->right){
                if(val == targetSum)return true;
            }
            
            if(node->left)
                bfs.push({node->left,val + node->left->val});
            
            if(node->right)
                bfs.push({node->right,val + node->right->val});
        }
        return false;
    }
    
     
};
