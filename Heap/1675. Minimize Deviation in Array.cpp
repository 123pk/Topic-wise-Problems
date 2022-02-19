/*
Platform :- Leetcode
Approach :- If you will carefully analyse the problem you will find that you can perform the (ii) operation only once as after that all the values become even and we can only perform 
            first operation , so it is optimal to conver all the values even by multiplying by 2 and we will also maintain min_value of array in variable, we will store all the vlaue
            in max heap and we will reduce the max value of array (val = val/2) till it is divisible by 2 and keep on finding the min value of differene and also update the min_value
            in process.
*/
