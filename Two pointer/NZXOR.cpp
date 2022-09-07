
/*
Platform :- Codechef
Contest :- Codechef Starters 55
Approach :- We traverse through the array and computer the xor of all elements till ith index , we also maintain a set which stores the 'xor_values' already occured
            whenever we get xor_value  = 0 or a xor_values which is repating ( this means we have a subarray which has xor  = 0) so we increment out count as we need to
            change this value , and make xor_value = 0 and do the traversal again , we also make the set empty .
*/
