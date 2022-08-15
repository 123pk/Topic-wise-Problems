/*
Platform :- CSES
Problem set :- Dynamic Programming
Approach :- We will finnd the max difference between score of player1 and player2 using DP ( recursion + memoisation)
           --> let x = score1 - score2
           ---> Let tot_sum  = score1+score2 
           --> simplifying we will get (tot_sum + x) = 2*score1 , so score of (player1 = (tot_sum + x)/2 )
           
           We try all possible options.
           
Time Complexity :- O(n^2)
Space Compleity :- O(n^2)                         
*/
