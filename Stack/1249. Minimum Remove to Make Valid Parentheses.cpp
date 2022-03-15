/*
Platform :- Leetcode
Approach :- We take care of '(' and ')' we want to use balanced parenthesis , and we use a count function to add '+1' when we have '(' and -1' when we have '(' ,we will ignore the 
            operation which make the count to be -ve , similarly if after traversing through the string the count is > 0 then we will remove/ignore last of 'count' of '(' characters
            and copy the remaining characters as it is .

*/
