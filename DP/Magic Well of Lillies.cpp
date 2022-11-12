/*
Platform :- Coding Compeition with google
Contest :- Google Kickstart Round H
Approach :- So we will traverse though from 1 to n and for each i, we will find the minimum coins we will need to get 'i' lilies out of the well ,
            you need to notice that you get minimum cost if you choose some factor of 'i' and take note of it and then repeatedly use that many using '2' coins .
            And if its is prime number them dp[i] = min(dp[i],dp[i-1]+1)
Time Complexity :- O(n* sqrt(n))
*/
