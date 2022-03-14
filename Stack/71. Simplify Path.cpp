/*
Platform :- Leetcode
Approach :- We will use the stack of string to push the folder names , if we enounter '..' after a single or series of slash '/' then we pop the top element of stack at the end
            we take all the string from the stack and add it to our answer where each directory name is separated by '/' and the canonial path start with '/'
*/
