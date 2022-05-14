/*
Platform :- Codeforces
Contest :- Codeforces Round 791
Approach :- We will use greedy algorithm here ,
         --> So we use a flag to check if we have use any operation of type '2' till now or not , we will also maintain a set which will store indexes which are changed
         --> if we have not used then it is easy we just update the  ' total_sum  += (value - A[idx] ) ' 
         --> if we have used type '2' then we will erase all the values in set storing changed index and update 'total_sum = n*value'.
         --> we will maintain a variable that will store the last value of type '2' operation . 
         --> while performing type '1' operation when we have performed type '2' in past , we check if current index is changed or not ,
             if not we change the value to 'last_value_type2' and update the total_sum ,  else we compare with updated sum 
*/
