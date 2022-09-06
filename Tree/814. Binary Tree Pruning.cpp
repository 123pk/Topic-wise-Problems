/*
Platform :- Leetcode
Apporach :- We will do dfs and will take care from where we get the '1' ( in left subtree or right) ,  we remove the edge which doesnot give us '1' or which does not
            contain '1' (left child or right child edge).
            
Time Complexity :- O(n) --> n = number of edges
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
    
    bool find(TreeNode*node){
        if(!node)return false;
        int f = 0;
        int g = 0;
        if(find(node->left))f =1;
        if(find(node->right))g = 1;
        if(f||g){
            if(f == 0 )node->left = NULL;
            if(g == 0)node->right = NULL;
            return true;
        }
        else {
            if(node->val == 1){
                
                node->left = NULL;
                node->right = NULL;
                return true;
            }
            return false;
        }
    }
    TreeNode* pruneTree(TreeNode* root) {
        
        if(!root)return NULL;
        
        if(find(root)){
            return root;
        }
        return NULL;
    }
};
