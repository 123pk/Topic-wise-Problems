/*
Platform :- Leetcode
Approach :- If you will carfully observe you will find that there is formation of strongly connected component between cells with stones ,we need to count no of nodes 
            in stricly connected compment for each cell ,let 'x' be the count ,then we can remove x-1 of them .
            So sum of all such 'x-1' for each connected component is our solution.
            We will use two map which will store the cell for each row , and column .We will start with bfs and visited array so that we don't visit same cell again.
            and keep on counting.
 Time Complexiy :- O(m*n*log(m*n))
*/
