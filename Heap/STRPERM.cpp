/*
Platform :- Codechef
Contest :- Codechef Starters 48
Approach :- We will maintain list for each value from '1' to 'n' and store the values at the index given in 'm' instructions, we will contsturct our array backwards from 
            n to 1, we will check if there is any list for 'i' value or not if there is a value we will store it in max_heap or we can use set of negative values as this will
            also give max values in log(n) time . Now we will initialise 'i' with the max value we have .
            --> Solution is not possible for case where our heap or set becomes empty and we have some index to fill.
Time Complexity :- O(n * log(n)) 
*/
