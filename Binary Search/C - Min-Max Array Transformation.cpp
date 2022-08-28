/*
Platform :- Codeforces 
Contest :- Codeforces Educational Round 134 
Approach :- Okay so we have to think greedily in which case are we going to have smallest increment operation ,
            i. For smallest increment values we need to convert A[i] to nearest available B[j] >= A[i] , so we can use binary search on sorted B or lower_bound on set with
               all elements of B.
            ii. For greatest increment value we will find the first value which is B[j] >= A[i] , then from index 'j' to 'i' I can convert each element of A to B[i] , we sort the
                elements of array A in increasing order and start from end (n-1) to (0), So basically for each index we want the max value we can convert our value to .
                Now greaterst increment is (max_value[i] - A[i]),
               
*/
