/*
Platform :- Leetcode
Time Complexity :- O(n log n)
Approach :- We maintain count array which stores the count of matches 'x'th player lost, we maintain one set which stores the players which played .
            Now we traverse through the set and get those values in first array which have ( count[x] == 0),
            if we have count[x] == 1,we push in second array.

*/
