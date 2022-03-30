/*
Platform :- Leetcode
Appraoch :- We will use binary search , Since we are given that ( matrix [ i ][ 0 ] > matrix[ i - 1 ][ col - 1] ) --> first element of ith matrix is greater than last 
            element of i-1th row , so first we will find the row using binary search and then we will use binary serach on that row to find the value 
*/
