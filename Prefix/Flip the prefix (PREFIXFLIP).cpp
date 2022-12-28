/*
Platform :- Codechef
Contest :- Codechef Starters 71
Approach :- I reduced the array or compressed to alteranting string of 01010.. or 101010.. form , where I stored two thigns (current_character,count_of_consecutive_this_char)
           Now I tried sliding window and two pointer where I find the window with sum of charcters >= k and cost to be minimum.
           
Time Complexity ;- O(n)
*/
