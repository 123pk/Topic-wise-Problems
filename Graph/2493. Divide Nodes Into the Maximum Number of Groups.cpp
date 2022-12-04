/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 322
Approach :- First if you will observer the problem you will find that if the graph has even length of cycle then we cannot have any valid distribution.
            Even length  = even no of edges  ,
            else we have multiple subgraph which are disjoint and we will try to find the max length we can get to by Brutefrocing for each of the node,
            and the max value out of all the nodes is added to our answer.
 Time Complexity :- O(n*(n+m))
*/
