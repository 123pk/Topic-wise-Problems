/*
Platform :- Leetcode
Approach :- We will do dfs and if there is any apple in descendents of current node then we need to add cost of '2' , '1' for going down and '1' for coming up till here
            So we get boolean value returned to us , which state that there is any apple with descendents of current node or not ,if yes we add '2' to our sum
Time Complexity :- O(n+m)
*/
