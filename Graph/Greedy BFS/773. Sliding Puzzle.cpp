/*
Platform :- Leetcode
Approach :- We will do bfs greedily / similary to dijkstra , we will sift the empty cell (cell wth value '0') to neighbouring ones , we also maintain one set which store 
             the state , we don't want to get back to same state again .
            So the first time we get the desired state we run out of loop and that is our answer.
Time Complexity :- O(n*m*6!)
*/
