/*
Platform :- Codechef
Contest :- Codechef Lunchtime February 2022
Approach :- If you will carefully analyse the problem , you will find that value of answer one of {0,1,2} for possible cases else -1.
           ---> if array is sorted then answer is '0'
           --> when we have only one type of character in string either 'N' or 'S' then we have no solution if array is not sorted so '-1'
           --> we need atmax '2' moves to sort the array
               we find the first and last index of unsorted elment , if they are between a subarray with different polarities in end then aswer is '1'
               else '2'
*/
