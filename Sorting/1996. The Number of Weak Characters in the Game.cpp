/*
Platform :- Leetcode
Approach :- First we sort the array by first value , then for each value we try to find the max value (second one)that we can get from all the values greatear than it .
            We first find max of all second value for particular x,like for (5,2) , (5,4) , (5,8) , (5,9) ... we want to store (5,9) for value of 5 , 9 is the max value we 
            can have . Similary for all other value .
            Now we want to find max of all second values for all first values greater than current first value 
            (5,9) (6,7)(9,8)  --- we will store (5,8) (6,8) (9,0) as that is the maximum second value that we can have from all value greater than first value.
*/
