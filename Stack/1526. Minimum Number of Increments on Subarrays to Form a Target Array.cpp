/*
Platform :- Leetcode
Approach :- We will use stack and if (A[i]<A[i-1]), then we will remove all the values from stack until we get the top element to be smaller than A[i] ,
            else we add in stack if (A[i]>A[i-1]) , if elements are equal we ignore them.
            Now while removing elemet from the stack we will add difference between top and second top element . Because that is the time required by us to change
            top element to second top.
            At the end we will have a non empty stack and we will add the top element to answer.
*/
