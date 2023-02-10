/*
Platform :- Leetcode
Approach :- We maintain one 2d- matrix which store the smallest distance of that cell (i,j) from any land ,
            for all the land it will be '0'
            else we initialise to "infinity" for all the cell initally.
            Now whenever we have any land cell , we start bfs from there and move to neighbouring water cells only if 'cost' or smallest distance [i,j] < cur_cost+1 .
            In this way we find the smallest value for each of the cell .
Time Complexity :- O(n*m)
*/
