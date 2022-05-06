/*
Platform :- Codeforces
Contest :- Codeforces Round 787 Div 3
Approach :- We will start from last element and traverse to the first , Since we can only change the value by diving them by 2 , so this means we cannot increase values
            we will start from last and if current element ( A[i] < A[i+1]) then we dont do anythign because it is already in increasing order, else we change it until
            the value of A[i] is smaller and "count" it, if at any point we reach to '0' then we cannot convert the array and print "-1" else print the "count".
*/
