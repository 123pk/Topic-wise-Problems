/*
Platform :- Codechef
Contest :- Codechef Starters 62
Approach :- We first change out binary string into 10101... or 010101.. or basically compress out string , where bunch of same segment are compressed to 1 ,ex (001110 --> 010)
            No we want to make this string sort in ascending order which will be possible if we have '0's in front and '1's in last . So we will try each combination
            likke if we are at '1' we want all the values beyond this point to be '1' and all values to left of this to be '0' we will found the cost .
            The min of all is our answer.
Time Complexity :- O(n)
*/
