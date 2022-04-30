/*
Platform :- Leetcode
Contest :- Leetcode Bi Weekly contest 77
Approach :- We will find the total sum of array ,now we will traverse through the array and find the left average and right average , so the index with minimum value is 
            our answer.
*/
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int ans = 0;
        
        long long mx = 1e18;
        long long tot = 0;
        for(auto&x:nums)tot+=x;
        
        long long pref = 0;
        int n = nums.size();
        for(int i=0;i<n-1;++i){
            pref+=nums[i];
            long long rem = tot-pref;
            long long z = i+1;
            long long last = n - (i+1);
            long long left_av = pref/(z);
            long long right_av = (rem/last);
            
            long long dif = abs(left_av - right_av);
            if(dif<mx){
                mx = dif;
                ans = i;
            }
        }
        
        long long rem = tot;
        long long z = n;
        rem/=n;
        if(rem<mx){
            mx = rem;
            ans = n-1;
        }
        
        return ans;
    }
};
