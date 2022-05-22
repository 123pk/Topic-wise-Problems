/*
Platform :- Coding Competitions with Google
Approach :- We will need to simplify the equation ,
            Let sum of subset elements of Alan be 'S1' and that of Barbara is 'S2',
            then according to problem 
                (S1/S2) = (X/Y)    -----(i)
                and let the tot_sum = S1 + S2 ----  (ii)
                
                Simplifying equation (i) 
                S1*y = S2*x
                putting the value of S1 from equation (ii) and simplifying we will get 
                S2 = (tot_sum * y ) / (x+y)
                if numerator is not divisible by denominator then the solution is not possible 
                
                else we will get S1 from that , Now we will start from the max elements and if the sum value is > than this we  will add in our array and decrement the value
                until the sum becomes 0
                
Time complexity :- O(n)
*/
