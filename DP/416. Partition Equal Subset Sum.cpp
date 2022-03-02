/*
Platform :- Leetcode
Approach :- Since we need to partition our array into equal sum them the total_sum of array need to be even else we can't partition them into two ,
            now the problem is reduced to checking if there is subset of sum  = (total_sum/2), we will use knapsack dp to find this .
*/
class Solution {
public:
    int dp[200][20001];
    bool find(int idx,int rem_sum,vector<int>&nums){
        if(rem_sum==0)return 1;
        
        if(idx<0)return 0;
        
        if(dp[idx][rem_sum]!=-1)return dp[idx][rem_sum];
        
        //so we have two options either to choose 
        //current value in subset or not
        //if we dont choose it
        bool val = find(idx-1,rem_sum,nums) ;
        if(rem_sum-nums[idx]>=0)val|= find(idx-1,rem_sum-nums[idx],nums);
         
        
        return dp[idx][rem_sum] = val;
    }
    
    bool canPartition(vector<int>& nums) {
        int tot = 0;
        for(auto&x:nums)tot+=x;
        
        if(tot%2)return 0;
        int n = nums.size();
        tot>>=1;
        
        memset(dp,-1,sizeof(dp));
        
        int ans = find(n-1,tot,nums);
        
        return ans;
    }
};
