/*
Platform :- Leetcode
Contest :- Leetcode Bi Weekly contest 86

Approach is to use a left/start pointer and we will consider subarray from [start,current_index 'i'] , 

i. We will use prefix sum to find sum of runningcost in O(1)

ii. We will use set and map , set to get the max element in range in O(logn)

iii. We will use map to store the frequency of each element in subarray choosen,
    while moving the left/start pointer we will decrease the freqeuncy count of left/start element and remove from set
    if frequency becomes zero

So Time complexity :- O(n*log(n))
 

*/
