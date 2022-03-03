/*
Platform :- Leetcode
Approach :- We try to find length of arithmetic subarray , for a arithmetic array of length of 'c' we can have (c*(c+1))/2 subarrays . So we find that 'c' while traverseing through
            the array and maintain one value 'c' which we increment if (A[i]-A[i-1] == dif) else we add (c*(c+1))/2 to our answer and make c = 0 and (dif = A[i]-A[i-1])
*/
