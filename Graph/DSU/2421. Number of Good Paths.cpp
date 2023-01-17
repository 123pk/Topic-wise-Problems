/*
Platform :- Leetcode
Approach :- The basic approach is to form the graph starting with edge with smallest maximum value . We join two disjoint sets and 
            if the max_value in both is same then we can have (count1*count2) no of good paths where count1 & count2  is frequency of max_values .
            After merging we update the parent and count is updated to sum for the parent and made '0' for other node.
Time Complexity :- O(n+e log n)
*/
