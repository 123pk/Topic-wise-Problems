/*
Platform :- Codeforces
Contest :- Codeforces Round 817 Div 4
Approach :- We maintain prefix sum for each row where A[i][j] gives me the area of square in in range i<= height and j<=width , 
            now for each query we travese through columnn or row depending upon the prefix sum we have maintained we find the value in range specified 
            for columns from b1+1 to b2-1
*/
