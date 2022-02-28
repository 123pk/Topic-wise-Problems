/*
Platform :- Leetcode
Approach :- Binary search on values from 0 to size - 1 , We will check for each of the (start+end)/2 , if it is possible to cross then we will update the answer and binary search on
            value from (mid,end) else we binary search on value from (strat,mid).
            
            We will use BFS to find if it is possible to cross or not.
*/
