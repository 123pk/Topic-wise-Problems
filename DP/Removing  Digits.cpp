/*
Platform :- CSES
Approach :- So we will start with bottom up dp , where dp[i] stores the minimum no of operations require to get ith value from '0' by adding digits 
            dp[i] = min(dp[i-j] + 1,dp[i])  where 'j' is the digit in 'i'
*/
