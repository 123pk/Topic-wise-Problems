/*
Platform :- Codeforces
Contest :- Codeforces Contest 847 Div 3
Approach :- We will store the frequency of count of each value and store all values in set too ,
            now we perform the following operation until the set becomes empty :- 
               - we traverse through the set starting with the first value and get traverse through consecutive values 
               - decrease their frequency , if frequency becomes 0 we store in some vector 
               - erase all the elements of vector from set
               - increse our count by 1
Time Complexity :- O(n log n)
*/
