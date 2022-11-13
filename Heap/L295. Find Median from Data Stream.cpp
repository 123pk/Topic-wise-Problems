/*
Platform :- Leetcode
Approach :- We will maintain two heaps , the main idea is to store the first half in max heap and second halp of sorted array in min_heap ,  so the top value of both would 
            represent the middle values of sorted array.
            - We need to carefully insert the values . We don't want the top value of first half be "greater" than "top" value of min_heap which store the second half.
            So we greediy insert the values and at any point the difference in size should not be more than '1'
 Time Complexity :- O(n*logn)
*/
