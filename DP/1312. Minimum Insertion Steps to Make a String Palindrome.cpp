/*
Platform :- Leetcode
Approach :- We will maintain two pointers one will point to the end and one to the front , if the chanracteres are equal then we (i++) and (j--) ,
            if they are not equal then we have two option 
             --- either to add one character similar to (ith) character in end 
             --- or add character similar to (jth) character in front 
             we will check for both operation and consider the one with minimum cost ,we will use memoisation to make our code more efficient.
*/
