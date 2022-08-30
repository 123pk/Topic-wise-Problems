/*
Platform :- Leetcode
Approach :- We create a 3d dp where dp[i][j][k] -- stoers the min cost of flight to reach from 'i' to 'j' with 'k' stopage
            We do bfs (greedily) always choosing the path with minimum cost (dijkstra) or we can also use bellman ford .
            We store the min cost for each of the instances. 
            At the end we want the min feasible value for dp[src][dst][i] --- i =0 to k
Runtime :- O(n*m*k)
*/
