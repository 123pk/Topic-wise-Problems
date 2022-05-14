/*
Platform :- Codeforces
Contest :- Codeforces Round 791 Div 2
Approach :- If we have any odd value or even value less than 4 then we cannot have any valid answer so it is "-1" ,
            else for minimum no of busses we will use '6' wheel ones , and for maximum no of buses we will use one with '4' wheels 
            ---> Take care of edge cases like  n = 14 , 
             if we will use '6' wheel buses then we will get only '2' but we can remove one '6' wheel and get '2' 4 wheel which will 
             give us n = 14 and minimum no of buses will be '3'.
*/
