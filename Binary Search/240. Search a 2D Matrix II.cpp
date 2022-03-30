/*
Platform :- Leetcode
Approach :- This problem is variation of (74. Search a 2D Matrix)
            --> the difference in both the problem is that here it is not nescessary that ( matrix[i][0] > matrix[i-1][m-1] ) 
            --> so here for all the columns of first row we will do binary search and check if there is our target value in that particular column or not
Time Complexity :- O( m * Log n)
*/
