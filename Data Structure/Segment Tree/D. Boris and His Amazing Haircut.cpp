/*
Platform :- Codeforces
Contest :- Hello 2023
Approach :- The approach is to store the indexes of each value of B in a vector and map with the value,now we start will bigger size razor,
            we can always cut a hair fro (l,r) to 'x' if the max value in range (l,r) inclusive is <= x
            now we start from last index value and then move to smaller and all the way to the first index ,
            we delete the value from index array and change the size in A to x if the max value in range is <='x'
            We use Segment tree to find the max in range and update the index remaining for each value.
            At the end we check if both array are equivalent.
            
            -- We cannot have solution in case where A[i]<B[i],we can't grow hair natural thing :)

Time Complexity :- O(n log n)
*/
