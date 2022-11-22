/*
Platform :- Leetcode
Approach :- let 'x' be square root of 'i' , we will use dp here where dp[i] = min number of perfect squre sum who add to 'i',
            so we will run aloop from 'j' -- (1 to 'x') for each 'i' and will find the min cost out of them all which will be '(dp[i] = min(dp[i],dp[i-j]+1)'
Time Complexity :- O(n*sqrt(n))
*/
