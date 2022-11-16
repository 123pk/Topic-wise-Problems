/*
Platform :- Leetcode
Approach :- So we have to call another function "guess"  which takes on argument an integer value 'x' and then return three values
            ---> -1 if 'x' > 'actual_number'
            ---> +1 if 'x' < 'actual_number'
            ---> 0 if 'x' == 'actual_nubmer'
            
            So this is good hint for using the binary search , so we will use binary search as the 'actual_number' is between '1' and 'n' inclusive,
Time Complexity :- O(log n)
*/
  
class Solution {
public:
    int guessNumber(int n) {
         int start = 1,end = n,mid = (start+(end-start)/2);
         while(start<end){
             int val = guess(mid);
             if(val == -1){
                 end = mid-1;
                 mid = (start+(end-start)/2);
             }
             else if(val == 1){
                 start = mid+1;
                 mid = (start+(end-start)/2);
             }
             else break;
         }
         return mid;
    }
};
