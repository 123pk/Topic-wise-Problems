/*
Platform :- Leetcode
Apporach :- We will maintain one variable that will help us in telling if we are at odd level or even , we know in BFS we store the elements from left to right way ,
            so we will maintain a vector to store elements at each level , if the variable which give information about level of tree is "odd" then we reverse the array
            and add in our answer elese we add it unchanged.
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        
        if(!root)return ans;
        
        queue<TreeNode*>bfs;
        bfs.push(root);
        
        vector<int>element;
        int d = 0;
        while(!bfs.empty()){
            int c = bfs.size();
            element.clear();
            
            for(int i=0;i<c;++i){
                TreeNode* temp = bfs.front();
                bfs.pop();
                element.push_back(temp->val);
                
                if(temp->left){
                   bfs.push(temp->left);   
                }
                
                if(temp->right){
                    bfs.push(temp->right);
                }
            }
            d++;
            if(d%2 == 0)reverse(element.begin(),element.end());
            ans.push_back(element);
            
        }
        
        return ans;
    }
};
