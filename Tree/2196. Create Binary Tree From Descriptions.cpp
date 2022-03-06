/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 283
Approach :- Brutforces , we just mintain a array of pointer where each poiter points to ith node, we also use compression to make the value of nodes in range [1 to n] for easy operation
            then to find root , the node which dont have any parent is our root , apart from that we add child of ith node based on given information .
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
    TreeNode* createBinaryTree(vector<vector<int>>& description) {
        TreeNode*root = NULL; 
        int n = description.size()+1;
        vector<int>used(n);
        vector<int>vis(n);
        vector<TreeNode*>P(n);
        
        //let us compress
        vector<int>compressed(n);
        map<int,int>have;
        int last = n;
        for(auto&x:description){
            if(have[x[0]] == 0){
                have[x[0]] = last;
                last--;
            }
            if(have[x[1]] == 0){
                have[x[1]] = last;
                last--;
            }
        }
        
        
        for(auto&x:description){
            int p = have[x[0]]-1;
            int c = have[x[1]]-1;
            int lc = x[2];
            used[c]++;
           // cout<<p<<" "<<c<<" "<<lc<<endl;
            if(vis[p] == 0){
                TreeNode*pcell = new TreeNode;
                pcell->val = x[0];
                P[p] = pcell;
                vis[p]++;
              //  cout<<(p+1)<<endl;
                if(lc){
                //    cout<<"*"<<endl;
                    if(vis[c]){
                        P[p]->left = P[c];
                    }else{
                        TreeNode* cell = new TreeNode;
                        cell->val = x[1];
                        P[p]->left = cell;
                        P[c] = cell;
                        vis[c]++;
                    }
                }
                else{
                    if(vis[c]){
                        P[p]->right = P[c];
                    }else{
                        TreeNode* cell = new TreeNode;
                        cell->val = x[1];
                        P[p]->right = cell;
                        P[c] = cell;
                        vis[c]++;
                    }
                }
            }
            else{
                if(lc){
                    if(vis[c]){
                        P[p]->left = P[c];
                    }else{
                        TreeNode* cell = new TreeNode;
                        cell->val = x[1];
                        P[p]->left = cell;
                        P[c] = cell;
                        vis[c]++;
                    }
                }
                else{
                    if(vis[c]){
                        P[p]->right = P[c];
                    }else{
                        TreeNode* cell = new TreeNode;
                        cell->val = x[1];
                        P[p]->right = cell;
                        P[c] = cell;
                        vis[c]++;
                    }
                }
            }
            
        }
        
        for(int i=0;i<n;++i){
            if(used[i] == 0){
                return P[i];
                break;
            }
        }
        
        return root;
    }
};
