/*
Platform :- Leetcode
Approach :- We try to find value of each of valid substring of parenthesis and for each level we add them and for lower level we multiply by '2' .
*/
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>P;
        P.push(0);
        int ans = 1;
        for(auto&x:s){
            if(x == '(')P.push(0);
            else{
                int val = P.top();
                P.pop();
                if(val == 0){
                    val+=1;
                }
                else{
                    val<<=1;
                }
                P.top()+=val;
            }
        }
        ans = P.top();
        return ans;
    }
};
