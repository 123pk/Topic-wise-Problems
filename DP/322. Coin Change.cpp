/*
Platform :- Leetcode
Approach :- It is standard Dynamic programming problem which we will use 2-d dp to solve , state of dp[i] = min(dp[i], dp[i-coins[j]] + 1 ) 
            here coins[j] is list of all denominations we have 
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans=INT_MAX,f=0;
        
        vector<int>dp(amount+1);
       /* for(int j=0;j<coins.size();++i){
            dp[coins[i]]=1;
        }*/
        dp[0]=0;
        
        
        for(int i=1;i<=amount;++i){
            //For each value from 1 to amount
            //the minimum denominations is required
            dp[i]=INT_MAX;
            for(int j=0;j<coins.size();++j){
                if((i-coins[j])>0 && dp[i-coins[j]]){
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
                }
                else if((i==coins[j]))dp[i]=1;
            }
            if(dp[i]==INT_MAX)dp[i]=0;
        }
        
        if(dp[amount]==0 && amount)return -1;
        return dp[amount];
    }
};
