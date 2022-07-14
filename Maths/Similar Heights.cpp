/*
Platform :- Codechef
Contest :- Codechef Starters 47
Appraoch :- You need to carefully understand the lines in problem statement 
           --> You can sepearate out all the group of size  = 1 , let c = count of such values then 
           --> if c>1 then it will cost us (c*(c+1))/2 operations to make them into a single group and it will be the minimum cost too
           --> if c == 1 and the max_size of any gropu is  = 2 then we have to do '2' opeartion
           --> else we need '1' operation and this is our edge case
*/
