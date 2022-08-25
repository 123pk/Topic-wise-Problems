/*
Platform :- Leetcode
Approach :- We will use binary search here to get O(logn) solution ,  so to decide which direction to move we can get that by comparing with 
             neighbours, 
             1. check if current index is valid peak or not , if it is return it
             2. if current index is not a peak then check the neighbours to find where to move if(nums[mid] < nums[mid-1]) ---> move to left to get the maxima
                else move to right .
*/
