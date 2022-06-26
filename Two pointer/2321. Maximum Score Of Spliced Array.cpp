/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 299
Approach :- We maintain two change arrays , they store what is the benefit or change in sum we are going to get if we replace A[i] with B[i] , now in both arrays we
             find maximum sum subarray and then answer is max(tot1 + max_subarray_sum1 + tot2 + max_subarray_sum2)
*/
