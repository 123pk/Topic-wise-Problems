/*
Platform :- Leetcode
Approach :-  I will find the maximum frequency of character in string , that is the max possible frequency that can be assigned
             I will maintain a frequency array and sort the frequencis in decreasing order
             I will run a loop from i = mx to 1 and assign I would give the frequency of 'i' to the ith character if ( fre[i]> = i ) and I will have to delete
             (fre[i]-i) characters . Once I reach to 1 then I have to delete all the remaining characters and add frequency to answer.

*/
