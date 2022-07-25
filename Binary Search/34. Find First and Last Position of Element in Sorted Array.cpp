/*
Platform :- Leetcode
Approach :- We will do binary search and find first occurence of "target" values in array , if we are not able to find we return {-1,-1} , else we update our array 
            with that index, now we recursively do binary search on left part of that index and similarly or right part and find the smallest index and largest index
            with target value
 Time Complexity :- O(log n)
*/
