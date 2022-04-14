/*
Platform :- Leetcode
Approach :- Since it is a BST we know that all the values to the left are smaller than current value of node and all the values to the right are greater 
            we will look for value if we found the values we will get the values in subtree and retun it
*/
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        //if root is null return null
        if(!root) return root;
        //create node to return 
        TreeNode *node=new TreeNode(); 
        // if root->val != val,search in left and right
        //otherwise this would be required node and we would return it
        if(val<root->val){
            //search in left 
            node=searchBST(root->left,val);
        } else if(val>root->val){
            //search in right
            node=searchBST(root->right,val);
        } else {
            //required node
            node=root;
        }
        return node;
    }
};
