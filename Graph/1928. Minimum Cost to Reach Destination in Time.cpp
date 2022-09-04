/*
Platform :- Leetcode
Approach :- We will use dijkstra algorithms with priority on minimum cost/fees path first . We can use set of pair where first element is the element with smallest
            cost/fees . 
            We will move along the path if the 'time_take <= maxTime' , 
            -- Then we will check for cost , if cost to reach node 'x' is less than already stored value to reach there then we update it and do traversal again
            --- Else we look for minimum time to reach current node if that can be modified we again take it in consideration and do traversal again
*/
