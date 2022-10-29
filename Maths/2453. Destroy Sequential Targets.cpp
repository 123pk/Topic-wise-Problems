/*
Platform :- Leetcode
Contest :- Leetcode Bi Weekly contest 90
Approach :- So we are give we can destroy target if nums[j] =  (nums[i] + c*space) --  if you will simplify this
            you will find (nums[j] - nums[i])/space = c , so if nums[j]%space == nums[i]%space then we can destroy them 
            so we maintain a count for nums[i]%space ,
            and one with max frequency/count and min value is our answer.
Time Complexity:- O(N)
*/
