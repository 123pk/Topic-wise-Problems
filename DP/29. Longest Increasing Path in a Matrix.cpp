/*
Platform :- Leetcode
Approach :- So the basic idea is to dfs and we find the max length path we can get to if we start from some cell (i,j) we use 2d matrix to store it and later use that value
            if required so that we don't compute for same cell again and again (Dynamic Programming).
            We have four option to move from any cell (left,right ,up and down)
            we check all the four option if it is valid to move and we have not already visited and find its value we go there and finnd the value ,mark it visited.
Time Complexity :- 
*/
