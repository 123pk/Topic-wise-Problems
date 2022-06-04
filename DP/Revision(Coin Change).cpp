/*
Platform :- Leetcode
Approach :- We will run a loop from 1 to amount , and will try to find the minimum cost to reach there using any denomination available 
            dp[i] = min(dp[i],dp[i-coin[j]] + 1 ) ---> here dp[i] = min cost to get to amount 'i' , here coin[j] is denomination of 'j'th coin
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
         // to get [11], from  [2,3,5]
        // we have options like [5,3,3]
        vector<int> dp(amount+1,-1);
        dp[0] = 0;
        for(int i=1;i<=amount;++i){
            for(auto&x:coins){
                if(i>=x){
                    if(dp[i-x]!=-1){
                        if(dp[i]!=-1)dp[i] = min(dp[i],dp[i-x]+1);
                        else dp[i] = dp[i-x]+1;
                    }
                }
            }
        }
        
        return dp[amount];
    }
};
