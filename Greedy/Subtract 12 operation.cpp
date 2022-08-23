/*
Platform :- Codechef
Contest :- Codechef Lunctime August
Approach :- We will greediy traverse in reverse order (n-1 to 1) , and if ( A[ i ] <= 0) we skip this else we reduce (A[i]/2)*2 value from it and A[i]/2 from A[i-1]
            after modifying the array 
            we again traverse back and change 1,1 adjacent pairs to 0,-1
*/
