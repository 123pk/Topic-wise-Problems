/*
Platform :- Atcoder
Contest :- Atcoder Beginner Contest 241
Approach :- We want to do query optimally , that is to store the elements in sorted order and do query on them efficiently , I am using set to store the elements and jump to 
            nearest value of 'x' using lowerbound and we will also maintain frequency array , I will now move to left and right accordinly of query and if the frequecy of elements
            are >= y then that is required value else print -1;
*/
