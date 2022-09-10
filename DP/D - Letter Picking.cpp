/*
Platform :- Codeforces
Contest :- Codeforces Educational Round 135
Approach :- So we have four combination to take care for any range [i,j]
            1. If Alice choose ith element 
                  i. When Bob chooses (i+1)th element
                  ii. When Bob Choses (jth) element
            2. If Alice choose jth element 
                  iii. When Bob Chooses (i)th element
                  iv. When Bob choose (j-1)th element
            So we will use ' recursion+ memoisation' (DP) and find suitable situation for all the four conditions
Time Complexity :- O(n*n)
*/
