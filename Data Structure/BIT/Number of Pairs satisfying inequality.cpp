/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 88
Approach :- You need to simplify the equation 
                        nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff 
                   ---> nums2[j] - nums1[j] <=  nums2[i] - nums1[i] + diff , 
                   ---> now for each 'i' we want to find the number of values (nums2[j] - nums1[j]) for each 'j' greater than 'i' are smaller than nums2[i] - nums1[i] + diff 
            So problem is reduced to find number of value smaller than or equal this to right .
*/
