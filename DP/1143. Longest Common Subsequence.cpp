/*
Platform :- Leetcode
Approach :- We first write down bruteforce recursion where we start with the last index of both strings , 'n-1' and 'm-1' where 'n' = length of string 1 , 'm' = length of string 2
            Case 1 : - If s[i] == t[j] , then we move the index of both by 1 and increment size of LCS by '1'
            Case 2 :- Here we have two subtask/options
                      Option 1 :-  We will move to next index in string one and find LCS for (i+1,j)
                      Option 2 :-  We will move to next index in string two and find LCS for (i,j+1)
                      The max of these is our LCS
                     
                     
            This solutin is exponenetial and will give TLE to avoid TLE and make our program more efficient we will "memoise" values and will reuse them again when we need and will
            not compute again and the solution now have time complexity of (O(n^2)) which will pass.
*/
