/*
Platform :- Leetcode
Apporach :- We will maintain one variable that will help us in telling if we are at odd level or even , we know in BFS we store the elements from left to right way ,
            so we will maintain a vector to store elements at each level , if the variable which give information about level of tree is "odd" then we reverse the array
            and add in our answer elese we add it unchanged.
*/
