/*
Platform :- Leetcode
Approach :- We will first get all the values of tree and sort them in increasing order , second option is to traverse in "inorder" and get the values they will already be
            in sorted order, now we create a new tree with all the reuqirements , basically we make all the right child to null and attach with left child only.
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
    TreeNode* increasingBST(TreeNode* root) {
        
        queue<TreeNode*>bfs;
        vector<int>temp;
        bfs.push(root);
        while(!bfs.empty()){
            int c = bfs.size();
            for(int i=0;i<c;++i){
                TreeNode* zz = bfs.front();
                bfs.pop();
                
                temp.push_back(zz->val);
                if(zz->left)bfs.push(zz->left);
                if(zz->right)bfs.push(zz->right);
            }
        }
        
        sort(temp.begin(),temp.end());
        
        TreeNode*val;
        for(int i=0;i<temp.size();++i){
            TreeNode* x = new TreeNode;
            x->val = temp[i];
            if(i == 0){
                root = x;
                val = x;
            }
            else{
                val->right = x;
                val = x;
            }
        }
        return root;
    }
};
