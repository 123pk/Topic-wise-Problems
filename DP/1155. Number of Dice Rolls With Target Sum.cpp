/*
Platform :- Leetcode
Approach :- We will use recurison  + memoisation ,
            The apporahc is dp[i][value] = dp[i-1][value-j] , where 'j' is any value from the face between '1' and 'k'
            we will take care of overflow using 'mod'
Time Comlexity :- O(n*k*target)
*/


class Solution {
public:
    int mod = 1e9+7;
    int dp[31][1001];
    
    int find(int i,int k,int rem){
        
        if(i == 0){
            if(rem)return 0;
            else return 1;
        }
        
        if(dp[i][rem] != -1)return dp[i][rem];
        
        int val = 0;
        
        for(int j=1;j<=k;++j){
            if((rem-j)<0)break;
            val += find(i-1,k,rem-j);
            val %= mod;
        }
        
        
        return dp[i][rem] = val;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        
        return find(n,k,target);
        
    }
};
