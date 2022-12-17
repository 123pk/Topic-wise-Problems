/*
Platform :- Codeforces
Contest :- Codeforces Polynomial Round 2022 (Div. 1 + Div. 2)
Approach :- The main idea is to have a block of size 'k' and we can have 'k' disitinct values only if all values are atleast (max_value-1).
            If (k>m) we cannot have our solution
            Else we will sort the values and choose the smallest (m-(k+1)) values to make the set of values from ((m-k) to m) equal to (max_value-1)
Time Complexity :- O(n log n)
*/
