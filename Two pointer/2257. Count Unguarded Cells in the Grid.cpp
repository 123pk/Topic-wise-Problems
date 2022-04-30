/*
Platform :- Leetcode
Contest :- Leetcode Bi Weekly contest 77 
Approach :- We will perform four traversal operations and that will cover all the cells which can be gurarded and all the remainig cells cannot be guarded and apart from
            walls the count of remaining ones is our answer.
            
            Basic idea is to do traversal and if we find any guard node then we mark flag , if we found a cell that is not guarded and our flag is marked then it means 
            we can guard this cell , if we found wall then we unmark the flag until we found any other guard .
            
            Four traversals are ( Left --> Right ) ,(Right --> left) , ( Top --> Bottom) and (Bottom to Top) 
*/
