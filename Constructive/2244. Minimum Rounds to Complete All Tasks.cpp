/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 289 
Approach :- Since we can choose '2' or '3' values of same type at a time so if we have an element with just '1' frequency then it is not possible
            else for all other cases no of operation required per element is value = (x/3) , if(x%3)value++ , here 'x' = frequecy of element
*/
