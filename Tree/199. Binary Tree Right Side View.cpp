/*
Platform :- Leetcode
Approach :- We will do level order traverl and last node value at each level is added in our answer array as all the values before it cannot be seem from right side.
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(!root)return ans;
        
        queue<TreeNode*>bfs;
        bfs.push(root);
        while(!bfs.empty()){
            int c = bfs.size();
            int node = -1;
            for(int i=0;i<c;++i){
                TreeNode* temp = bfs.front();
                bfs.pop();
                
                node = temp->val;
                
                if(temp->left)bfs.push(temp->left);
                if(temp->right)bfs.push(temp->right);
            }
            ans.push_back(node);
        }
        
        return ans;
    }
};
