/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 314
Approach :- We will maintain one suffix array which will store the minimum character to right of current index till the end , basically for index 'i' it store the 
            min character from  index [i,n] , 
            We will maintain a stack which store the available characters we can choose from.
            -- now we travers through the array from left to right and if (suff[i] == s[i]) , we will compare with the top elements of stack , we will take out the
            top element if that element is <= suff[i] , at the end we will add current element also as it is eqaual to suff[i],
            -- similarly for other values we will take top from stack if it is <= suff[i] and at the end we will push the current value in stack.
            If stack is not empty we make it empty and add the top values to end of our curren string .
            
Time Comlexity :- O(n)
*/
