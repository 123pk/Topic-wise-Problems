/*
Platform :- Codeforces
Contest :- Codeforces Round 796 Div 2
Approach :- We have two cases 
           i. k < n , here we will find the subarray of length with max sum and we will start from starting index of this subarray and find the final value
           ii. k >=n , here we can visit all elements of array and we will do the same , It take us (n) days in start to get all the way to last element from start and after that we
               will get all the way to end element in (n-1) days . So we will find the extra addition cost for 'x' days which is (x*(x-1))/2 , similary if there are some 
               remaining days it is better to get them the max values in those days
*/
