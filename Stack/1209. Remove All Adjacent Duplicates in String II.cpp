/*
Platform :- Leetcode
Approach :- We will use stack in this , we will push the characters in stack with the frequency , if we have same element as that of top character of stack then we increment
            the frequency of top character, as soon as the frequency becomes 'k'we pop out that element .At the end we get the string according to frequecy and return.
*/
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>P;
        for(auto x:s){
            if(P.empty()){
                P.push({x,1});
            }
            else{
                pair<char,int>temp=P.top();
                if(temp.first==x){
                    if((temp.second+1)==k){
                        P.pop();
                    }
                    else{
                        P.pop();
                        P.push({x,temp.second+1});
                    }
                }
                else{
                    P.push({x,1});
                }
            }
        }
        
        string ans;
        while(!P.empty()){
            char ch=P.top().first;
            for(int i=1;i<=P.top().second;++i){
                ans+=ch;
            }
            P.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
