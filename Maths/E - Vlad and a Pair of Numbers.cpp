/*
Platform :- Codeforces 
Contest :- Codeforces Round 847 Div 3
Approach :- If you will simplify the problem, 'x' = the xor of (a&b)
            if we can get 'x' from offset bits , all bits that are offset have occurence '0' or '2' times ( one in each 'a' and 'b') 
            so we create array of those values and an array of set bits values too .
            For each offset bit we push them two times as both 'a' and b can have that bit set .Now the main motive is to get ( the set bits value) from
            off set bit array.
            We sort the array and start from the bigger values .If we are able to get the set bit array then we can have pair (A,B) else -1.
            We maintain frequency of used value,
            now if frequency is '2' we add that value to both 'a' and b' else we can add to either.
Time Complexity :- O(log^2 n)
*/
