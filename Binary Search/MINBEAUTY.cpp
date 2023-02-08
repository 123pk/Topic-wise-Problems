/*
Platform :- Codechef
Contest :- Codechef Cook off February 2023
Approach :- You need to reduce the expression first , 3*(mean - median) --> for (a,b,c) in sorted order
            3 * ((a+b+c)/3 - median) => 3*( (a+b+c) - 3*median)/3 ==> ((a+b+c) - 3*b)   --  median is middle element and 'b' is middle of (a,b,c) as they are in sorted order
            --> Now we need to find best 'c' -> (c = 3*b - (b+a)) ==>  [ c = 2*b - a ]
            So we will find the closest value to this 'c' for all the pairs (a,b) .
            1. Sort the array in increasing order 
            2. Find all the pairs (a,b) bruteforce 
            3. for each pairs binary search on remaining values and find the best values closest to 'c' 
            4. Find the score and store the minimum of all 
Time Complexity :- O(n^2 log n) --> n^2 --  for all pairs (a,b) , log n  for binary search to find 'c'
*/
