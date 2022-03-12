/*
Platform :- Atcoder
Contest :- Atcoder Beginner Contest 243
Approach :- If you will try to use bruteforce operations then you will face long long range over flow , So you should compress as possible , 'U' is very helpful it undo any move 
           of 'L' or 'R' so we will maitain a stack and push 'L' or 'R' in it  , if we have a empty stack and we get 'U' then we decrease the value/index of node by half, else we
           pop top element of stack . Now we will get the string from the stack and perform the operations as it will not overflow now .
*/
