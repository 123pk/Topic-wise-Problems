/*
Platform :- Leetcode
Approach :- We store chldren of each node intially marked as [-1,-1] , where first -1 =  no left child and second -1  = no right child.
            We traverse through the string and store the nodes at each level , if we found a node at level 'c' then this node is going to be child of
            lasst node of level '[c-1]' for all ' c >= 1 ' . 
            The very first node that we get is out root node, so we do BFS starting from root node and we progress adding left child first and then right child 
            if they are not -1.
 Time Complexity :- O(nlogn)
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
    TreeNode* recoverFromPreorder(string traversal) {
        
        //so the basic idea is to store the nodes per level 
        //first come first serve 
        map<vector<int>,pair<int,int>>children;
        map<int,vector<int>>NodeAtLevel;
        int c = 0,cur = 0;
        int root = -1;
        vector<int>temp ;
        int m;
        int last = 0;
        int szz;
        for(auto&x:traversal){
            if(x == '-'){
                
                if(root == -1)root = cur;
                
                if(c == 0){
                    //cout<<cur<<" ";
                    szz = NodeAtLevel[last].size();
                    children[{cur,last,szz}] = {-1,-1};
                    NodeAtLevel[last].push_back(cur);
                    if(last){
                        temp.clear();
                        temp = NodeAtLevel[last-1];
                        m = temp.size();
                        
                        if(children[{temp[m-1],last-1,m-1}].first == -1){
                            children[{temp[m-1],last-1,m-1}].first = cur;
                        }
                        else children[{temp[m-1],last-1,m-1}].second = cur;
                    }
                }
                
                c++;
                last = c;
                cur = 0;
            }
            else{
                cur*=10;
                c = 0;
                cur += x-'0';
            }
        }
        //cout<<cur<<" "<<last<<"\n";
        if(cur){
            NodeAtLevel[last].push_back(cur);
            szz = NodeAtLevel[last].size()-1;
            children[{cur,last,szz}] = {-1,-1};
            if(root == -1)root = cur;
            else{
               temp.clear();
                temp = NodeAtLevel[last-1];
                m = temp.size();
                 
                if(children[{temp[m-1],last-1,m-1}].first != -1)children[{temp[m-1],last-1,m-1}].second = cur;
                else {
                     
                    children[{temp[m-1],last-1,m-1}].first = cur;
                }
            }
        }
        
       /* for(auto&x:children){
            cout<<x.first<<" -- "<<x.second.first<<" "<<x.second.second<<"\n";
        }
        cout<<"\n";
        */
        
        TreeNode*head = NULL;
        TreeNode*start = new TreeNode;
        start->val = root;
        queue<pair<int,TreeNode*>>bfs;
        bfs.push({root,start});
        //head = start;
        int lvl = 0;
        while(!bfs.empty()){
            int sz = bfs.size();
            int d = 0;
            for(int i=0;i<sz;++i){
                pair<int,TreeNode*> temp = bfs.front();
                bfs.pop();
                
                int value = temp.first;
                TreeNode*node = temp.second;
                if(head == NULL)head = node;
                //cout<<value<<" ";
                if(children[{value,lvl,d}].first != -1){
                    TreeNode* z = new TreeNode;
                    z->val = children[{value,lvl,d}].first;
                    node->left = z;
                    bfs.push({z->val,z});
                }
                
                if(children[{value,lvl,d}].second != -1){
                    TreeNode* z = new TreeNode;
                    z->val = children[{value,lvl,d}].second;
                    node->right = z;
                    bfs.push({z->val,z});
                }
                d++;
            }
            lvl++;
        }
        
        return head;
    }
};
