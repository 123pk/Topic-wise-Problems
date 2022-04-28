/*
Platform :- Leetcode
Approach :- We will maintain a 2d array which will store the min value that we can have if we choose that cell to be in our final path , that value will be the min of 
            max value of all choosen paths till there . If current value of that cell is less than the value we will moving from neighbouring cell then we will not consider
            that path as we have better option.
*/
