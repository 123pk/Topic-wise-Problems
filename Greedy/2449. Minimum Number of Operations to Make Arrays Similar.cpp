/*
Platform :- Leetcode
Contest :- Weekly contest 316
Approach :- Get all the odd and even values of nums array, now sort the target array and for each odd value or even value , get the abs(x-value[j])/2 where j is the last odd or 
            even element accordingly .
            At the end we have to half of those operations as we are covering two operatino in 1 move.
Time Complexity :- O(n logn)
*/
