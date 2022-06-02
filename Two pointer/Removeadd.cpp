/*
Platform :- Codechef
Contest :- Codechef starters 41
Approach :- We will find the longest subarray with distinct elements , now the count of elemnet to left be 'x' and elements to the right 'y' , so we will remove min(x,y)
            elements and the we will add that element to the side with max(x,y) and then we will remove the (x+y)values and append distinct values,
            Take care of longest prefix and suffix and find the min cost out of them also . The min of all three is our answer.
*/
