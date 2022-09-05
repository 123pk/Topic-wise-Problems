/*
Platform :- Leetcode
Approach :- We use min heap of pair storing the value of first element of of each of k lists , now we move the pointer by taking the top element and adding it to the list
            at the end we return the head
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //let us make it space efficent 
        //we will use priority_queue to get the smallest value node at the beginnig
        priority_queue<pair<int,ListNode*>>P;
        
        for(auto&x:lists){
            if(!x)continue;
            P.push({-(x->val),x});
        }
        
        ListNode*ans = NULL;
        ListNode*cur = NULL;
        
        while(!P.empty()){
            pair<int,ListNode*>temp = P.top();
            P.pop();
            int  val = abs(temp.first);
            ListNode* node = temp.second;
            
            if(ans == NULL){
                ans = node;
                cur = node;
            }
            else{
                cur->next = node;
                cur = cur->next;
            }
            
            node = node->next;
            if(node){
                P.push({-(node->val),node});
            }
        }
        
        return ans;
    }
};
