/*
Platform :- Leetcode
Approach :- We will maintain two heaps , one max heap which will store (k+1)/2 smallest values where 'k' is size of array at that moment,
            similarly we will maintain a min heap which will store (k)/2 largest values.
            Now for answering queries, if we have odd no of elements then we will return the max value of the smaller values,
            if its even then we will return the middle value of 'top' element of both heaeps
*/
