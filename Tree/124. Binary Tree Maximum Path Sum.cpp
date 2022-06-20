/*
Platform :- Leetcode
Approach :- We will use dfs and will find (the max_sum_from_left_subtree + max_sum_from_right_subtree + curr_nodevalue) , this will help me in getting the maximum path sum 
*/
class Solution {
public:
    int find(TreeNode* root,int & ans) {
       if(!root)return 0;
        
        int val = 0;
        val = root->val;
        int left = max(0,find(root->left,ans));
        int right = max(0,find(root->right,ans));
        
        ans = max(ans,val + left + right);
        return val+max(left,right);
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        
        int z = find(root,ans);
        return ans;
    }
};
