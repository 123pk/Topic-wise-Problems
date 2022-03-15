/*
Platform :- Leetcode
Approach :- We take care of '(' and ')' we want to use balanced parenthesis , and we use a count function to add '+1' when we have '(' and -1' when we have '(' ,we will ignore the 
            operation which make the count to be -ve , similarly if after traversing through the string the count is > 0 then we will remove/ignore last of 'count' of '(' characters
            and copy the remaining characters as it is .

*/
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        
        int c = 0;
        for(int i=0;i<s.size();++i){
            if(s[i] == '('){
                c++;
                ans+=s[i];
            }
            else{
                if(s[i] == ')'){
                    if(c==0)continue;
                    else{
                        c--;
                        ans+=s[i];
                    }
                }
                else{
                   ans+=s[i];   
                }
            }
        }
        
        if(c>0){
            int i = ans.size()-1;
            map<int,int>not_used;
            string temp="";
            while(c){
                if(ans[i] == '('){
                    not_used[i]++;
                   c--;   
                }
                i--;
            }
            
            for(int i=0;i<ans.size();++i){
                if(not_used[i])continue;
                temp+=ans[i];
            }
            ans = temp;
        }
        
        return ans;
    }
};
