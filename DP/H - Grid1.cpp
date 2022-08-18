/*
Platform :- Atocder
Contest :- Educational DP Contest
Approach :- We will use recursion and memoisation in bottom up manner , so we will start from (n,m) last cell and will do 'up' and 'left' operation which is equivalent 
            to 'right' and 'down' in top down approach . So we will check if current cell is already blocked then no of ways to reach there is 0(dp[i][j] = 0)
            else dp[i][j] = no_of_ways_to_reach(i-1,j) + no_of_ways_to_reach(i,j-1) --- ( left and up movement) . If we area at starting cell if it is not blocked we 
            set dp[i][j] = 1
            
            -- for tabular form dp[i][j] = dp[i-1][j] + dp[i][j-1] for bottom up
*/
