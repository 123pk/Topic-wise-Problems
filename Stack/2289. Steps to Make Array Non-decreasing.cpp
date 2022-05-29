/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 295
Approach :- The approach is to find size of largest substring to right of current index which  have smaller value that current index, We will use stack to find this 
            then if we found a value 'x' which is greater than the top value of stack then we will pop it out until we found a value which is >= 'x' , while popping we 
            will take care of no of value which will need to be deleted .
            
            Take an example of 
            14 2 14 13 2 5 6
            here we will need '3' moves . 
            we will reverse the array and perform the operations
            
            so we are storing the following values in stack 
            1. {6,0} ---> element is 6 and no of values smaller than this is 0
            2. {5,0} ---> element is 5 and no of value smaller thatn this is 0
            3. {2,0} ---> same as above
            4. {13,3} --> no of vallues smaller than this to right
            5. {14,3} --> here we didin't get '4' because in one move 2 will be gone due to '13'
            6. {2,0}
            7 . {14,1} 
            so max no of time is '3'
 */
