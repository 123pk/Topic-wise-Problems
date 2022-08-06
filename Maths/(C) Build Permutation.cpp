/*
Platform :- Codeforces
Contest :- Codeforces Round 811 Div 2
Approach :- First create an array of size n with all values 0, Start from the very end (n-1) and run till 0 now we check what is the nearest squre to this number to 
            its right (>=(n-i)) , let that value be 'y' which is definitely smaller than (n-i) , now from that index to (n-i) store the diff (x-j) where 'x'  is the square 
            and ( y <= 'j' <= (n-i)) .
            
            Similarly we find the new square value when (i<y) and update the 'y' .
Time Complexity :- O(n)
*/
