/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 313
Approach :- I have use KMP + dp for the solution ,
            1. I have precalculated the 'vector' of indices which follow the condition ( first i letters of s are equal to the following i letters in s)
               for each substring from ( j to n-1) for all 'j' from [0,n-1] , I have vector of those indices 
               so if I am at 'j' I can jump to ('j'+ idx[i]) as they will satisfy the condition.
               
               I have used KMP for comparing the string and finding those indices.
            2. Now for all the indices I have found the max value I can get if I start from there .
Time Comlexity :- O(n*n)
*/ 
