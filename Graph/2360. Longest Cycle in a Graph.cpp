/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 304
Approach :- We will traverse from 0 to n-1, if the nodes are already visited we don't visit then again , else we do dfs and store two vlues the length till 'x'th node
          (path len till there) and the starting node or root of current connected component or DSU , if we visit one node whose root node is (i+1) then it means we have
          a cycle and it is of length (curent_len - len_till_that_node)+1. 
          --> If we visite a node whose root is not (i+1) then it means we have already considered that path and will not traverse it again so we stop our bfs there and 
              break out .
Time complexity :- O(n)
Space complexity :- O(n)
*/
