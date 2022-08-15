/*
Platform :- Codeforces
Contest :- Codeforces Round 806 Div 4
Approach :- We know the max value of A[i] is 10^9 , so it means if no of 2nd operation is more than 30 then that max value will also become zero ,
            so for each index 'i' from 0 to n-1 we will check what if we proceed first 'i' values with 1st operation and next min(n,i+32) value with 
            operation 2nd and store the max of all sum obtained . That will be our required ansewr.
            
Time Complexity :- O(n*32) -- O(n)
*/
