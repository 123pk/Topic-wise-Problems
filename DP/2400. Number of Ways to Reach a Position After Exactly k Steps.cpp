/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 309
Approach :- We will use recursion + memoisation (dp) , as it is one of standard problems where dp[i][j] --> gives us the number of ways to reach (ith coordinate) with 
            'k' steps .
            Before applying this we need to take care of negative values , we will add 1000 to both 'start' and 'end' so that they will not be negative
Time Complexity :- O(n*k) , where n can be atmax 3000
*/
