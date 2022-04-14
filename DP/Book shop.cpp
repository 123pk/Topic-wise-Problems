/*
Platform :- CSES
Approach :- We will use bottom up approach , here dp[i] -- > stores the max no of pages we can have with atmost 'i' coins ,
            we will traverse from (x to 1 )coins and  ' if( i >= price[j] ) dp[i] = max(dp[i],dp[i-price[j])+pages[j])
*/
