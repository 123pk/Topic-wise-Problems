/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 286
Approach :- You need to analyse it carefully and you will find that , you can have always have first half of palindrome and that is (10^(n-1) - 1) + query[i] ,
            now you will get the second half from this .
*/
class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& Q, int len) {
        vector<long long>ans;
        
        
       //we can use permutaion  
        
        //approach is to get the starting values 
        //then wwe add Q[i]+starting_value = givest the half of our required value
        int z = (len+1)>>1;
        long long left_out = 1;
        for(int i=1;i<z;++i){
            left_out*=10ll;
        }
        left_out--;
        
        vector<int>s(len);
        for(auto&x:Q){
            long long val = left_out+x;
            
            if(to_string(val).length()>z){
                ans.push_back(-1);
            }
            else{
                string temp = to_string(val);
                for(int i=0;i<z;++i){
                    s[i] = s[len-1-i] = (temp[i]-'0');
                }
                
                long long tot = 0;
                for(int i=0;i<len;++i){
                    if(i==0){
                        tot+=s[i];
                    }
                    else{
                        tot*=10ll;
                        tot+=s[i];
                    }
                }
                ans.push_back(tot);
            }
        }
        
        return ans;
    }
};
