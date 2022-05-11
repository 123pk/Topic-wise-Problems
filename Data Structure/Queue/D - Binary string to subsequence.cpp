/*
Platform :- Codeforces 
Contest :- Codeforces Round 661 Div 3
Approach :- We will use two deque to store the no of subsequence , first will store the no for "one"(1's) and no for "two"(2's) . now if we are at some ith index
            and if s[i] == '1' then if we have any available '0' the '1' in that subseqence and update the answer too . And if we don't have any '0' available then we
            will have to add new subsequence , basically update 'd' to d+1 , the 'd' show the no of subsequence and update it in deque .
*/
