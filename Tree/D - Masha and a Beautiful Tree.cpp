/*
Platform :- Codeforces
Contest :- Codeforces Round 826 Div 3
Appraoch :- We will make complete tree from the give data, where parents store  ( min_value_in_subtree , max_value_in_subtree , no_of_nodes_in_subtree },
            --- when is the given tree cannot be sorted , it is a permutaion so if there is any missing  value in subtree then it cannot be sorted
            --- missing value is when ( max - min)+1 > no_of_nodes in subtree.
            --- We keep on check this also ,if the min is from right subtree of current node then we need to flip it and it will cost us '1' point
Time Comlexity :- O(n*log(n))
*/
