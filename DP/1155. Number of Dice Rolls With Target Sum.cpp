/*
Platform :- Leetcode
Approach :- We will use recurison  + memoisation ,
            The apporahc is dp[i][value] = dp[i-1][value-j] , where 'j' is any value from the face between '1' and 'k'
            we will take care of overflow using 'mod'
Time Comlexity :- O(n*k*target)
*/
