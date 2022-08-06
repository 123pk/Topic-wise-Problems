/*
Platform :- Atcode
Contest :- LINE Verda Programming Contest（AtCoder Beginner Contest 263）
Approach :- We find the max perfix difference we can get using the operation till (ith index) replacing each element with 'L' 
           Similarly we found the suffix max of change in sum we can get from (n-1th to ith index)by replacing each elemnet with 'R'.
           We found the max value(pref[i]+suff[i+1]) and also max(pref[n-1] ,suff[0])---> in this case we are removing each element and addding L or R whole 
           now we remove the max of all from the sum of elements , we will remove +ve value only if the max is -ve we ignore.

Time Complexity ;- O(n),space - O(3*n)
*/
