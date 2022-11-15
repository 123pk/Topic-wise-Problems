
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
    
    void find(TreeNode*root,int &d){
        if(!root)return;
        d++;
        find(root->left,d);
        find(root->right,d);
    }
    int countNodes(TreeNode* root) {
        int d=0;
        find(root,d);
        return d;
    }
};
