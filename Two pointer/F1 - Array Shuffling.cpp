/*
Platform :- Codeforces
Contest :- Codeforces Global Round 20
Approach :- Sort values by frequency and make array of indexes, where we first take the most frequent value and all add all its indexes in inital array and similary for all
            other values. Similarly we will make array of values also , now we will shift the value array by maximum no frequency of element in array to left and initalise
            the indexes with new values after shifting.
            
            Approach is to get a array with least no indexes which have same values as inital array.
*/
