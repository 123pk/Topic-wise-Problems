/*
Platform :- Codeforces
Contest :- Codeforces Round 777 Div 2
Approach :- It is always optimal to come from n,m to (1,1) and we have '1' in our matrix we choose a rectange of (i,j-1) to (i,j) , for all j>1,
            --> if we have (1,1) of our matrix as  '1' then we dont have any possible answer
            --> if we have no cells with '1' then we have '0' operations to perform
            --> we will perform 'e' operations where 'e' is no of '1' in our matrix , for a values which is '1' at j = 0, in this case we choose (i-1,j) to (i,j) rectangle
*/
