/*
Platform :- Leetcode
Contest :- Bi weekly contest 72
Approach :- For each of values in array nums1 , we will create array of index in array 2 , now we want to know for (i=1 , to n-2 ), no of values that are smaller than current value
            in that array and no of values greater than that value to the right in that array , the product of those is added to the answer .
            For finding no of values greater than curret value to the right we will use self balancing BST and using that info we can also find no of values smaller than it to let
            check more about this :- https://www.geeksforgeeks.org/count-smaller-elements-on-right-side/
*/
