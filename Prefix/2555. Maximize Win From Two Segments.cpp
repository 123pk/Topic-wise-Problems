/*
Platform :- Leetcode
Contest :- Leetcode Bi Weekly contest 97
Approach :- We can observe that since we can choose two segment , for each index we can find the max_value in segment from [0,i] or left_segment 
            and max_value for right segment [i+1,n-1] 
            Using Sliding window and prefix and suffix array we can find the max count for each index 'i' to its left and to its right.
            The max value of prefix[i] + suff[i+1] , is our answer.
Time Complexity :- O(n)
*/
