/*
Platform :- Leetcode
Approach :- We will first find the binary string of both values ,  now we will find anther string which will be 'or' of both strings and one will be 'and' of both string
            then we will do bit addition operaion . with carray .
*/
class Solution {
public:
    int getSum(int a, int b) {
        
        string one = bitset<32>(a).to_string();
        string two = bitset<32>(b).to_string();
        
        reverse(one.begin(),one.end());
        reverse(two.begin(),two.end());
        
        //now do addition of bits
        string ans = "";
        int carry = 0;
        for(int i=0;i<32;++i){
            int d = 0;
            if(one[i] == '1')d++;
            if(two[i] == '1')d++;
            
            d+=carry;
            carry = 0;
            if(d>1){
                carry = 1;
                d%=2;
                if(d)ans+='1';
                else ans+='0';
            }
            else{
                if(d == 0)ans += '0';
                else ans += '1';
            }
        }
        reverse(ans.begin(),ans.end());
        int val = stoll(ans,0,2);
        
        return val;
         
    }
};
