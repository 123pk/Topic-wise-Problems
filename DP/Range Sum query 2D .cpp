/*
Platform :- Leetcode
Approach :- We will precalculate the sum till (i,j) ,
           --> sum of all values from 
               from 0 to i
                   from 0 to j
                       sum += matrix[i][j]
              We will do it optimally . 
              The best way to get the sum is dp[i][j] = matrix[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]
              we have subtracted dp[i-1][j-1] because it is repeating in both i,j-1 and i-1,j
              
              Similarly to find value from (i1,j1) to (i2,j2) , we will get it by val = dp[i2][j2] - dp[i1-1][j2] - dp[i2][j1-1] + dp[i1-1][j1-1]
*/
