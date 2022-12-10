/*
Platform :- Leetcode
Approach :- We will find total sum of all the nodes,then we will do dfs and try to find sum of nodes in subtree of current node, we will find the product if we seperate t
            current node from its ansestor and store the max of all.
Time Complexity :- O(n+e)
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
    long long mod = 1e9+7;
    long long find(TreeNode*node,long long &ans,long long tot){
         if(!node)return 0;

         long long cur = node->val ;
         long long left =  find(node->left,ans,tot) ;
         long long right =  find(node->right,ans,tot);
         long long sum = cur + left + right;

         long long score = (tot-sum);
         score*=sum;
         ans = max(ans,score);
        return sum;

    }
    int maxProduct(TreeNode* root) {
        //its easy
        if(!root)return 0;
       long long ans = 0;

        long long tot = 0;
        queue<TreeNode*>bfs;
        bfs.push(root);
        

        while(!bfs.empty()){
            TreeNode* node = bfs.front();
            bfs.pop();
            tot += node->val;
            if(node->left)bfs.push(node->left);
            if(node->right)bfs.push(node->right);
        }

        int temp = find(root,ans,tot);
        return ans%mod;
    }
};
