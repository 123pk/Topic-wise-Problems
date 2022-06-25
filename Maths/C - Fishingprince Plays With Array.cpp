/*
Platform :- Codeforces
Contest :- Codeforces Global Round 21
Approach:- We will first perform operation '1' on array A till the time it is possible , we will maintain two things {value,count} , now we will traverse through array 
           B and will check if we can get the B[i] from P[j] or not . We can only get if B[i]%P[j] == 0 and the required value is power of m , req = B[i]/P[j] , req  = m^b
           else we cannot get that values
*/
