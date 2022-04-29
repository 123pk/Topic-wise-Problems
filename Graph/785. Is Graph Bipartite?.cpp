/*
Platform :- Leetcode
Approach :- So since we want to divide our graph into two disjoint segment such that adjacent nodes are in diffenent segment , this problem can be changed to 
            can we color given graph with two color  or not ? If we can then the graph is bipartite else not .
            
            So for doing that we will run a loop from 0 to n-1 and if we haven not colored any node  , then we will do bfs on that nodes and color all the nodes in that
            subgraph, we will try to color adacent nodes with differnt color and if we find any node which is adjacent and have same color as current node then we cannot 
            color our graph using two color and we will return false,
            else if we are able to color all the nodes we will return true
            
Time Complexity :- O(n), as we are visiting any node atmax once 
*/
