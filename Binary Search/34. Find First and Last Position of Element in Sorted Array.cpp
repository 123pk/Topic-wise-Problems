/*
Platform :- Leetcode
Approach :- We will do binary search and find first occurence of "target" values in array , if we are not able to find we return {-1,-1} , else we update our array 
            with that index, now we recursively do binary search on left part of that index and similarly or right part and find the smallest index and largest index
            with target value
 Time Complexity :- O(log n)
*/
class Solution {
public:
    
    void find(int start,int end,vector<int>&nums,vector<int>&ans,int target){
        
         
        if(start>end)return;
         
        int mid = (start+end)/2;
       
        if(nums[mid] == target){
            ans[0] = min(ans[0],mid);
            ans[1] = max(ans[1],mid);
           //update the values if we found any match
        }
        find(start,mid-1,nums,ans,target);
        find(mid+1,end,nums,ans,target);
        
    }
    
    vector<int> searchRange(vector<int>& nums, int target){
        vector<int>ans;
        ans = {-1,-1};
        if(nums.size() == 0)return ans;
        int start = 0,end = (nums.size()-1) ,mid = (start+end)/2;
        int f = 0;
        while(start<=end){
            if(nums[mid] == target){
                //check if they are present or not
                f = 1;
                break;
            }
            else{
                if(nums[mid]>target){
                    end = mid-1;
                    mid =(start+end)/2;
                }
                else{
                    start = mid+1;
                    mid = (start+end)/2;
                }
            }
        }
        //if there is no target value return {-1,-1}
        if(f == 0)return ans;
        ans={mid,mid};
        
        //find the smallest index to left of mid index
        find(0,mid-1,nums,ans,target);
        int n = nums.size();
                
        //find the lagest index to right of this mid index
        find(mid+1,n-1,nums,ans,target);
        
        return ans;
    }
};
