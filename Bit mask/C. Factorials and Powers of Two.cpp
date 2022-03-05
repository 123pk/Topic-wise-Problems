/*
Platform :- Codeforces
Contest :- Codeforces Round 774 Div 2
Approach :- We first find all the factorials that are <=n and make an array , then we try to find all possible distinct subsequence sum of that array , let 'c' = no of elements
            in that subsequence , we also maintain a 'rem' variable to store the (n - ' sum_of_subsequece_choosen ') then we find binary representaion of that rem value as it is 
            'sum of power of 2' let no of set bit in it be 'd' then for ith subseqence we have (c+d) no of distinct value which add upto 'n' and min of all of them is our value.
*/
