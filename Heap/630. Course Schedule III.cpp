/*
Platform :- Leetcode
Approach :- We first sort the values by the 'last date' in increasing order and if the 'last date' for some values are same then we sort them based on 'duration' in inreasing
            order. We maintain one max_heap ( priority_queue ) in c++ , we will traverse through the array and choose the 'ith' course if it can be completed within
            'last_date[i]' , else we will check if the max_duration course is greater than 'duration[i]' then we remove that course and took this one , and update the heap
            and total_duration used .
*/
