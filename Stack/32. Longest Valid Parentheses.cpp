/*
Platform :- Leetcode
Approach :- We will use stack data structure, stack of pair<char,int> , when stack is empty we will puch 'current' character with its 'index' , if we get '(' we will 
            do only push operation with index , else if our stack is not empty and top element have charater '(' and current character is ')' then we will pop our that
            top element as it is balanced by current element , the size of valid parenthesis is from current index to top elements that we removed so the max of all this 
            differences is our answer.
Time complexity :- O(N) 
Space Complexity :- O(N)
*/
