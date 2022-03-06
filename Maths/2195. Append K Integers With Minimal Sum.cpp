/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 283
Approach :- 1. Sort the array in non decreasing order ,
            2. The max no of unique values between two no is going to be (max - min)-1 ,
            3. The sum of unique values between two is (sum_of_unique_value_till_max - sum_of_unique_values_till_min )
            4. The forumulae for finding sum of 'n' consecutive numbers is (n*(n+1))/2
            5. We use the above formulae and find the max no of values that we can get and cost of adding them.
*/
