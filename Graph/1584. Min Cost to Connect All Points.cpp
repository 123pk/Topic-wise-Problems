/*
Platform :- Leetcode
Approach :- You need to see those points as node and create one undirected weighted connected graph with weight between two nodes [i,j] = manhattan distance between
            ( points[i] & points[j] ) . Now for that graph we need to find the MST and sum of weights is our answer . 
            I have used prims algorithm for the following .
Time Complexity :- O(E log N)
*/
