/*
Platform :- Leetcode
Approach :- We will use binary search here to get O(logn) solution ,  so to decide which direction to move we can get that by comparing with 
             neighbours, 
             1. check if current index is valid peak or not , if it is return it
             2. if current index is not a peak then check the neighbours to find where to move if(nums[mid] < nums[mid-1]) ---> move to left to get the maxima
                else move to right .
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //int idx = -1;
        int n = nums.size();
        if(n == 1)return 0;
        
        //now let us have a binary search solution in O(logn) complexity
        int start = 0,end = n-1,mid = (start+end)/2;
        
        //the logic is to move towards greatest element in inclined slope
        //check the neighbours they will give you idea in which direction to move
        while(start<=end){
            
            //now check the neighbours of mid
            //for movement
            if(mid == 0){
                //check for the right 
                if(nums[mid]>nums[mid+1])return mid;
                else{
                    start = mid+1;
                    mid = (start+end)/2;
                }
            }
            else if(mid == n-1){
                //check neighbour
                if(nums[mid]>nums[mid-1])return mid;
                else{
                    //move to left
                    end = mid-1;
                    mid = (start+end)/2;
                }
            }
            else{
                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])return mid;
                else{
                    if(nums[mid]>nums[mid-1]){
                        start = mid+1;
                        mid = (start+end)/2;
                    }
                    else{
                        end = mid-1;
                        mid = (start+end)/2;
                    }
                }
            }
        }
        return mid;
    }
};
