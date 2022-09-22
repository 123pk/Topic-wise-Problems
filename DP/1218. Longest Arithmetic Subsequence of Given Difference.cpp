/*
Platform :- Leetcode
Approach :- Sice we have to deal with negative values too , We will add some big amount to make it positive , So I have added 5*10^4 hence all values will become +ve 
            now we will use dp , where ' dp[i] = max(1,max(dp[i] , dp[i-dif] + 1))'  we will look for only values if (x-dif) is >=0 .
Time Complexity :- O(n)
Space Complexity :- O(n)
*/
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int dif) {
        vector<int>dp(100001);
                
        //now we don't need to deal with negative value
        for(auto&x:arr)x+=50000;
        
        int ans = 1;
        
        for(auto&x:arr){
            if((x-dif) <0)continue;
            // max no of len of AP including 'x' is max of previous len including 'x' and len to reach 'x'-dif + 1  
            dp[x] = max(1,max(dp[x],dp[x-dif]+1));
            ans = max(ans,dp[x]);
        }
        return ans;
        
    }
};
