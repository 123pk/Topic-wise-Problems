/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 289
Approach :- We will perform the operations as stated until we get a string with length smaller than 'k'
*/
class Solution {
public:
    string digitSum(string s, int k) {
        string ans="",temp="";
        while(s.size()>k){
            temp = "";
            //first took the k characters and find the sum then add and merge
            for(int i=0;i<s.size();i+=k){
                int val = 0;
                for(int j=0;j<k && (i+j)<s.size();++j){
                    val+=s[i+j]-'0';
                }
                temp+=to_string(val);
            }
            s = temp;
        }
        return s;
    }
};
