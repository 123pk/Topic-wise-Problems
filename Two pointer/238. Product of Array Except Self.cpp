/*
Platform :- Leetcode
Approach :- We need to find prefix and suffix that will contain product of values .
            Now for index 'i' our required value is pref[i-1]*suff[i+1] for valid idxes.
Time Complexity:- O(n*n)
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        
        /*
        Mulitplication without using division operation
        perfix and suffix product array
        */
        int n = nums.size();
        vector<long long>pre(n),suf(n);
        
        long long start = 1;
        for(int i=0;i<n;++i){
            
            long long val = nums[i];
            start*=val;
            pre[i] = start;
        }
        
        vector<int>ans(n);
        start = 1;
        for(int i=n-1;i>=0;--i){
            long long val = nums[i];
            start*=val;
            suf[i] = start;
        }
        
        for(int i=0;i<n;++i){
            if(i == 0){
                if(i == n-1)ans[i] = 0;
                else{
                    ans[i] = suf[i+1];
                }
            }
            else if(i == n-1){
                ans[i] = pre[i-1];
            }
            else{
                long long val = pre[i-1]*suf[i+1];
                ans[i] = val;
            }
        }
        
        return ans;
    }
};
