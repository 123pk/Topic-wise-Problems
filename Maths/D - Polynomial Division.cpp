/*
Platform :- Atcoder
Contest :- Atcoder Beginner Contest 245
Approach :- We have a poynomial Sequence A and B , the product of those is C , We are given A and C and we want to find 'C' , so we can get that by simplifying the given
            information , like for Cn+m = A[n]*B[m] , we can get B[m] from here , similarly for Cn+m-1 = A[n-1]*B[m] + A[n]*B[m-1] , since we already know values of all the
            values ( Cn+m-1 , A[n] , A[n-1] and B[m]) hence we can find B[m-1] , similarly we can get for all the other values . We will start form last value because it is 
            guaranteed that those values cannot be '0' for all test cases .
*/
