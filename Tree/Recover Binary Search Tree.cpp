/*
Platform :- Leetcode
Approach :- Inorder + Greedy implementaion
*/
vector<pair<TreeNode*,TreeNode*>> vec;
    TreeNode* prev = NULL;
    void inorder(TreeNode* root)
    {
        if(!root) return;
        inorder(root->left);
        if(prev && prev->val>root->val) vec.push_back({prev,root});
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        if(vec.size()==1)
            swap(vec[0].first->val,vec[0].second->val);
        if(vec.size()==2)
            swap(vec[0].first->val,vec[1].second->val);
    }
