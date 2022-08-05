/*
Platform :- Codeforces
Contest :- Educational Round 133 
Approach :- We first convert n to abs(n) as its easy to deal with +ve value , now it is much better to do jump of '3' , so we will do (n/3) jumps of '3' steps , now
            if there is some remainder we need +1 additional jump .
            Take care of case when n == 1, here we need 2 jumps.
*/
