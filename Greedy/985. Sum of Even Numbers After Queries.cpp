/*
Platform :- Leetcode
Approach :- We have four cases :- 
           1. nums[i] is odd
               i. val is odd
               ii. val is even
           2. nums[i] is even
               i. val is odd
               ii. val is even
           
Time Complexity :- O(n)
*/
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        
        int eve = 0;
        for(auto&x:nums){
            if(x%2 == 0)eve += x;
        }
        
        for(auto&x:queries){
            if(nums[x[1]]%2){
                if(x[0]%2){
                    eve += (nums[x[1]] + x[0]);
                    nums[x[1]]+=x[0];
                }
                else{
                    
                    nums[x[1]] += x[0];
                }
            }
            else{
                if(x[0]%2 == 0){
                    eve += x[0];
                    nums[x[1]] += x[0];
                }
                else{
                    eve -= nums[x[1]];
                    nums[x[1]] += x[0];
                }
            }
            ans.push_back(eve);
        }
        return ans;
    }
};
