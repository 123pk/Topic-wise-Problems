/*
Platform :- Leetcode
Approach :- We will do dfs and we want a frequency array which store the frequency of characters in subtree of ith node,
            since there are 26 characters only it will be fine .
            So we get the fequency array from each of the child and now we sum those frequencies into a common frequency array and 
            store the fequency of ith node character in answer.
            
 Time Complexity :- O(n+e)
 Space Coplexity :- O(n+e+26)
*/
