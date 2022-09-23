/*
Platform :- Codechef
Contest :- Codechef Lunchtime September 2022
Approach :- So the score is the amx differnce between A[i-1] - A[i] for i = 1,n-1.
            We will use set and frequency array using hashmap to store the available differences and the max available non negative difference is our answer.
            We update the difference while adding one element , first we reduce count of previos difference at that position if any and then we do check if we need 
            to remove this diff or not . Then we add new one with increasing frequency.
Time Complexity :- O(n log n) -- > (log n) per query
*/
