/*
Platform :- Leetcode
Approach :- So we will first write one recursive solution , where we maintain three pointers pointer to start of each string (s1,s2 ans s3) respectively in the beginning
           , we will check ------> if(s1[i] == s3[k]) then we check for (i+1,j,k+1) 
              ---->   if(s2[j] == s3[k] ) then we check for (i,j+1,k+1) ,
              in this way we get all the possible combination . If 'i' or 'j'  are equall to string s1.size() or s2.size() then we check with respective value'j' or 'i' and'k'
              in order to avoid calculating for overlapping subtasks we will use memoisation.
*/
