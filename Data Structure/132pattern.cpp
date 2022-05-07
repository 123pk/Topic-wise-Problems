/*
Platform :- Leetcode
Approch :- We will maintain a prefix array where 'pref[i]' will store the minimum value till ith index , now we will maintain a set to store values in increasing order
           from behind (last to first) , now basic idea is to check for all values from (1 to n-2) that for value 'nums[i]' if we have a value in set which is greater
           than pref[i-1] and less than nums[i] , 
           so let 'x' be the value in set then we want , pref[i-1] < x  < nums[i] , we will use lower_bound on set to find the just greater value than pref[i-1], if there
           exist any such value then we will  return true.
*/
