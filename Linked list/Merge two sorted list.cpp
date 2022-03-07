/*
Platform :- Leetcode
Approach :- We greedily maintain two pointer and compare between values the pointer is pointer , first pointer is for first linked list
            Second pointer is for scond linked list and choose the one to added before which have less value
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode*temp=NULL,*head=NULL;
        while(l1&&l2){
            if(!l1 || !l2)break;
            if(l1->val<=l2->val){
                if(temp==NULL){
                    ListNode*x=new ListNode;
                    x->val=l1->val;
                    x->next=NULL;
                    head=x;
                    temp=x;
                    l1=l1->next;
                }
                else{
                     ListNode*x=new ListNode;
                    x->val=l1->val;
                    x->next=NULL;
                    temp->next=x;
                    temp=x;
                    l1=l1->next;
                }
            }
            else{
                if(temp==NULL){
                    ListNode*x=new ListNode;
                    x->val=l2->val;
                    x->next=NULL;
                    head=x;
                    temp=x;
                    l2=l2->next;
                }
                else{
                     ListNode*x=new ListNode;
                    x->val=l2->val;
                    x->next=NULL;
                    temp->next=x;
                    temp=x;
                    l2=l2->next;
                }
            }
        }
        
        if(l1||l2){
            if(l1){
                while(l1){
                    ListNode*x=new ListNode;
                    x->val=l1->val;
                    l1=l1->next;
                    if(temp){
                        temp->next=x;
                        temp=x;
                    }
                    else {
                        head=x;
                        temp=x;
                    }
                    x->next=NULL;
                }
            }
            else{
                while(l2){
                    ListNode*x=new ListNode;
                    x->val=l2->val;
                    l2=l2->next;
                    if(temp){
                        temp->next=x;
                        temp=x;
                    }
                    else{
                        head=x;
                        temp=x;
                    } 
                    x->next=NULL;
                }
            }
        }
        return head;
    }
};
