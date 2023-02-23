/*
Platform :- Leetcode
Approach :- You need to analyse the problem and you will find for 'x' capital we want to find the (maximum_profit_value for <= capital_'x' ) 
             we can use priority queue for that which will give us max value when required in (log n) ,
             Now we will first sort the array based on ascending order of capital ,
             and will travearse through the array and if our curent capital 'x' >= capital[i] , then we add the 'profit[i]' to our 'priority_queue'
             else we will increase out 'capital' by taking 'top_value' from our 'priority_queue' until ('x' >= capital[i]) or (k>0) or (priority_queue)
             is not empty .
             
             -- If we traverse throgh the whole array and still we have some 'k'left , we keep taking out the top value and adding to our capital the profit value
           
Time Complexity :- O(n log n)
             
*/
