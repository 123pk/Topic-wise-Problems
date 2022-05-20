/*
Platform :- Leetcode
Approach :- Since we are allowed to have two moves only ,either go to "rigth" or to "down" , we will use 2D Dp , 
            where dp[i][j] ---> gives us no of ways to reach to this node from top left ,
            
            DP STATE --->   dp[i][j] = dp[i][j-1] + dp[i-1][j] , for j>=1 && j<m && i>=1 && i<n (0 - based indexing)
            -->here also if we have obstacle then dp[i][j] = 0,
            for j == 0  dp[i][j] = dp[i-1][j]
            for i == 0  dp[i][j] = dp[i][j-1]
            
*/
