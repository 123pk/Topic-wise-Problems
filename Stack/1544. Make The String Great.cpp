/*
Platform :- Leetcode
Approach :- We will use a stack and if there is some elemet in stack we will check if top element and current element satisfy the condition or not,if they do then we
            pop out that element else we keep it and push the current element in stack.
            After traversign through the string we get the element from stack and add to string and reverse it that is our requried string
Time Complexity :- O(n)
*/
class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        stack<char>P;
        for(int i=0;i<(s.length());++i){
             if(P.empty()){
                 P.push(s[i]);
             }
             else{
                 char ch = P.top();
                 if(abs(ch-s[i]) == 32){
                     P.pop();
                 }
                 else P.push(s[i]);
             }
        }

        while(!P.empty()){
            ans += P.top();
            P.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
