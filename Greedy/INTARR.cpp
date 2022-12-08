/*
Platform :- Codechef
Contest :- Codechef Starters 68B
Approach :- If you will observe you will find that if frequency of any element > (n+1)/2 ,then we cannot have the desired array.
            We first find the max frequency and check if answer exist or not.
            
            We first sort the array ,then we divide the array into 'small'(first (n+1)/2 value) and 'big' remainging values of second half,
            So there are two option 
            1. We have an array of A[0]>A[1]<A[2]>A[3].., even index values are greater than odd indexed values
            2. We have even indexed values smaller than odd index values , 
            We greedily check both the options and if any of one is satisified we print it else we print -1.

Time Complexity :- O(n log n) --sorting
*/
