/*
Platform :- Codeforces
Contest :- Codeforces Round 780 Div 3
Approach :- We will maintain a prefix array which will store no of increments we can do till ith index ,( change '--' to '+') .
            Now we will traverse through all the subarrays possible of length from 2 to n and will check if the no of ('+') == no of('-') then we will increment our answer
            as they are already good , else we will check if we have enough option to change '--' to '+' such that they are equal.
*/
