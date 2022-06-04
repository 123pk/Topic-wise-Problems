/*
Platform :- Leetcode
Approach :- We will run a loop from 1 to amount , and will try to find the minimum cost to reach there using any denomination available 
            dp[i] = min(dp[i],dp[i-coin[j]] + 1 ) ---> here dp[i] = min cost to get to amount 'i' , here coin[j] is denomination of 'j'th coin
*/
