/*
Platform :- Codeforces
Contest :- Codeforces Global Round 22
Approach :- We will keep on finding the values , A[i] = B[i]-B[i-1] , and all the value that we have foudn should be increasing in order 
              A[i-1]<=A[i] for all adjacent pairs , after if we have some value remaining we will find the smallest max value we can have out of all 
              x  = ceil(B[0]/(n-k)+1) .. if this 'x' is greatear than smallest A[i] value that we have calculated then also it is impossible .
 Time Comlexity :- O(k) 
*/
