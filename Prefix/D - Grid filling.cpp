/*
Platform :- Atcoder
Contest :- Atcoder Beginner Contest 278
Approach :- We find total number of unique values in whole matrix let it be 'x'.
            Since the values can be upto 300 , I used two prefix array which store the minimum and maximum coloumn and row for each value.
            Now for each of the subarray we count how many values are there which are totally inside this subarray let that be 'c'
            then for each subarray we prinnt (x-c)
 Time Complexity :- O(H*w*N)
*/
