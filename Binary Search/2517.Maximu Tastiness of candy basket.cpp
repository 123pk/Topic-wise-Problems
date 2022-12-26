/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 325
Approach:- We will binary serach on values between 1 and max value,we will also sort the array in increasing order as the ordering doesnot matter.
           Now we will start from first element and will find the count of longest increasing subsequence whose difference between adjacent elements is atleast 'mid'
           if we get atleast 'k' values then 'mid' can be our tastiness ,similarly we will increasea the values and check for bigger values if it satisfies else for
           smaller values.
           
Time Complexity :- O(N log N)
*/
