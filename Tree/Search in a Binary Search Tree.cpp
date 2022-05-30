/*
Platform :- Leetcode
Approach :- Do DFS and ass soon as we foudn the value we store in a variable and at the end we return it
*/
class Solution {
public:
    TreeNode* ans ;
    void find(TreeNode*node,int value,int& f){
        if(f)return;
        
        if(!node)return ;
        if(node->val == value){
            f=1;
            ans = node;
            return;
        }
        find(node->left,value,f);
        find(node->right,value,f);
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        
        int f = 0;
        find(root,val,f);
        return ans;
    }
};
