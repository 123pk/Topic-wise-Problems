/*
Platform :- Leetcode
Appraoch :- We sort the array and it is optimal to make all elements equal to mid value of array , so we choose 3 value to left of mid and 5 to the right and find the lowest
            cost for converting out of cost value of each elements.
*/
class Solution {
public:

    int find(vector<int>&A,int val){
        long long cost = 0;
        
        for(auto&x:A){
            cost+=abs(val-x);
        }
        long long x = INT_MAX;
        cost = min(cost,x);
        return cost;
    }
    
    int minMoves2(vector<int>& nums) {
        int ans =  INT_MAX;
        
        int sum = 0;
         sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = max(0,n/2-3);i<min(n,(n/2)+3);++i){
            ans = min(ans,find(nums,nums[i]));
        }
        
        return ans;
    }
};
