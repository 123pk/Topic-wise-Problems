/*
Platform :- Codeforces
Contest :- Codeforces Round 827 
Approach :- We will find 2^x that we have in our array from the elements by dividing them by '2' , then we will use one array to store the additional power that we can ad
            if we have 'x'>=n we don't need to do any operation , else we will sort the values arrray which store the power of '2' for each index in decresaing order
            and keep incrementing 'x' if 'x'<n after all the addition then it is not possible else we will maintain count which will be our answer.
            
Time Complexity :- Nlog(N)
*/
