/*
Platform :- Geeksforgeeks
Approach :- We maintain two pointer pointing to stat and end of required range , we traverse through the array and update tot = tot + arr[i]
            we move our start pointer till tot>s , at the end we check if we have required sum or not , if yes then we have range from [start,end]
            
Time Complexity :- O(n)
*/
