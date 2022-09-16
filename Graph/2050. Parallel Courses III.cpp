/*
Platform :- Leetcode
Quality :- Very good
Approach :- We will use topological sort we will start with nodes which have no incoming edge , we will also maintain one max_time array which will store the max_time 
            it will require to comlete ith subject .
            We maintain one count array which is basically the no of incoming edges for each node , we do bfs and reduce the count of node if count[node] == 0, we add in 
            bfs traversal with max_time .
            At the end the max time out of all subjects to finish is our required answer.
Time Complexity :- O(E+N log n)
*/
