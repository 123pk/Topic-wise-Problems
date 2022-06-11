/*
Platform :- Leetcode
Contest :- Leetcode Bi Weekly contest 80
Approach :- We try to find the longest subarray which satisfy the condition while traversing from left to riht (0 to n-1) using two pointer , we will push those ranges
            in array and  no of subarrays which satisfies the condition for len 'x'  = 'x'*(x+1)/2 , we will remove overlapping values which are added multiple times 
            we just want to add single times.
*/
