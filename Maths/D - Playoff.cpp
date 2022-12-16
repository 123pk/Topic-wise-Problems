/*
Platform :- Codeforces
Contest :- Codeforces Educational Round 140
Approach :- If you will observer carefully you will find that , for following example "1010"
           -- If we want 'x' to win the competiton then he need to beat '2' opponent with 'SMALLER' VALUE and '2' with 'BIGGER' VALUE ,
           -- But for the second 'SMALLER' and second 'LARGER' value also need to beat their respective opponents to reach till their.
           So the following solution can be deduced that we traverse throgh the array and maintain count for '1' and '0'
           -- If ith value is '1' , it means we need to have additional (2^(one-1)) values SMALLER , where '1' is no of ones till there 
           --- if ith value is '0', it means we need to have additional (2^(one-1)) values GREATER , where '1' is no of ones till there 
           At the end we print all the values from (SMALLER+ 1) to (2^n- GREATER).
           
Time Complexity :- O(n)
*/
