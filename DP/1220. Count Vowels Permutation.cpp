/*
Platform :- Leetcode
Appraoch :- We will use bottom up do here , starting from nth index and filling upto 1st index , we will take care of conditions.
Time Complexity :- O(n*k)
*/
class Solution {
public:
    int dp[20001][5];
    map<char,int>order;
    int mod = 1e9+7;
    
    int find(int i,char ch){
         
        if(i<0)return 0;
        int j = order[ch];
        if(dp[i][j] != -1)return dp[i][j];
        
        //now we will explore the options
        if(i == 0){
            if(ch == 'a'){
                //we can have e so we can get 'a' at 1st index
                return dp[i][j] = 1;
            }
            else if(ch == 'e'){
                //here we can have ''a and i only 
                return dp[i][j] = 2;
            }
            else if(ch == 'i'){
                //we can have four value before i except i
                return dp[i][j] = 4;
            }
            else if(ch == 'o'){
                //we can have only i and u before o 
                return dp[i][j] = 2;
            }
            else {
                //for u we can have only a
                return dp[i][j] = 1;
            }
        }
        else{
            //here what we will do 
            int val = 0;
            if(ch == 'a'){
                //we can have e or u so we can get 'a' at 1st index
                val = find(i-1,'e');
                val%=mod;
                 
            }
            else if(ch == 'e'){
                //here we can have ''a only 
                  val = find(i-1,'a');
                  val%=mod;
                  val+= find(i-1,'i');
                  val%=mod;
            }
            else if(ch == 'i'){
                //we can have four value before i except i
                   val = find(i-1,'a');
                   val%=mod;
                   val += find(i-1,'e');
                   val%=mod;
                   val += find(i-1,'o');
                   val%=mod;
                   val += find(i-1,'u');
                   val%=mod;
            }
            else if(ch == 'o'){
                //we can have only i and u before o 
                    val = find(i-1,'u');
                    val%=mod;
                    val += find(i-1,'i');
            }
            else {
                //for u we can have only a
                 val = find(i-1,'a');
                 val%=mod;
            }
            
            return dp[i][j] = (val)%mod;
        }
    }
    
    int countVowelPermutation(int n) {
        if(n == 1)return 5;
        
        order['a'] = 0;
        order['e'] = 1;
        order['i'] = 2;
        order['o'] = 3;
        order['u'] = 4;
        
        memset(dp,-1,sizeof(dp));
        
        int ans = 0;
        vector<char>P=  {'a','e','i','o','u'};
        for(auto&x:P){
            ans += (find(n-2,x));
            ans = ans%mod;
        }
        return ans;
    }
};
