/*
Platform :- Leetcode 
Approach :- So we will try to look for the center point of any palindrome , we will try all possilbe and 
           1. for odd length of palindromic substrings we start with two pointer 'left' and 'right' , they will move in direction as the name suggest
               we will check if they are equal or not ,if equal we will increment our count else break and move to next index and consider it center,
               initially 'left' = 'right' = 0
           2. for even length of palindromic substring we will start with 'left' = i , 'right' = i+1
              and do the same we did in step 1
*/
