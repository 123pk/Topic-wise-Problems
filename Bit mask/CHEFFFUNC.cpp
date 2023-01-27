/*
Platform :- Codechef
Contest  :- Codechef Starters 75
Approach :- You need to observe the values  of f(x) and g(x) for [1<= x <=32 ] , you will find that the max value is for 'x' which is 'power_of_2' .
            After that we the value decreases .
            till it reach the next power_of_2.
            So approach is to find the biggest power of '2' in range 'a' to 'b' if there is no such value then we find the score for 
            'a' as we have oberve the value will decrease from 'a'-->b as we move.
            So the biggest will be at 'a' if no power of 2 in range.
            Else the power of 2 will give use the max value.
Time Complexity :- O(log(b))
*/
