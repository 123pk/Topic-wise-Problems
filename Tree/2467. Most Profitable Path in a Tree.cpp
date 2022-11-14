/*
Platform :- Leetcode
Contest :- Bi Weekly contest 91
Approach :- We will first make the graph , maintain one parent array which stores the parent of each node .
            Now we modify the values of nodes in path from ( root to bob node) .
            Now the problem is narrow down to find the path with max sum from root to any of leaf . We will use bfs and the max value is our answer.
Time Complexity :- O(n+e)
*/
