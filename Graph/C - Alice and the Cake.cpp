/*
Platform :- Codeforces 
Contest :- Codeforces Round 778(Div1 + Div 2)A
Approach :- We will start in reverse, from initial value we will try to get the array , so the starting value is going be sum of array elements , we will also maintain
            one frequency array which will help us in determining that we should divide further the value of not , we will do bfs,starting with the sum  if the frequency
            of current element of queue is '0' then we don't have that element in our array and we need to divide it , we will do the operation (n-1) time, if at the end
            we have some element whose frequency is not '0' then we cannot obtain that array and answer is "NO" else "YES".
*/
