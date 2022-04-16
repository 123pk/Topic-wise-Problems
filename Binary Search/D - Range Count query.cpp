/*
Platform :- Atcoder
Contest :- Atcoder Beginner Contest 248
Approach :- For each of the values we will store the occurence in set , now we will also maintain an array 'count' which will store the count of 'ith' element at till that
            index (including it) ,  now for each query we will find the first index of occurence in range using 'lower_bound' on set which is same as binary search , 
            and simlary we will do 'lower_bound' of 'r' of range , the no of values are (count[end] - count[start] + 1)
*/
