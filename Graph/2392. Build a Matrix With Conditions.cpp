/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 308
Approach :- So you need to understand it is a graph problem more formally Disjoint Set Union (DSU) or connected componenets .
            i. Condition for 'NOT' having any solutin is when we have a 'Cycle' in any of the connected component.
            ii. Now we know we have solution but how to initialise the cells , it is better to create two graphs based on conditions one for row and for column
            iii. Now we use topological sort to give the cell to the number from 1 to k , 
            iv. We fill the values which have both row and column value already from topological sorting
            v. Now for remaining values with either row or column value , we can give cells to any one of them first so how to do that , suppose we know the row 
               then we will run a loop for column from 0 to k-1 and will find the first unfilled cell and give it to this number . We do same until finshed

Time complexity :- O(N^2) , in worst case when we just have row or column value only
*/
