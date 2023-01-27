/*
Platform :- Codechef
Contest  :- Codechef Starters 75
Approach :- You need to observe the values  of f(x) and g(x) for [1<= x <=32 ] , you will find that the max value is for 'x' which is 'power_of_2' .
            After that we the value decreases .
            till it reach the next power_of_2.
            So approach is to find the biggest power of '2' in range 'a' to 'b' if there is no such value then we find the score for 
            first 100 values from 'a' to min(b,a+100) 
            and the biggest will be our answr.
            Else the power of 2 will give use the max value.
Time Complexity :- O(log(b))
*/
