/*
Platform :- Leetcode
Approach :- We will traverse through array push and push the elemnts in stack and then we will check if top element is equal to pop value then we pop that element from stack
*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>P;
        int i=0,j=0;
        for(i=0;i<pushed.size();++i){
            P.push(pushed[i]);
            while(!P.empty() && P.top()==popped[j]){
                P.pop();
                j++;
            }
        }
        return P.empty();
    }
};
