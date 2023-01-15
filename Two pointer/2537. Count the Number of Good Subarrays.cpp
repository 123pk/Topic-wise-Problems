/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 328
Approach :- We want to find no of subarrays satifying the following condition starting at index 'i' for all ( 0 <= 'i' < n )
            We maintian one score which store the no of such pairs,once 'score' >= k , we will move the start pointer which is pointing to the start of the current subarray
            moving a start pointer will cost us fre[nums[start]]-1 , where fre store the frequency of values of arrays till now.
Time Compelxity :- O(n log n)
*/
