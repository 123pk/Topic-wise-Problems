/*
Platform :- Atcoder
Contest :- Atcoder Beginner Contest 281
Approach:- We maintain two set , one to store the 'k' smallest vlaues in range , one another set to store the remaining (m-k) values of range ,
           We maitain frequency count also .
           The main idea is to store smallest k value sin one set and reamaining in other ,then when we have new value we compare with the largest 
           value in current set if (largest_available > current) we add current to set and add the largest_available to extra. We do the following changes in 
           sum also.
 Time Complexity :- O(n log n)
  */
