/*
Platform :- Leetcode
Contest :- Weekly contest 310
Approach :- We will maintain one dp[i] for all values in range [1, 10^5+1] ,  for dp[i] = max value in range(dp[i-k] ,dp[i-1]) + 1 
            to find max value in range we will use segment tree
Time Complexity :- O(n*logn)
*/
