/*
Platform :- Leetcode
Approach :- So the intution is that you need to understand if there are 'x' number of consecutive same colors then we need to remove 'x-1' of them for 'x'>1 ,
            so we will choose the one with max_time out of those 'x' to be left out and we will remvove all the remainings ones.
            So approach is to find consecutive equal colors range and remove the max from sum of range .
            We can use prefix sum or we can store the last index with number of consecutive terms and store in array , later we traverse throught the range and find 
            the sum of time in range and remove the max time from the sum of range and that remaining time is added to our answer.
Time Complextiy :- O(n)
*/
