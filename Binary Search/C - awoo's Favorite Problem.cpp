/*
Platform :- Codeforces
Contest :- Codeforces Educational Round 130
Approach :- If you will carefully analyse the problems you will find that 'ab' --> 'ba'  and 'bc' to 'cb'
            this operations is usful for shifting operation . Like we can shift 'b' to 'x' no of positions if we have 'x' consecutive 'a' before 'b'
            --> similarly we can shift 'c' if we have 'x' no of 'b'
            
            Now we will traverse through the string and will find that if the charactes are not equal in both string at 'ith' position then 
            for s[i] = 'a' we can change to 'b' only and that also when we have 'b' just after occurence of 'a'
            similarly for s[i]  = 'b' we can change to 'c' only depending upon its occurence.
            
            For all other cases we cannot perform any operation .
            After performing all the operations we check if we have both string equal or not
*/
