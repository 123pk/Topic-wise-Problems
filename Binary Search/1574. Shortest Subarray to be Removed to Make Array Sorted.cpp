/*
Platform :- Leetcode
Approach :- We find the starting index and ending index where our array is unsorted , 
            * if the subarry from start to end is sorted , in that case we will consider situation when we will remove prefix and suffix of that
            * For each element in [0,start-1] we will find a value which is smallest index where ( arr[i]>= arr[current_index] ) value in [end,n-1] , 
                as they will form sorte array as value in [end,n-1] are already sorted .
           * Similarly for all element in [end,n-1] we will find one value which will be <= current value in range [ 0 ,star-1].
           We will use binary search to find the indexes as they are already sorted.
           
 Time Comlexity - O(n log n) -- binary search
*/
