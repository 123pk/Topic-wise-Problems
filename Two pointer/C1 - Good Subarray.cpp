/*
Platform :- Codeforces
Contest :- Codeforces Round 825 Div 2
Approach :- So for a given subarray if current element can be added if A[i] >= c+1 , where 'c' is current size of subarray ,
            else we will move the start pointer of subarray until A[i] >= c , and each element contribute 'c' points to answer.
            
Time Complextiy :- O(n)
*/
