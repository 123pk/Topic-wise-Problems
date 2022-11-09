/*
Platform :- Leetcode
Approach :- We will use a stack which will store "value" and "count" , where count is number of values which are consecuitevely before "value" and are smaller or equal
            to "value" , whenever we get value from stack and check if that value is smaller or equal to current value then we remove it and add the count to our answer
            at the end we push current value and answer to stack.
Time Complexity :- O(n)
*/
