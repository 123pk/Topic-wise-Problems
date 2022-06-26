/*
Platform :- Codeforces
Contest :- Codeforces Round 802 Div 2
Approach :- Main motive is to make all elements till n-1 equal and last element may or maynot be equal , we can always do operatiions accordinbly , if last value>cur_value
            then we decrease the last value with cost of (last_value - cur_value) , else we change cur_value to last_value and all the values to right are also change 
            (cur_value - last_value),we maintain a varible which store how much we need to change current value from previous operations 
*/
