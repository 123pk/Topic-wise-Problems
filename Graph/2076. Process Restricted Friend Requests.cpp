/*
Platform :- Leetcode
Approach :- For each of the requests(u,v) we will traverse through the array and find parent of each node in subtree of (u) and subtree of (v) and now we traverse through 
            the restrictions and check if ( parent[x] == parent[u] ) and  ( parent[y] == parent[v] ) or 'vice versa' this means we have restricted nodes in subtrees so we cannot
            join or fulfill this request and we add 'false' else we add 'true'
            
Time Complexity :- O(n*n)
*/
