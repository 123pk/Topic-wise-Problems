/*
Platform :- Leetcode
Apporach :- For all level from 0 to n-2 , we will update the values at next level , for index from 1 to length of vector of ith level we will update all 
            values from 1 to len[i]-1 , 
            we will store the min (triangle[i+1][j] + triangle[i][j] , triangle[i+1][j]+triangle[i][j+1] ) 
*/
