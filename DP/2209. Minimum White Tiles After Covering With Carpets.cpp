/*
Platform :- Leetcode
Contest :- Leetcode Bi Weekly contest 74
Approach :- We will use dp for memoisation , so basic idea is to use dp[1000][1000] , such tha dp[i][j] stores the min no of white tiles that are remaining upto 'ith'
            index after using 'j' black tiles .
            We have two options ,either to put a tile at ith index or not , if we don't put it at ith index and 's[i] = '1'' then we have one uncoverd white tile.
            min of two option we return.
*/
