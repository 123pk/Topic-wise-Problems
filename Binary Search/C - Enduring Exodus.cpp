/*
Platform :- Codeforces
Approach :- We will do binary serach on minimum distance 'x' from John tohis fatherst cow , we would also precompute no of zeros till 'ith' index , 
            now while doing binary search we will travers through array and check for no of zeros in range of '[ max(0,i-mid)] to [min(i+mid,n-1) ] '
            if it contains values > k then we choose min of all available values.
*/
