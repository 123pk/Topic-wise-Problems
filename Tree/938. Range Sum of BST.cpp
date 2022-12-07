
/*
Platform :- Leetcode
Approach :- We do dfs traversal and check if the node value is in range or not if it is then we add to our sum else leave.
Time Complexity :- O(n+e)
*/
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)return 0;
        int val = 0;
        if(low <= root->val && root->val <= high)val = root->val; 
        
        return val + rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
    }
};
