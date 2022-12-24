/*
Platform :- Atcoder 
Contest :- Atcoder Beginner Contest 283
Approach:- We maintain one frequency array of size 26 where 0-->a ,1 -->b ... 25-->z ,
           we will traverse the array and we will push'(' and other alphabets in stack and also maintain frequency count array 
           if frequency count is >1 at any point for any character it is not allowd,
           else if we found ')' we pop out every thing until we find '(' if there is no '(' then also it is not possible to make it emnpty
           else we can always make the string empty
Time Complexity :- O(n)
*/
