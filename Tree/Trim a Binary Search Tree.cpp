/*
Platform :- Leetcode
Approach :- This is problem similar to deleting a node from BST , we will first find all the values to be removed and then it becomes same we need to remove all of them
            from BST, few things to node after each deleting the parents need to be updated.
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        while(root != NULL && (root->val < low || root->val > high)){
            if(root->val < low)root = root->right;
            else root = root->left;
        }
        if(root == NULL)return NULL;
        TreeNode* left = trimBST(root->left, low, high);
        TreeNode* right = trimBST(root->right, low, high);
        root->left = left;
        root->right = right;
        return root;
    }
};
