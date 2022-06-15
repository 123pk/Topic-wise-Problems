/*
Platform :- Codechef
Contest :- Codechef Starters 43
Approach :- We want to make the and of all values to '0' , so we start with max value and get back to 1, from n ---> 1 , we will mark the values already used using set
            now find the bitwise representation of current value 'i' and find the biggest value with which '&' is '0' and choose that value .
            if n is odd then except for '1' all other odd values donot have any solution.
*/
